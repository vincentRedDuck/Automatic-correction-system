#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct morse
{
    char ch;
    string mor;  
};

int main(int argc,char *argv[])
{
    ifstream fin1("code.txt");
    morse table[36];
    for(int i=0 ;i<36 ;i++) 
    {
        fin1 >> table[i].ch >> table[i].mor; 
    } 
    fin1.close(); 
     
    ifstream fin2(argv[1]);
    ofstream fout(argv[2]);
    char token;
    if(argv[3][0]=='e')
    {
        while(fin2.get(token))
        {
            if(isalpha(token)||isdigit(token))
            {
                for(int i=0; i<36; i++)
                {
                    if(table[i].ch==token)
                    {
                        fout << table[i].mor << "   ";
                        break;
                    }
                }        
            }    
            else if(token==' ')
                fout << "    ";
            else if(token=='\n')
                fout << endl;    
        }
    }
    else
    {
        int num = 0;
        string word;
        while(fin2.get(token))
        {
            //int num = 0;
            //string word;
            if(token=='-'||token=='.')
            {
                word += token;
                num = 0;
            }       
            else if(token=='\n')
            {
                for(int i=0; i<36; i++)
                {
                    if(word==table[i].mor)
                    {
                        fout << table[i].ch ;
                        break;
                    }
                }
                fout << endl;
                word.clear();
            }
            else
            {
                num++;
                if(num==3)
                {
                    for(int i=0; i<36; i++)
                    {
                        if(word==table[i].mor)
                        {
                            fout << table[i].ch ;
                            break;
                        }
                    }
                    fout << "\0";
                    word.clear();
                }
                else if(num==7)
                    fout << " ";
            }
        }
    }    
    return 0;
}
