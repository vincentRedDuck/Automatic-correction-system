#include<iostream>
#include<string>
using namespace std;
int main(){
    while(1){
        string str;
        int num[2][26]={0};
        cout<<"Enter message: ";
        getline(cin,str);
        if(str=="Stop")
        break;
        int a=str.length();
        for(int i=0;i<a;i++){
            if(int(str[i])>=65&&int(str[i]<91))
            {
                num[0][str[i]-'A']++;
               // cout<<str[i]-'A'<<endl;
            }
            else 
            {
                num[1][str[i]-'a']++;
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<26;j++){
                 if(num[i][j]!=0){
                    if(i==0){
                        cout<<char(65+j)<<": "<<num[i][j]<<endl;
                    }
                    else
                        cout<<char(97+j)<<": "<<num[i][j]<<endl;
                
                //cout<<num[i][j]<<" ";
                }
                
                    
            }
        }
        
        
   } 
    return 0;
}
