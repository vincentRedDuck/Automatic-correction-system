#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include <iostream>
#include <vector>


#include "object.h"
#include "constValue.h"

using boost::asio::ip::tcp;

void parser(struct httpEnv_s &httpEnv, char *requestData);
void parserHost(struct httpEnv_s &httpEnv, string strLineData);
void parserMethod(struct httpEnv_s &httpEnv, string strLineData);
void splitToVectorNotHaveDelimeter(vector<string> &v, string lineString, string delim);
string getWordAfterSpecificPos(string str, int pos);
void showEnv(struct httpEnv_s &httpEnv);
void setEnviroment(const struct httpEnv_s &httpEnv);
void resetEnviroment();

boost::asio::io_context global_io_service;

class session : public std::enable_shared_from_this<session>{
    tcp::socket socket_;
    enum { max_length = 1024 };
    char data_[max_length];
    struct httpEnv_s httpEnv;

    private:
        void do_read(){
            auto self(shared_from_this());
            socket_.async_read_some(boost::asio::buffer(data_, max_length),
                [this, self](boost::system::error_code ec, std::size_t length){ // 要加 this，才可以避免該session 出去 do_read func. 後就被刪掉
                    if (!ec){         
                        //std::cerr << "startRead" << endl;                        
                        httpEnv.SERVER_ADDR = socket_.local_endpoint().address().to_string();
                        httpEnv.SERVER_PORT = std::to_string((socket_.local_endpoint().port()));
                        httpEnv.REMOTE_ADDR = socket_.remote_endpoint().address().to_string();
                        httpEnv.REMOTE_PORT = std::to_string((socket_.remote_endpoint().port()));                    
                        parser(httpEnv, data_);
                        //std::cerr << "endRead" << endl;
                        //showEnv(httpEnv);

                        

                        do_write(length);
                    }else{ //when socket close, it wiil return ec = 9.
                        std::cerr << "read ec: " << ec << endl;
                    }
                }
            );
        }
        
        void do_write(std::size_t length){
            auto self(shared_from_this());
            strcpy(data_, "");
            strcpy(data_, "HTTP/1.1 200 OK\r\n");        
            boost::asio::async_write(socket_, boost::asio::buffer(data_, strlen(data_)), //it means that buffer has strlen(data_) space, then this function can continue run.
                [this, self](boost::system::error_code ec, std::size_t /*length*/){
                    if (!ec){                        
                        //std::cerr << "startWrite" << endl; 
                        setEnviroment(httpEnv);

                        global_io_service.notify_fork(boost::asio::io_service::fork_prepare);
                        if (fork() != 0) { //parent
                            global_io_service.notify_fork(boost::asio::io_service::fork_parent);
                            socket_.close();
                        } else { //clild 
                            global_io_service.notify_fork(boost::asio::io_service::fork_child);
                            int sock = socket_.native_handle();
                            dup2(sock, STDERR_FILENO);  //!!!!when debugging, this need to comment
                            dup2(sock, STDIN_FILENO);
                            dup2(sock, STDOUT_FILENO);
                            socket_.close();
                            
                            if (execlp(httpEnv.TARGET_CGI.c_str(), httpEnv.TARGET_CGI.c_str(), NULL) < 0) {
                                std::cerr << "Content-type:text/html\r\n\r\n<h1>FAIL</h1>";
                            }
                            //std::cerr << "\nnot run cgi\n\n";
                        }

                        //std::cerr << "endWrite" << endl;                        
                    }else{
                        std::cerr << "write ec: " << ec << endl;
                    }
                }
            );            
        }
        
    public:
        session(tcp::socket socket)
            : socket_(std::move(socket)){
        
        }

        void start(){
            do_read();
        }


};

class server{
    tcp::acceptor acceptor_;
    private:
        void do_accept(){
            //process will create thread to monitor a new client. (this thread is running acceptor_.async_accept() function.)
            acceptor_.async_accept(  // async_accep註冊到 io_server 的 handler table
                    [this](boost::system::error_code ec, tcp::socket socket){ // 要加 this，才可以避免該session出去 do_accpet func. 後就被刪掉
                        if (!ec){
                            std::make_shared<session>(std::move(socket))->start();
                        }
                        do_accept();
                    }
                );
        }

    public:
        server(boost::asio::io_context& io_context, short port):
            acceptor_(io_context, tcp::endpoint(tcp::v4(), port)){
            do_accept();
        }




};

