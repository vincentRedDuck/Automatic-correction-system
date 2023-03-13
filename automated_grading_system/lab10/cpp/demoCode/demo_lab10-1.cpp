#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <string.h>
#include <time.h>
#include <string>
#include <iostream>
using namespace std;


//--------------- need to rewrite ---------------------
#define LABNUMBER "lab10" //format "lab#", # is number of exercise
#define EXNUMBER "ex10" //format "ex#", # is number of exercise
#define EXERCISENUMBER "1" //format "#", # is number of exercise
#define TADIRPATH "/home/studemo/" //TA root directory
#define PEIVILEGEUID 1005 //UID is who has the TADIRPATH

#define USERNAMESIZE 20  //Student ID size. It usually not change.
#define CHECKRESULTDIRPATH "/tmp/"     //middle handdle. It usually not change.


void setEndTime(time_t &due_t){  // score will change 0.7 after the deadline. 
    struct tm *timeStruct = (struct tm*)malloc(sizeof(struct tm));
    timeStruct->tm_sec=0;
    timeStruct->tm_min=0;
    timeStruct->tm_hour =22;
    timeStruct->tm_mday=13;
    timeStruct->tm_mon=12-1;   // -1 is mean that the range is 0 to 11.
    timeStruct->tm_year=2021-1900; // -1900 is mean the year start from 1900.
    due_t = mktime(timeStruct);
}
//---------------------- end ---------------------------


#define BASHPATH (TADIRPATH LABNUMBER "/script/" LABNUMBER "-" EXERCISENUMBER ".sh")
#define LOGFILE (TADIRPATH LABNUMBER "/log/" EXERCISENUMBER ".log")
#define GOOGLESHEETPYTHONPATH (TADIRPATH  "upload_record_new.py")

using namespace std;

string charToString(const char *charArray);

int main(){
    time_t cur_t, due_t;
    time(&cur_t);
    setEndTime(due_t);

    string dirname = TADIRPATH + charToString(LABNUMBER) + charToString("/") + charToString("studentCode") + charToString("/") + charToString(LABNUMBER) 
                        + charToString("-") + charToString(EXERCISENUMBER) + charToString("/");
    string codename = charToString(EXNUMBER) + charToString("-") + charToString(EXERCISENUMBER) + charToString(".cpp");

    char* username = (char*)malloc(sizeof(char) * USERNAMESIZE);
    memset(username, '\0', USERNAMESIZE);
    getlogin_r(username, 20);  //get current user who login this server.
    
    string studentOutputfile = charToString(CHECKRESULTDIRPATH) + charToString(LABNUMBER) + charToString("/") + charToString(LABNUMBER) + charToString("-") + charToString(username);
    string copypath = dirname + username + charToString(".cpp");
    
    pid_t pid;
    int status = 999;
    int waitpid;

    //Run demo bash file
    if((pid = fork()) < 0){
        perror("fork error\n");
    }
    else if(pid == 0){
        //child process
        if(setuid(PEIVILEGEUID) != 0)
            printf("Error: setuid(%d)\n", PEIVILEGEUID);

        //check now effective uid (debug)
        // uid_t  uid;
        // uid = geteuid();
        // cerr << "effective: " << uid << endl;

        execlp("bash", "bash", BASHPATH, NULL);
    }
    else{
        //parent process
        waitpid = wait(&status);        
    }    


   //if(FILE *file = fopen((charToString(CHECKRESULTDIRPATH) + charToString(LABNUMBER) + charToString("/") + charToString(LABNUMBER) + charToString("-") + charToString(username)).c_str(), "r")){
    if(FILE *file = fopen((charToString(CHECKRESULTDIRPATH) + charToString(LABNUMBER) + charToString("/") + charToString(LABNUMBER) + charToString("-") + charToString(username)).c_str(), "r")){
        fclose(file);
    }else{
    	printf("%s\n", (charToString(CHECKRESULTDIRPATH) + charToString(LABNUMBER) + charToString("/") + charToString(LABNUMBER) + charToString("-") + charToString(username)).c_str());
        printf("no executable file\n");
        exit(0);
    }
   

    //Run diff command to check if student's program is correct.   
    if((pid = fork()) < 0){
        perror("fork error\n");
    }
    else if(pid == 0){
        //child process
        if(setuid(PEIVILEGEUID) != 0)
            printf("Error: setuid(%d)\n", PEIVILEGEUID);
        
        execlp("diff", "diff", "-Z", "-B", (charToString(CHECKRESULTDIRPATH) + charToString(LABNUMBER) + charToString("/") + charToString("true") + charToString(EXERCISENUMBER)).c_str(), studentOutputfile.c_str(), NULL);
        
        cerr << "diff error" << endl;
    }
    else{
        //parent process
        waitpid = wait(&status);
    }

//check it
    //Write the student whose code is correct to log file

    if((status >> 8) == 1){
        printf("The student's program is Fail.\n");
    }
    else{
        printf("The student's program is Correct!\n");
 	
	//Copy student's code to the depository (in order to catch the Plagiarisms)
        if((pid = fork()) < 0){
            perror("fork error\n");
        }
        else if (pid == 0){
            if(setuid(PEIVILEGEUID) != 0)
                perror("setuid error");

            execlp("cp","cp", "-n", codename.c_str(), copypath.c_str(), NULL);
        }
        else{
            waitpid = wait(&status);
        }

	if((status >> 8) == 1){
	    printf("Error: the cpp file name is wrong.\n");
	    return 0;
	}

        
        //Write score to google sheet
        if((pid = fork()) < 0){
            perror("fork error\n");
        }
        else if (pid == 0){        
            //child process
            if(setuid(PEIVILEGEUID) != 0)
                perror("setuid error");
            
            int outfd = open(LOGFILE, O_CREAT | O_WRONLY | O_APPEND, 0700);
            
	    if(outfd == 0)
                cerr<< "Error: open " << LOGFILE << endl;

            int saved_stdout = dup(1);  //avoid that python program print string to log file
            
            dup2(outfd, 1);
            printf("%s\n", username);   //print string to log file
            close(outfd);

            dup2(saved_stdout, 1);
            if(difftime(cur_t, due_t)>0)
		//cerr << "score: 0.7" << endl;
                execlp("python3","python3", GOOGLESHEETPYTHONPATH, LABNUMBER,"0.7",EXERCISENUMBER,NULL);
            else
		//cerr << "score: 1.0" << endl;
                execlp("python3","python3", GOOGLESHEETPYTHONPATH, LABNUMBER,"1.0",EXERCISENUMBER,NULL);
            
            cerr << "Python error" << endl;
        }
        else{
            //parent process
            waitpid = wait(&status);
        }


   }

    return 0;
}


//----------------other functions--------------

string charToString(const char *charArray){
    string str(charArray);
    return str;
}
