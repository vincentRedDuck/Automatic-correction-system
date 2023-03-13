#include "hw2.h"

using namespace std;

#define GLIBC "libc.so.6"
#define PRE_MSG "[logger]"

static int outputFD = -1;


static void init(void){}

static void finish(void){}


// ---- 3. own-defined function -----
void setOutputFile()
{    
    static getenvFunc glibc_env_func = NULL;
    static fopenFunc glibc_fopen_func = NULL;

    if(outputFD == -1)
    {
        if(glibc_env_func == NULL)
            glibc_env_func = (getenvFunc) dlsym(RTLD_NEXT, "getenv");

        char* outputFile = glibc_env_func("HW2_OUTPUT_FILE_FD");
        
        if(outputFile == NULL)
            outputFD = 2;
        else
        {
            string strNumber = string(outputFile);
            outputFD = stol(strNumber);
        }
    }        
}

string addQuotes(string str)  //add double-quotes
{
    return "\"" + str + "\"";
} 

string dtoh(int decimal) //decimal to hex
{
    stringstream ss;
    ss << hex << decimal;
    return ss.str();
}

string dtoo(int decimal) //decimal to octal
{
    stringstream ss;
    ss << oct << decimal;
    return ss.str();
}

string getRealPath(string file) //get absoluate Path
{
    char absolutePath[1024];
    char *resolv;
    if(resolv = realpath(file.c_str(), absolutePath))
        return absolutePath;
    
    return file;
}

void showMsg(string functionName, char* ans, char* parameters,...)
{
    char *arg = parameters;
    va_list vaPars;    
    dprintf(outputFD, "%s %s(", PRE_MSG, functionName.c_str());
    
    if(arg)
        dprintf(outputFD, "%s", arg);
    else
    {
        dprintf(outputFD, ") = %s\n", ans);
        return;
    }
    

    va_start(vaPars, parameters);
    arg = va_arg(vaPars, char*);

    while(arg)
    {
        dprintf(outputFD, ", %s", arg);
        arg = va_arg(vaPars, char*);
    }
    va_end(vaPars);
    
    dprintf(outputFD, ") = %s\n", ans);    
}

char *stoa(string str)
{
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());

    return cstr;
}

string getFirst32Bytes(const char *buf, long long int size)
{
    string str = "";

    int index = 0;
    while(index < 32  && buf[index] != '\0' && index < size)
    {
        str += (isprint(buf[index]))? buf[index]: '.';            
        index++;
    }

    return str;
}

string fdFileName(pid_t pid, int fd)
{
    string path = "/proc/" + std::to_string(pid) + "/fd/" + std::to_string(fd);

    char buf[1024];
    int len;
    len = readlink(path.c_str(), buf, 1024); //not handle error exception
    buf[len] = '\0'; 

    return buf;
}

// ------------ end 3. --------------


