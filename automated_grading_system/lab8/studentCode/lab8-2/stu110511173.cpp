#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    while(1)
    {
        string sen;
        cout << "Enter message: ";
        getline(cin,sen);
        int A[52] = {0};
        if( sen == "Stop")
            break;
        else
        {
            for(int i = 0 ; i< sen.length() ; i++)
            {
                if(char(sen[i])<91&&char(sen[i])>64)
                {
                    A[char(sen[i])-65] ++; 
                }
                else if(char(sen[i])>=97&&char(sen[i])<=122)
                {
                    A[char(sen[i])-71] ++;

                }                            
            }
            for(int i = 0 ; i<52 ; i++)
            {
                if(A[i]!=0)
                {
                    if(i<26)
                    {
                        cout << char(i+65) << ": " << A[i] << endl;
                    }
                    else
                    {
                        cout << char(i+71) << ": " << A[i] << endl;

                    }
                }
            }
        }
    }
    return 0;
}

