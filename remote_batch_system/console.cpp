#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> //wait(), waitpid()
#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "object.h"

const string instrDictionary = "test_case/";

namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
using string = std::string;

void htmlContent(map<int, struct serverInfo_s> &servers);
void parserQueryString(map<int, struct serverInfo_s> &servers, string queryString);
bool isEmptyServer(string serverIP, string serverPort);
void showServerInfo(map<int, struct serverInfo_s> &servers);
string getQueryFieldData(string field);
string getWordAfterSpecificPos(string str, int pos);
void splitToVectorNotHaveDelimeter(vector<string> &v, string lineString, string delim);
string htmlEscape(string content);
void strOutputToHtml(int elementID, string content, string color);

boost::asio::io_context global_io_content;

class Client: public std::enable_shared_from_this<Client>{
    int elementID;
    fstream pFile;
    std::string port;
    tcp::resolver resolver_;
    tcp::socket socket_;
    enum { max_length = 1024 };    
    char read_[max_length];
    char write_[max_length];    

public:
    Client(boost::asio::io_service& io_service, int id)
            : resolver_(io_service), socket_(io_service) {
        elementID = id;        
    }

    void start(std::string serverName, std::string serverPort, std::string fileName){        
        port = serverPort;
        pFile.open((instrDictionary + fileName).c_str(), ios::in);

        tcp::resolver::query query(serverName, serverPort);
        resolver_.async_resolve(query, boost::bind(&Client::onResolve, getPtr(), boost::asio::placeholders::error, boost::asio::placeholders::iterator));
    }

    std::shared_ptr<Client> getPtr(){
        return shared_from_this();
    }

private:
    void onResolve(const boost::system::error_code& err, tcp::resolver::iterator endpoint_iterator) {
        if (!err) {
        // Attempt a connection to the first endpoint in the list. Each endpoint
        // will be tried until we successfully establish a connection.
        tcp::endpoint endpoint = *endpoint_iterator;
        // std::cerr<< port << "line 51 " << endl;
        socket_.async_connect(endpoint,
            boost::bind(&Client::onConnect, getPtr(), boost::asio::placeholders::error, ++endpoint_iterator));
        // std::cerr<< port << "line 54 " << endl;
        }
        else {
            std::cout << "Error: " << err.message() << "\n";
        }
    }

    void onConnect(const boost::system::error_code& err, tcp::resolver::iterator endpoint_iterator){
        if (!err){
            // The connection was successful. Send the request.            
            // std::cerr<< port << "line 67 " << endl;
            readStage();            
            // std::cerr<< port << "line 70 " << endl;
        }
        else if (endpoint_iterator != tcp::resolver::iterator()){
            // The connection failed. Try the next endpoint in the list.
            socket_.close();
            tcp::endpoint endpoint = *endpoint_iterator;
            socket_.async_connect(endpoint,
            boost::bind(&Client::onConnect, getPtr(),
                    boost::asio::placeholders::error, ++endpoint_iterator));
        }
        else{
            std::cout << "Error: " << err.message() << "\n";
        }
    }

    void readStage(){
        auto self(shared_from_this());
        // std::cerr << port<< "start read\n" << std::endl;
        
        strcpy(read_, "");        
        memset(read_, 0, max_length);

        socket_.async_read_some(boost::asio::buffer(read_, max_length), 
        [this, self](boost::system::error_code ec, std::size_t length){
                if (!ec){ 
                    std::string lines = string(read_);
                    memset(read_, 0, max_length);

                    if(lines.find("% ") != std::string::npos){

                        // debug file ascii code
                        // std::cerr << "trace start:\n" ;
                        // for(int i = 0; i < instr.size(); i++){
                        //     std::cerr << (int)instr[i] << "   ";
                        // }                        
                        // std::cerr << "trace end:\n" ;

                        //std::cerr << "response:\n" << lines << std::endl << "data:" << read_ << std::endl << "response end\n";
                        strOutputToHtml(elementID, lines, string("orange"));                        
    
                        writeStage();
                        //readStage();
                    }else{
                        //std::cerr << "response2:\n" << lines << std::endl << "response end\n";
                        strOutputToHtml(elementID, lines, string("orange"));

                        readStage();
                    }
                }else{ //when socket close, it wiil return ec = 9.
                    std::cerr << "port:" << port << "read ec: " << ec.message() << std::endl;
                    socket_.close();
                }
            }
        );
    }

