#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <boost/bind.hpp>


#include "object.h"
#include "constValue.h"

using boost::asio::ip::tcp;


void parser(struct httpEnv_s &httpEnv, char *requestData);
void parserHost(struct httpEnv_s &httpEnv, string strLineData);
void parserMethod(struct httpEnv_s &httpEnv, string strLineData);
void splitToVectorNotHaveDelimeter(vector<string> &v, string lineString, string delim);
string getWordAfterSpecificPos(string str, int pos);
void showEnv(struct httpEnv_s &httpEnv);
std::string panelHtmlContent();
void parserQueryString(map<int, serverInfo_s> &servers, string queryString);
string getQueryFieldData(string field);
bool isEmptyServer(string serverIP, string serverPort);
void showServerInfo(map<int, struct serverInfo_s> &servers);
std::string consoleHtmlContent(map<int, struct serverInfo_s> &servers);
string htmlEscape(string content);
std::string strOutputToHtml(int elementID, string content, string targetColor);

const string instrDictionary = "test_case/";
boost::asio::io_context global_io_service;

class session : public std::enable_shared_from_this<session>{
    tcp::socket socket_;
    enum { max_length = 1024 };
    char cStrIn[max_length];
    string strOut;
    struct httpEnv_s httpEnv;
    map<int, struct serverInfo_s> servers;

    private:
        void do_read(){
            auto self(shared_from_this());
            socket_.async_read_some(boost::asio::buffer(cStrIn, max_length),
                [this, self](boost::system::error_code ec, std::size_t length){
                    if (!ec){         
                        //std::cerr << "startRead" << endl;                        
                        httpEnv.SERVER_ADDR = socket_.local_endpoint().address().to_string();
                        httpEnv.SERVER_PORT = std::to_string((socket_.local_endpoint().port()));
                        httpEnv.REMOTE_ADDR = socket_.remote_endpoint().address().to_string();
                        httpEnv.REMOTE_PORT = std::to_string((socket_.remote_endpoint().port()));                    
                        parser(httpEnv, cStrIn);
                        //std::cerr << "endRead" << endl;
                        //showEnv(httpEnv);

                        if(httpEnv.REQUEST_URI.find("console.cgi") != std::string::npos){                            
                            parserQueryString(servers, httpEnv.QUERY_STRING);
                            showServerInfo(servers);
                            writeConSoleHtml(servers);


                        }else if(httpEnv.REQUEST_URI.find("panel.cgi") != std::string::npos){
                            writePanelHtml();
                        }else{
                            std::cerr << "no known cgi name!!" << std::endl;
                        }

                    }else{ //when socket close, it wiil return ec = 9.
                        std::cerr << "read ec: " << ec << endl;
                    }
                }
            );
        }
        
        void writePanelHtml(){
            auto self(shared_from_this());
            std::string panelHtmlStrOut;
            panelHtmlStrOut = "HTTP/1.1 200 OK\r\n";
            
            panelHtmlStrOut += panelHtmlContent();

            boost::asio::async_write(socket_, boost::asio::buffer(panelHtmlStrOut.c_str(), strlen(panelHtmlStrOut.c_str())), //it means that buffer has strlen(data_) space, then this function can continue run.
                [this, self](boost::system::error_code ec, std::size_t /*length*/){
                    if (!ec){                        
                        socket_.close();
                    }else{
                        std::cerr << "write ec: " << ec << endl;
                    }
                }
            );            
        }
        
