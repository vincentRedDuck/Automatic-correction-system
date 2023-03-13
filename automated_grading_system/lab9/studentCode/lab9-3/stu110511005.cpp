#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include <fstream>

struct table
{
    string code;
    char ans;
};

int main(int argc, char *argv[])
{
    table tb[36];
    ifstream inFile;
    ofstream outFile;
    inFile.open("code.txt");
    for (int i = 0; i < 36; i++)
    {
        inFile >> tb[i].ans >> tb[i].code;
    }
    inFile.close();
    inFile.open(argv[1]);
    outFile.open(argv[2]);
    char ch;
    if (*argv[3] == 'e')
    {
        while (inFile.peek() != EOF)
        {
            inFile.get(ch);
            if(ch == ' ') {
                outFile << "       ";
            }
            else if(ch == '\n')outFile << '\n'; 
            else
            {
                for (int i = 0; i < 36; i++)
                {
                    if (tb[i].ans == ch)
                    {
                        outFile << tb[i].code;
                        break;
                    }
                }
                char tmp = inFile.peek();
                if (tmp != ' ')
                {
                    outFile << "   ";
                }
            }
        }
    }
    else {
        char ch;
        while(inFile.peek() != EOF){
            int counter = 0;
            while(inFile.peek() == ' '){
                counter++;
                inFile.get(ch);
            }
            string code;
            int newline = 0;
            if(counter <= 3){
                while(inFile.get(ch)){
                    if(ch != ' ' && ch != '\n'){
                        code.push_back(ch);
                    }
                    else{
                        if(ch == '\n')newline = 1;
                        break;
                    }
                }
                for(int i = 0; i < 36; i++){
                    if(tb[i].code == code){
                        outFile << tb[i].ans;
                        break;
                    }
                }
                if(newline)outFile << '\n';
            }
            else{
                outFile << " ";
            }
        }
    }
    inFile.close();
    outFile.close();
    return 0;
}