    void writeStage(){
        auto self(shared_from_this());
        
        std::string instr = "";                        
        std::getline(pFile, instr);
        
        strcpy(write_, "");        
        memset(write_, 0, max_length);
        strcpy(write_, (instr + string("\n")).c_str());           

        //std::cerr << "write: " << write_ << endl;
        boost::asio::async_write(socket_, boost::asio::buffer(write_, strlen(write_)),  boost::asio::transfer_all(), //it means that buffer has strlen(data_) space, then this function can continue run.
                [this, instr, self](boost::system::error_code ec, std::size_t /*length*/){
                    if(!ec){                              
                        memset(write_, 0, max_length);
                        strOutputToHtml(elementID, instr + string("\n"), string("brown"));                                              
                        if(instr.compare("exit") == 0){
                            //std::cerr << "endding\n";
                            socket_.close();
                        }else{                            
                            readStage();
                        }                                           
                    }else{
                        std::cerr << "write error: " << ec.message() << std::endl;
                    }
                }
        );
    }
};

int main(int argc, char* argv[]){
    map<int, struct serverInfo_s> servers;
    map<string, string> env_variables = {
                                    {"REQUEST_METHOD", ""}, {"REQUEST_URI", ""},
                                    {"QUERY_STRING", ""}, {"SERVER_PROTOCOL", ""},
                                    {"HTTP_HOST", ""}, {"SERVER_ADDR", ""},
                                    {"SERVER_PORT", ""}, {"REMOTE_ADDR", ""},{"REMOTE_PORT", ""}
                                };

    for(map<string, string>:: iterator it = env_variables.begin(); it != env_variables.end(); it++)
        it->second = getenv(it->first.c_str());
    

    parserQueryString(servers, env_variables["QUERY_STRING"]);
    //showServerInfo(servers);
    htmlContent(servers);
    

    for(map<int, struct serverInfo_s>:: iterator it = servers.begin(); it != servers.end(); it++){                        
        std::make_shared<Client>(global_io_content, it->first)->start(it->second.name, it->second.port, it->second.fileName);                
    }  


    global_io_content.run();

    return 0;
}

void strOutputToHtml(int elementID, string content, string targetColor){
    string color;

    if(targetColor.compare("orange") == 0){
        color = "cTypeA";
    }else if(targetColor.compare("brown") == 0){
        color = "cTypeB";
    }

    content = htmlEscape(content);
    string combStr = string("<script>document.getElementById(\'s") + std::to_string(elementID) 
                        + string("\').innerHTML += \'<") + color + string(">") + content + string("</")
                        + color + string(">\';</script>\r\n");

    std::cout << combStr;
    std::cout.flush(); 
}

string htmlEscape(string content){
    string escapeStr = "";
    for(int i = 0; i < content.size(); i++){
        if(content[i] == ' '){
            escapeStr += string("&nbsp;");
        }else if(content[i] == '<'){
            escapeStr += string("&lt;");
        }else if(content[i] == '>'){
            escapeStr += string("&gt;");
        }else if(content[i] == '\n'){
            escapeStr += string("&NewLine;");
        }else if(content[i] == '\''){
            escapeStr += string("&apos;");
        }else if(content[i] == '\"'){
            escapeStr += string("&quot;");
        }else if(content[i] == '&'){
            escapeStr += string("&amp;");
        }else if(content[i] == '-'){
            escapeStr += string("&ndash;");
        }else if(content[i] == '|'){
            escapeStr += string("&#124;");
        }else if(content[i] == '\\'){
            escapeStr += string("\\\\");
        }else if(content[i] == int(13)){

        }else{
            escapeStr += content[i];
        }        
    }

    return escapeStr;
}