        void writeConSoleHtml(map<int, struct serverInfo_s> &servers){
            auto self(shared_from_this());
            std::string consoleHtmlStrOut = "";

            consoleHtmlStrOut += consoleHtmlContent(servers);
            boost::asio::async_write(socket_, boost::asio::buffer(consoleHtmlStrOut.c_str(), strlen(consoleHtmlStrOut.c_str())), //it means that buffer has strlen(data_) space, then this function can continue run.
                [this, self](boost::system::error_code ec, std::size_t /*length*/){
                    if (!ec){                        
                        std::cout << "StartWrite\n";
                        std::cout << "EndWrite\n";                        
                        createClientOBJ();
                    }else{
                        std::cerr << "write ec: " << ec << endl;
                    }
                }
            );   
        }

        
        void writeToHtmlSocket(string htmlContent){
            auto self(shared_from_this());
            boost::asio::async_write(socket_, boost::asio::buffer(htmlContent.c_str(), strlen(htmlContent.c_str())),  boost::asio::transfer_all(), //it means that buffer has strlen(data_) space, then this function can continue run.
                    [this, self](boost::system::error_code ec, std::size_t length){
                        if(!ec){
                            std::cout << "outputToHtml\n";
                        }else{
                            std::cerr << "outputTohtml is error: " << ec.message() << std::endl;
                        }
                    }
            );
        }

        void createClientOBJ(){
            for(map<int, struct serverInfo_s>:: iterator it = servers.begin(); it != servers.end(); it++){   
                std::cout << "create Client start\n";
                std::make_shared<Client>(global_io_service, it->first, get_ptr())->start(it->second.name, it->second.port, it->second.fileName);
                std::cout << "creat Client end\n";
            }
        }

    public:
        session(tcp::socket socket)
            : socket_(std::move(socket)){
        
        }

        void start(){
            do_read();
        }

        std::shared_ptr<session> get_ptr(){
            return shared_from_this() ; // Good
        }

        class Client: public std::enable_shared_from_this<Client>{
            int elementID;
            fstream pFile;
            std::string port;
            tcp::resolver resolver_;
            tcp::socket socket_;
            enum { max_length = 1024 };    
            char read_[max_length];
            char write_[max_length];    
            std::shared_ptr<class session> sessionPtr;

        public:
            Client(boost::asio::io_service& io_service, int id, const std::shared_ptr<session> &ptr)
                    : resolver_(io_service), socket_(io_service), sessionPtr(ptr) {
                elementID = id;        
            }

            void start(std::string serverName, std::string serverPort, std::string fileName){        
                std::cout << "start stage\n";
                port = serverPort;
                pFile.open((instrDictionary + fileName).c_str(), ios::in);

                tcp::resolver::query query(serverName, serverPort);
                resolver_.async_resolve(query, boost::bind(&Client::onResolve, get_ptr(), boost::asio::placeholders::error, boost::asio::placeholders::iterator));
                std::cout << "client start stage end\n";
            }

            std::shared_ptr<Client> get_ptr(){
                return shared_from_this();
            }

        private:
            void onResolve(const boost::system::error_code& err, tcp::resolver::iterator endpoint_iterator) {
                if (!err) {
                    std::cerr<< port << "onResolve-S" << endl;
                    tcp::endpoint endpoint = *endpoint_iterator;
                    socket_.async_connect(endpoint,
                                    boost::bind(&Client::onConnect, get_ptr(), boost::asio::placeholders::error, ++endpoint_iterator));
                    std::cerr<< port << "onResolve-E" << endl;
                }
                else {
                    std::cout << "Error: " << err.message() << "\n";
                }
            }

