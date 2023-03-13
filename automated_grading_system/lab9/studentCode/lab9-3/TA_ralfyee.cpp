#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct MORSE
{
    string alpha;
    string morse;
};

string morseToAlpha(MORSE morse[36], string code)
{
    if(code == "")
        return "";
    for(int i = 0; i<36; i++)
    {
        if(morse[i].morse == code)
        {
            return morse[i].alpha;
        }
    }
}

string alphaToMorse(MORSE morse[36], string code)
{
    for(int i = 0; i<36; i++)
    {
        if(morse[i].alpha == code)
        {
            return morse[i].morse;
        }
    }
}


int main(int argc, char *argv[])
{
    ifstream file;
    file.open("code.txt",ios::in);
    int idx = 0;
    MORSE morse[36];
    while(!file.eof())
    {
        char alphaFromFile;
        string morseFromFile;

        if(idx == 36)
            break;
        file>>alphaFromFile;
        file>>morseFromFile;
        morse[idx].alpha = alphaFromFile;
        morse[idx].morse = morseFromFile;
        idx++;
    }
    ifstream inputFile;
    inputFile.open(argv[1],ios::in);

    ofstream outputFile;
    outputFile.open(argv[2],ios::out);

    string stringFromFile;
    if(argv[3][0] == 'e')
    {
        char *pch;
        while(getline(inputFile,stringFromFile,'\n'))
        {
            char temp[stringFromFile.length() +1];
            strcpy(temp,stringFromFile.c_str());
            pch = strtok (temp," ");
            while (pch != NULL)
            {
                string word;
                word = pch;
                for(int i =0; i<word.length(); i++)
                {
                    string temp(1,word[i]);
                    cout<< alphaToMorse(morse,temp) <<" ";
                    outputFile<<alphaToMorse(morse,temp) <<" ";
                }
                pch = strtok (NULL, " ");
            }
            cout<<endl;
            outputFile<<endl;
        }
    }
    else
    {
        while(getline(inputFile,stringFromFile,'\n'))
        {
            string ans = "";
            string morsecode = "";
            int blankNum =0;
            for(int i =0; i<stringFromFile.length(); i++)
            {
                
                if(stringFromFile[i] != ' ')
                {
                    morsecode = morsecode + stringFromFile[i];
                    blankNum =0;
                }
                else
                {
                    blankNum++;
                    ans = ans + morseToAlpha(morse, morsecode);
                    if(blankNum == 5)
                        ans = ans + " ";
                    morsecode = "";
                }
                
            }
            ans = ans + morseToAlpha(morse, morsecode);
            cout<<"ans = "<<ans<<endl;
            outputFile<<ans<<endl;
        }
    }
    


    return 0;
}
