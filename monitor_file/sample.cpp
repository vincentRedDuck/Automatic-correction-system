#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>

#define OWN_SHARELIB "./logger.so"

using namespace std;


int main(int argc, char* argv[])
{    
    //bigfile
    // FILE * fp = fopen("ubuntu-20.04.2.0-desktop-amd64.iso", "r");
    // fclose(fp);

    //sample
    int i, fd;
    rename("tmp2", "tmp");
    creat("tmp", 0600);
    chmod("tmp", 0660);
    chown("tmp", 65534, 65534);
    rename("tmp", "tmp2");
    
    fd = open("tmp2", O_WRONLY | O_TRUNC | O_CREAT, 0666);
    write(fd, "cccc\n", 5);
    close(fd);
    fd = open("tmp2", O_RDONLY, 0000);
    char buf[1024];
    read(fd, buf, 100);
    close(fd);
    FILE *fp;
    fp = tmpfile();
    fwrite(buf, sizeof(char), 5, fp);
    fclose(fp);
    fp = fopen("tmp2", "r");
    char buf2[1024];
    fread(buf2, sizeof(char), 100, fp);
    fclose(fp);
    remove("tmp2");
    write(0, "simple done.\n", 14);

    return 0;
}