            void onConnect(const boost::system::error_code& err, tcp::resolver::iterator endpoint_iterator){
                if (!err){
                    // The connection was successful. Send the request.            
                    std::cerr<< port << "onConnect-S" << endl;
                    readStage();            
                    std::cerr<< port << "onConnect-E" << endl;
                }
                else if (endpoint_iterator != tcp::resolver::iterator()){
                    // The connection failed. Try the next endpoint in the list.
                    socket_.close();
                    tcp::endpoint endpoint = *endpoint_iterator;
                    socket_.async_connect(endpoint,
                    boost::bind(&Client::onConnect, get_ptr(),
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

                socket_.async_read_some(boost::asio::buffer(read_, max_length),  //!!old file no max_length parameter
                [this, self](boost::system::error_code ec, std::size_t length){
                        if (!ec){ 
                            std::string lines = string(read_);
                            memset(read_, 0, max_length);

                            std::string outputToHtml = "";
                            if(lines.find("% ") != std::string::npos){
                                //std::cerr << "response:\n" << lines << std::endl << "data:" << read_ << std::endl << "response end\n";
                                outputToHtml = strOutputToHtml(elementID, lines, string("orange"));                        
                                sessionPtr->writeToHtmlSocket(outputToHtml);

                                writeStage();
                                //readStage();
                            }else{
                                //std::cerr << "response2:\n" << lines << std::endl << "response end\n";
                                outputToHtml = strOutputToHtml(elementID, lines, string("orange"));
                                sessionPtr->writeToHtmlSocket(outputToHtml);

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

                std::cerr << "write: " << write_ << endl;
                boost::asio::async_write(socket_, boost::asio::buffer(write_, strlen(write_)),  boost::asio::transfer_all(), //it means that buffer has strlen(data_) space, then this function can continue run.
                        [this, instr, self](boost::system::error_code ec, std::size_t /*length*/){
                            if(!ec){                              
                                memset(write_, 0, max_length);
                                std::string outputToHtml = "";
                                outputToHtml = strOutputToHtml(elementID, instr + string("\n"), string("brown"));   
                                sessionPtr->writeToHtmlSocket(outputToHtml);

                                if(instr.compare("exit") == 0){
                                    std::cerr << "endding\n";
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

};

class server{
    tcp::acceptor acceptor_;
    private:
        void do_accept(){
            //process will create thread to monitor a new client. (this thread is running acceptor_.async_accept() function.)
            acceptor_.async_accept( 
                    [this](boost::system::error_code ec, tcp::socket socket){
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

        global_io_service.run();  //the parent process will hold on(not continue)
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

std::string panelHtmlContent(){
    std::string htmlContent = "";

    htmlContent = string("Content-type: text/html\r\n\r\n");
    htmlContent += string("<!DOCTYPE html><html lang=\"en\"><head><title>NP Project 3 Panel</title>")
                + string("<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css\" integrity=\"sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2\" crossorigin=\"anonymous\" />")
                + string("<link href=\"https://fonts.googleapis.com/css?family=Source+Code+Pro\" rel=\"stylesheet\" />")
                + string("<link rel=\"icon\" type=\"image/png\" href=\"https://cdn4.iconfinder.com/data/icons/iconsimple-setting-time/512/dashboard-512.png\" />")
                + string("<style>* { font-family: \'Source Code Pro\', monospace; }</style>")
                + string("</head><body class=\"bg-secondary pt-5\">");
    
    std::string FORM_ACTION = "console.cgi";
    std::string FORM_METHOD = "GET";
    std::string DOMAINNAME = "cs.nctu.edu.tw";

    htmlContent += string("<form action=\"") + FORM_ACTION + string("\" method=\"{FORM_METHOD}\"><table class=\"table mx-auto bg-light\" style=\"width: inherit\">")
                +  string("<thead class=\"thead-dark\"><tr><th scope=\"col\">#</th><th scope=\"col\">Host</th><th scope=\"col\">Port</th><th scope=\"col\">Input File</th></tr>")
                +  string("</thead><tbody>");
    
    std::vector<std::string> test_cases;
    for(int i = 1; i <= 10; i++)
        test_cases.push_back(string("t") + std::to_string(i) + string(".txt"));

    std::vector<std::string> hosts;
    for(int i = 0; i < 12; i++)
        hosts.push_back(string("nplinux") + std::to_string(i + 1));

    std::string test_case_menu = "";
    for(int i = 0; i < test_cases.size(); i++)
        test_case_menu += string("<option value=\"") + test_cases[i] + string("\">") + test_cases[i] + string("</option>");        

    std::string host_menu = "";
    for(int i = 0; i < hosts.size(); i++)
        host_menu += string("<option value=\"") + hosts[i] + string(".") + DOMAINNAME + string("\">") + hosts[i] +string("</option>");    
    

    int N_SERVERS = 5;
    for(int i = 0; i < N_SERVERS; i++){
        htmlContent += string("<tr><th scope=\"row\" class=\"align-middle\">Session ") + std::to_string(i + 1)
                    + string("</th><td><div class=\"input-group\"><select name=\"h") + std::to_string(i)
                    + string("\" class=\"custom-select\">") + string("<option></option>") + host_menu + string("</select>")
                    + string("<div class=\"input-group-append\"><span class=\"input-group-text\">.cs.nctu.edu.tw</span>")
                    + string("</div></div></td><td><input name=\"p") + std::to_string(i) + string("\" type=\"text\" class=\"form-control\" size=\"5\" />")
                    + string("</td><td><select name=\"f") + std::to_string(i) + string("\" class=\"custom-select\">")
                    + string("<option></option>") + test_case_menu + string("</select></td></tr>");                         
    }

    htmlContent += string("<tr><td colspan=\"3\"></td><td><button type=\"submit\" class=\"btn btn-info btn-block\">Run</button>")
                + string("</td></tr></tbody></table></form></body></html>");
        

    return htmlContent;
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

std::string consoleHtmlContent(map<int, struct serverInfo_s> &servers){
    std::string htmlContent = "";
    htmlContent += string("Content-type: text/html\r\n\r\n")
                +  string("<!DOCTYPE html>") + string("<html lang=\"en\">\n") + string("<head>\n")
                + string("<meta charset=\"UTF-8\" />\n") + string("<title>NP Project 3 Sample Console</title>\n")
                + string("<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css\" integrity=\"sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2\" crossorigin=\"anonymous\"/>\n")
                + string("<link href=\"https://fonts.googleapis.com/css?family=Source+Code+Pro\" rel=\"stylesheet\"/>\n")
                + string("<link rel=\"icon\" type=\"image/png\" href=\"https://cdn0.iconfinder.com/data/icons/small-n-flat/24/678068-terminal-512.png\"/>\n")
                + string("<style>\n")
                + string("* {\nfont-family: \'Source Code Pro\', monospace;\nfont-size: 1rem !important;\n}\n")
                + string("body {\nbackground-color: #212529;\n}\npre {\ncolor: #cccccc;\n}\ncTypeA {\ncolor: #ed5e26;\n}\ncTypeB {\ncolor: #ffae14;\n}\n")
                + string("</style>\n")
                + string("</head>\n")
                + string("<body>\n")
                + string("<table class=\"table table-dark table-bordered\">\n")
                + string("<thead>\n")
                + string("<tr>\n");

    for(map<int, struct serverInfo_s>:: iterator it = servers.begin(); it != servers.end(); it++){
            htmlContent += string("<th scope=\"col\">") + it->second.name + string(":") + it->second.port + string("</th>\n");
    }

    htmlContent += string("</tr>\n")
        + string("</thead>\n")
        + string("<tbody>\n")
        + string("<tr>\n");
    
    for(map<int, struct serverInfo_s>:: iterator it = servers.begin(); it != servers.end(); it++){
            htmlContent += string("<td><pre id=\"s") + std::to_string(it->first) + string("\" class=\"mb-0\"></pre></td>\n");
    }
    
    htmlContent += string("</tr>\n")
        + string("</tbody>\n")
        + string("</table>\n")
        + string("</body>\n")
        + string("</html>\n");
    
    return htmlContent;
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

//-------------need to rewrite----------------
std::string strOutputToHtml(int elementID, string content, string targetColor){
    std::string htmlContent = "";
    std::string color;

    if(targetColor.compare("orange") == 0){
        color = "cTypeA";
    }else if(targetColor.compare("brown") == 0){
        color = "cTypeB";
    }

    content = htmlEscape(content);
    htmlContent = string("<script>document.getElementById(\'s") + std::to_string(elementID) 
                        + string("\').innerHTML += \'<") + color + string(">") + content + string("</")
                        + color + string(">\';</script>\r\n");

    return htmlContent;
}