#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
string arr[100];
int num = 0;
bool endf = false;
void clear(){
    num = 0;
    for(int i = 0;i<100;i++){
        arr[i] = "";
    }
}
int main(){
    string s;
    cout<<"Enter the sentence: ";
    getline(cin,s);
while(s!="Stop the program"){

    for(int i=0;i<s.length();){
         string str ="";      
         while(isalpha(s[i])){


            str+=s[i];
            i++;
        }
        if(!isalpha(s[i])){
            i++;
            arr[num] = str;
            str = "";
            num++;
            while(i<s.length()&&!isalpha(s[i])){
                i++;
            }
        }

    }
    for(int i =num-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    clear();
    cout<<endl;
    cout<<"Enter the sentence: ";
    getline(cin,s);

}
    return 0;
}
