#include<iostream>
#include<string>

using namespace std;
bool apha(char);
int main(){
    string str;
    cout<<"Enter the sentence: ";
    getline(cin,str);
    bool going = true;
    if (str=="Stop the program")
        going=false;
    while(going){
            str+="0";
            str="0"+str;
            int csta=0;
            int cend=0;
        int sta[50];
        for (int i=0;i<=50;i++)
            sta[i]=0;
        int en[50];
        for (int i=0;i<=50;i++)
            en[i]=0;
            
            
        for (int i=1;i<str.length();i++){
            if (apha(str[i])&&!apha(str[i-1])){
                sta[csta]=i;
                csta++;
            }
            if (apha(str[i])&&!apha(str[i+1])){
                en[cend]=i;
                cend++;
            }
        }
        for (int i=50; i>=0;i--){
            if (sta[i]!=0){
                cout<<str.substr(sta[i],en[i]-sta[i]+1);
                if (i!=0)
                    cout<<" ";
            }
        }/*
        if (!apha(str[0]))
            cout<<str[0];*/
        cout<<endl<<"Enter the sentence: ";
        getline(cin,str);
        
        if (str=="Stop the program")
            going=false;
        
    }
    return 0;
}
bool apha(char a){
    if ((int(a)<=90&&int(a)>=65)||(int(a)<=122&&int(a)>=97))
        return true;
    else 
        return false;
}
