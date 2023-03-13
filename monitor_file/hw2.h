#ifndef _HW2
#define _HW2

#include <dlfcn.h>
#include <sstream>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>


using namespace std;

typedef char* (*getenvFunc)(const char *name);

//--- 1. set alias for function return type ----
typedef int (*openFunc)(const char *pathname, int flags, int mode);
typedef int (*creatFunc)(const char *pathname, mode_t mode);
typedef int (*chmodFunc)(const char *pathname, mode_t mode);
typedef int (*chownFunc)(const char *pathname, uid_t owner, gid_t group);
typedef int (*renameFunc)(const char *oldpath, const char *newpath);
typedef ssize_t (*writeFunc)(int fd, const void *buf, size_t count);
typedef int (*closeFunc)(int fd);
typedef ssize_t (*readFunc)(int fd, void *buf, size_t count);
typedef FILE* (*tmpfileFunc)(void);
typedef size_t (*fwriteFunc)(const void *ptr, size_t size, size_t nmemb, FILE *stream);
typedef int (*fcloseFunc)(FILE *stream);
typedef FILE* (*fopenFunc)(const char *pathname, const char *mode);
typedef size_t (*freadFunc)(void *ptr, size_t size, size_t nmemb, FILE *stream);
typedef int (*removeFunc)(const char *pathname);
//----------------- end 1. ---------------------


// ---- 2. own-defined function -----
string addQuotes(string str);  //add double-quotes
string dtoh(int decimal); //decimal to hex
string getRealPath(string file); //get absoluate Path
void showMsg(char* functionName, char* ans, char* parameters,...);
char *stoa(string str);
string getFirst32Bytes(const char *buf, long long int size);
string fdFileName(pid_t uid, int fd);
static void setOutputFile(void);
// ------------ end 2. --------------


static void init(void) __attribute__((constructor));
static void finish(void)  __attribute__((destructor));

#endif