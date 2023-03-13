#ifndef _OBJECT
#define _OBJECT

#include <string>

using namespace std;

struct httpEnv_s{
    string TARGET_CGI;
    string REQUEST_METHOD;
    string REQUEST_URI;
    string QUERY_STRING;
    string SERVER_PROTOCOL;
    string HTTP_HOST;
    string SERVER_ADDR;
    string SERVER_PORT;
    string REMOTE_ADDR;
    string REMOTE_PORT;
};

struct serverInfo_s{
    string name;
    string port;
    string fileName;
};

#endif