void parserQueryString(map<int, serverInfo_s> &servers, string queryString){
    vector<string> elements;
    splitToVectorNotHaveDelimeter(elements, queryString, "&");
    
    int i = 0;
    while(i < elements.size()){
        string serverIP = getQueryFieldData(elements[i + 0]);
        string serverPort = getQueryFieldData(elements[i + 1]);
        string fileName = getQueryFieldData(elements[i + 2]);

        if(!isEmptyServer(serverIP, serverPort)){
            
            int serverNumber = stoi(elements[i + 0].substr(1, elements[i + 0].find("=") - 1));
            
            struct serverInfo_s server;
            server.name = serverIP;
            server.port = serverPort;
            server.fileName = fileName;

            servers.insert({serverNumber, server});            
        }
    
        i += 3;
    }
}

string getQueryFieldData(string field){
    int equalPos = field.find("=");
    if(equalPos == field.size() - 1)
        return string("");
    return field.substr(equalPos + 1);
}

void htmlContent(map<int, struct serverInfo_s> &servers){
    cout << "Content-type: text/html\r\n\r\n";
    cout << "<!DOCTYPE html>" <<"<html lang=\"en\">\n" << "<head>\n"
        << "<meta charset=\"UTF-8\" />\n" << "<title>NP Project 3 Sample Console</title>\n"
        << "<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css\" integrity=\"sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2\" crossorigin=\"anonymous\"/>\n"
        << "<link href=\"https://fonts.googleapis.com/css?family=Source+Code+Pro\" rel=\"stylesheet\"/>\n"
        << "<link rel=\"icon\" type=\"image/png\" href=\"https://cdn0.iconfinder.com/data/icons/small-n-flat/24/678068-terminal-512.png\"/>\n"
        << "<style>\n"
        << "* {\nfont-family: \'Source Code Pro\', monospace;\nfont-size: 1rem !important;\n}\n"
        << "body {\nbackground-color: #212529;\n}\npre {\ncolor: #cccccc;\n}\ncTypeA {\ncolor: #ed5e26;\n}\ncTypeB {\ncolor: #ffae14;\n}\n"
        << "</style>\n"
        << "</head>\n"
        << "<body>\n"
        << "<table class=\"table table-dark table-bordered\">\n"
        << "<thead>\n"
        << "<tr>\n";

    for(map<int, struct serverInfo_s>:: iterator it = servers.begin(); it != servers.end(); it++){
            std::cout << "<th scope=\"col\">" << it->second.name << ":" << it->second.port << "</th>\n";
    }

    cout << "</tr>\n"
        << "</thead>\n"
        << "<tbody>\n"
        << "<tr>\n";
    
    for(map<int, struct serverInfo_s>:: iterator it = servers.begin(); it != servers.end(); it++){
            std::cout << "<td><pre id=\"s" << it->first << "\" class=\"mb-0\"></pre></td>\n";
    }
    
    cout << "</tr>\n"
        << "</tbody>\n"
        << "</table>\n"
        << "</body>\n"
        << "</html>\n";
}

bool isEmptyServer(string serverIP, string serverPort){
    if(serverIP.compare("") == 0 || serverPort.compare("") == 0)
        return true;
    return false;
}

void showServerInfo(map<int, struct serverInfo_s> &servers){
    for(map<int, struct serverInfo_s>:: iterator it = servers.begin(); it != servers.end(); it++){
        std::cerr << "serverIP: " << it->second.name << " serverPort: " << it->second.port << " FileName: " << it->second.fileName << endl; 
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