#include <iostream>
#include <unistd.h>
#include <string>
#include <string.h>

using namespace std;

// #define OWN_SHARELIB "./logger.so"

void showUsage()
{
    cout << "usage: ./logger [-o file] [-p sopath] [--] cmd [cmd args ...]" << endl
            << "\t-p: set the path to logger.so, default = ./logger.so" << endl
            << "\t-o: print output to file, print to \"stderr\" if no file specified" << endl
            << "\t--: separate the arguments for logger and for the command" << endl;
}

char *stoa(string str)
{
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());

    return cstr;
}

FILE* oFile = NULL;

int main(int argc, char **argv)
{   
    int cmd_opt, lastOptInd = 0;
    string command = "";
    string soFilePath = "./logger.so", outputFile = "stderr";


    while ((cmd_opt = getopt(argc, argv, "o:p:")) != -1)
    {
        switch (cmd_opt)
        {
            case '?':
                showUsage();
                exit(1);
                break;
            case 'p':
                soFilePath = optarg;
                break;
            case 'o':
                outputFile = optarg;
                break;
        }
    }

    int cmd_index = optind;    

    if(argc == 1)
    {
        cout << "no command given." << endl;
        exit(1);
    }
    else
    {        
        for(int i = cmd_index; i < argc; i++)
        {
            if(i == cmd_index)
                command = argv[i];
            else
                command += " " + string(argv[i]);
        }
    }

    setenv("LD_PRELOAD", soFilePath.c_str(), 1);
    if(outputFile.compare("stderr") != 0)
    {
        oFile = fopen(outputFile.c_str(), "w");
        setenv("HW2_OUTPUT_FILE_FD", stoa(std::to_string(fileno(oFile))), 1);
    }
    else
        setenv("HW2_OUTPUT_FILE_FD", "2", 1);
    
    system(command.c_str());

    if(oFile != NULL)
        fclose(oFile);
   
    return 0;
}