#ifdef __cplusplus
extern "C"
{
#endif


int open(const char *pathname, int flags, int mode = 0)
{
    setOutputFile();

    static openFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (openFunc) dlsym(RTLD_NEXT, __func__); 

    int ret = glibc_func(pathname, flags, mode);
           
    showMsg(__func__, stoa(std::to_string(ret)), stoa(addQuotes(getRealPath(pathname)))
                , stoa(dtoo(flags)), stoa(dtoo(mode)), NULL);
    
    return ret;
}

int open64(const char *pathname, int flags, int mode = 0)
{
    setOutputFile();

    static openFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (openFunc) dlsym(RTLD_NEXT, __func__);

    int ret = glibc_func(pathname, flags, mode);
           
    showMsg(__func__, stoa(std::to_string(ret)), stoa(addQuotes(getRealPath(pathname)))
                , stoa(std::to_string(flags)), stoa(dtoo(mode)), NULL);
    
    return ret;
}

int creat(const char *pathname, mode_t mode)
{
    setOutputFile();

    static creatFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (creatFunc) dlsym(RTLD_NEXT, __func__); 

    int ret = glibc_func(pathname, mode);
           
    showMsg(__func__, stoa(std::to_string(ret)), stoa(addQuotes(getRealPath(pathname)))
                , stoa(dtoo(mode)), NULL);
    
    return ret;
}

int creat64(const char *pathname, mode_t mode)
{
    setOutputFile();

    static creatFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (creatFunc) dlsym(RTLD_NEXT, __func__); 

    int ret = glibc_func(pathname, mode);
           
    showMsg(__func__, stoa(std::to_string(ret)), stoa(addQuotes(getRealPath(pathname)))
                , stoa(dtoo(mode)), NULL);
    
    return ret;
}


int chmod(const char *pathname, mode_t mode)
{
    setOutputFile();

    static chmodFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (chmodFunc) dlsym(RTLD_NEXT, __func__); 

    int ret = glibc_func(pathname, mode);
           
    showMsg(__func__, stoa(std::to_string(ret)), stoa(addQuotes(getRealPath(pathname)))
                , stoa(dtoo(mode)), NULL);
    
    return ret;
}

int chown(const char *pathname, uid_t owner, gid_t group)
{
    setOutputFile();

    static chownFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (chownFunc) dlsym(RTLD_NEXT, __func__); 

    int ret = glibc_func(pathname, owner, group);
           
    showMsg(__func__, stoa(std::to_string(ret)), stoa(addQuotes(getRealPath(pathname)))
                , stoa(std::to_string(owner)), stoa(std::to_string(group)), NULL);
    
    return ret;
}

int rename(const char *oldpath, const char *newpath)
{
    setOutputFile();

    static renameFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (renameFunc) dlsym(RTLD_NEXT, __func__); 

    char* tmpOldPath = stoa(addQuotes(getRealPath(oldpath)));
    int ret = glibc_func(oldpath, newpath);
    
    showMsg(__func__, stoa(std::to_string(ret)), tmpOldPath
                , stoa(addQuotes(getRealPath(newpath))), NULL);
    
    return ret;
}

ssize_t write(int fd, const void *buf, size_t count)
{
    setOutputFile();

    static writeFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (writeFunc) dlsym(RTLD_NEXT, __func__); 

    ssize_t ret = glibc_func(fd, buf, count);

    showMsg(__func__, stoa(std::to_string(ret)), stoa(fdFileName(getpid(), fd)),
                stoa(addQuotes(getFirst32Bytes((char*)buf, ret))), stoa(std::to_string(count)), NULL);
    
    return ret;
}

int close(int fd)
{
    setOutputFile();

    static closeFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (closeFunc) dlsym(RTLD_NEXT, __func__); 
    
    string fdPath = fdFileName(getpid(), fd);
    
    int ret = glibc_func(fd);

    showMsg(__func__, stoa(std::to_string(ret)), stoa(addQuotes(fdPath)), NULL);
    
    return ret;
}

ssize_t read(int fd, void *buf, size_t count)
{
    setOutputFile();

    static writeFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (writeFunc) dlsym(RTLD_NEXT, __func__); 

    ssize_t ret = glibc_func(fd, buf, count);

    showMsg(__func__, stoa(std::to_string(ret)), stoa(fdFileName(getpid(), fd)),
                stoa(addQuotes(getFirst32Bytes((char*)buf, ret))), stoa(std::to_string(count)), NULL);
    
    return ret;
}

FILE *tmpfile(void)
{
    setOutputFile();

    static tmpfileFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (tmpfileFunc) dlsym(RTLD_NEXT, __func__); 

    FILE *ret = glibc_func();
    
    char pointerData[256];
    sprintf(pointerData, "%p", ret);
    
    showMsg(__func__, pointerData, NULL);
    
    return ret;
}

FILE *tmpfile64(void)
{
    setOutputFile();

    static tmpfileFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (tmpfileFunc) dlsym(RTLD_NEXT, __func__); 

    FILE *ret = glibc_func();
    
    char pointerData[256];
    sprintf(pointerData, "%p", ret);
    
    showMsg(__func__, pointerData, NULL);
    
    return ret;
}

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    setOutputFile();

    static fwriteFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (fwriteFunc) dlsym(RTLD_NEXT, __func__);

    ssize_t ret = glibc_func(ptr, size, nmemb, stream);

    int fd = fileno(stream);

    showMsg(__func__, stoa(std::to_string(ret)),stoa(addQuotes(getFirst32Bytes((char*)ptr, ret * size))),
                    stoa(std::to_string(size)), stoa(std::to_string(nmemb)), stoa(fdFileName(getpid(), fd)), NULL);
    
    return ret;   
}

int fclose(FILE *stream)
{  
    setOutputFile();

    static fcloseFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (fcloseFunc)dlsym(RTLD_NEXT, __func__); 
    
    int fd = fileno(stream);
    string fdPath = fdFileName(getpid(), fd);
    
    int ret = glibc_func(stream);    

    showMsg(__func__, stoa(std::to_string(ret)), stoa(addQuotes(fdPath)), NULL);

    return ret;
}


FILE *fopen(const char *pathname, const char *mode)
{   
    setOutputFile();

    static fopenFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (fopenFunc) dlsym(RTLD_NEXT, __func__); 

    FILE *ret = glibc_func(pathname, mode);
    
    char pointerData[256];
    sprintf(pointerData, "%p", ret);

    showMsg(__func__, pointerData, stoa(addQuotes(getRealPath(pathname))), stoa(addQuotes(string(mode))), NULL);
    
    return ret;    
    
}


FILE *fopen64(const char *pathname, const char *mode)
{    
    setOutputFile();

    static fopenFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (fopenFunc) dlsym(RTLD_NEXT, __func__); 

    FILE *ret = glibc_func(pathname, mode);
           
    char pointerData[256];
    sprintf(pointerData, "%p", ret);

    showMsg(__func__, pointerData, stoa(addQuotes(getRealPath(pathname))), mode, NULL);
    
    return ret;
}

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    setOutputFile();

    static freadFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (freadFunc) dlsym(RTLD_NEXT, __func__); 

    ssize_t ret = glibc_func(ptr, size, nmemb, stream);

    int fd = fileno(stream);

    showMsg(__func__, stoa(std::to_string(ret)),stoa(addQuotes(getFirst32Bytes((char*)ptr, ret * size))),
                    stoa(std::to_string(size)), stoa(std::to_string(nmemb)), stoa(fdFileName(getpid(), fd)), NULL);
    
    return ret;   
}

int remove(const char *pathname)
{
    setOutputFile();
    static removeFunc glibc_func = NULL;
    if(glibc_func == NULL)
        glibc_func = (removeFunc) dlsym(RTLD_NEXT, __func__); 
    
    string absolutePath = getRealPath(pathname);
    
    int ret = glibc_func(pathname);
           
    showMsg(__func__, stoa(std::to_string(ret)), stoa(addQuotes(absolutePath)), NULL);
    
    return ret;
}



#ifdef __cplusplus
}
#endif