int main(int argc, char* argv[])
{
    int msockPort;
    try{
        switch(argc){
            case 2:
                msockPort = atoi(argv[1]);        
                break;
            default:
                std::cerr << "usage:TCPechod [port]" << std::endl;
                exit(0);
        }

        //boost::asio::io_context io_context;
        server s(global_io_service, msockPort);

        global_io_service.run();  //the parent process will hold on(not continue), 開始運行 io_service 中的 handler
    }catch (std::exception& e){
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}



void parserMethod(struct httpEnv_s &httpEnv, string strLineData){
    vector<string> strs;
    splitToVectorNotHaveDelimeter(strs, strLineData, " ");

    if(strs.size() < 3){
        cerr << "Error: parserMethod" << endl;
    }

    httpEnv.REQUEST_METHOD = strs[0];
    httpEnv.REQUEST_URI = strs[1];

    httpEnv.TARGET_CGI = "./";
    for(int i = 1; i < (int)strs[1].size(); i++){
        if(strs[1][i] == '?')
            break;
        else{
            httpEnv.TARGET_CGI += strs[1][i];
        }
    }

    httpEnv.SERVER_PROTOCOL = strs[2];

    if(strs[1].find("?") != string::npos){
        strs[1] = strs[1].substr(strs[1].find("?") + 1);
        httpEnv.QUERY_STRING = strs[1];
    }else{
        httpEnv.QUERY_STRING = "";
    } 
}

void parserHost(struct httpEnv_s &httpEnv, string strLineData){
    vector<string> strs;
    splitToVectorNotHaveDelimeter(strs, strLineData, " ");
    httpEnv.HTTP_HOST = strs[1];

    if(strs.size() < 2){
        cerr << "Error: parserMethod" << endl;
    }
}

void parser(struct httpEnv_s &httpEnv, char *requestData){
    //cerr << requestData << endl;
    stringstream ss;
    ss << string(requestData);

    string strLineData;
    while(getline(ss, strLineData)){
        string headerField = getWordAfterSpecificPos(strLineData, 0);
        
        if(headerField.compare("GET") == 0){
            parserMethod(httpEnv, strLineData);
        }else if(headerField.compare("Host:") == 0){
            parserHost(httpEnv, strLineData);
        }else if(headerField.compare("Upgrade-Insecure-Requests:") == 0){

        }else if(headerField.compare("Accept:") == 0){

        }else if(headerField.compare("User-Agent:") == 0){

        }else if(headerField.compare("Accept-Language:") == 0){

        }else if(headerField.compare("Accept-Encoding:") == 0){

        }else if(headerField.compare("Connection:") == 0){
        
        }else if(headerField.compare("DNT") == 0){

        }
    }
}

string getWordAfterSpecificPos(string str, int pos){
    str.erase(str.begin(), str.begin() + pos);    

    string returnStr = str;    
    int spacePos = str.find(" ");

    if(spacePos != int(string::npos))
        returnStr = str.substr(0, spacePos);

    return returnStr;
}

void splitToVectorNotHaveDelimeter(vector<string> &v, string lineString, string delim){
    char *token;
   
    char *cStr = new char[lineString.size() + 1];
    strcpy(cStr, lineString.c_str());
   
    token = strtok(cStr, delim.c_str());
    while(token != NULL){
        string str(token);
        v.push_back(str);
        token = strtok(NULL, delim.c_str());
    }
}

void showEnv(struct httpEnv_s &httpEnv){
    std::cerr << "print http enviroment\n";
    std::cerr << "TARGET_CGI: " << httpEnv.TARGET_CGI << std::endl;
    std::cerr << "REQUEST_METHOD: "  << httpEnv.REQUEST_METHOD << std::endl;
    std::cerr << "REQUEST_URI: "  << httpEnv.REQUEST_URI << std::endl;
    std::cerr << "QUERY_STRING: "  << httpEnv.QUERY_STRING << std::endl;
    std::cerr << "SERVER_PROTOCOL: "  << httpEnv.SERVER_PROTOCOL << std::endl;
    std::cerr << "HTTP_HOST: "  << httpEnv.HTTP_HOST << std::endl;
    std::cerr << "SERVER_ADDR: "  << httpEnv.SERVER_ADDR << std::endl;
    std::cerr << "SERVER_PORT: "  << httpEnv.SERVER_PORT << std::endl;
    std::cerr << "REMOTE_ADDR: "  << httpEnv.REMOTE_ADDR << std::endl;
    std::cerr << "REMOTE_PORT: "  << httpEnv.REMOTE_PORT << std::endl;
    std::cerr << "end http enviroment\n";
}

void setEnviroment(const struct httpEnv_s &httpEnv){
    setenv("REQUEST_METHOD", httpEnv.REQUEST_METHOD.c_str(), 1);
    setenv("REQUEST_URI", httpEnv.REQUEST_URI.c_str(), 1);
    setenv("QUERY_STRING", httpEnv.QUERY_STRING.c_str(), 1);
    setenv("SERVER_PROTOCOL", httpEnv.SERVER_PROTOCOL.c_str(), 1);
    setenv("HTTP_HOST", httpEnv.HTTP_HOST.c_str(), 1);
    setenv("SERVER_ADDR", httpEnv.SERVER_ADDR.c_str(), 1);
    setenv("SERVER_PORT", httpEnv.SERVER_PORT.c_str(), 1);
    setenv("REMOTE_ADDR", httpEnv.REMOTE_ADDR.c_str(), 1);
    setenv("REMOTE_PORT", httpEnv.REMOTE_PORT.c_str(), 1);    
}

void resetEnviroment(){
    setenv("REQUEST_METHOD", "", 1);
    setenv("REQUEST_URI", "", 1);
    setenv("QUERY_STRING", "", 1);
    setenv("SERVER_PROTOCOL", "", 1);
    setenv("HTTP_HOST", "", 1);
    setenv("SERVER_ADDR", "", 1);
    setenv("SERVER_PORT", "", 1);
    setenv("REMOTE_ADDR", "", 1);
    setenv("REMOTE_PORT", "", 1);  
}