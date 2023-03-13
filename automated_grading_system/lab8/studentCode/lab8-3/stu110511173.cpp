#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    while(1)
    {
        cout << "Enter the sentence: ";
        string sen;
        string res[100];
        getline(cin,sen);
        if(sen == "Stop the program")
            break;
        else
        {
            string tok;
            int num= 0;
            int len = sen.length();
            int start = 0;
            for(int i = 0 ; i<len; i++)
            {
                if(!isalpha(sen[i]))
                    continue;
                tok += sen[i];
                if(!isalpha(sen[i+1])||(i+1)==len) 
                {
                    res[num++] = tok;
                    tok.clear();
                }   
            }
            if(num==0)
                cout << endl;
            else
            {
            for(int i = num - 1; i>=0 ; i--)
            {
                if(i!=0)
                    cout << res[i] << " " ;
                else
                    cout << res[i] << endl;
            }
            }
        }
    }
    return 0;
}

