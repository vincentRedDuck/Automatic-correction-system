#include<iostream>
#include<string>
using namespace std;

int main(){
string a;
cout << "Enter message: ";
getline(cin,a);
int count=0;
while(a!="Stop"){
for(int j=0; j<26; j++){
    for(int i=0; i<a.length(); i++){
        if(char(j+'A')==a[i]){
            count++;  
        }
    }
   if(count>0){
        cout << char(j+'A') << ": " << count << endl;
    }
    count = 0;

}
for(int j=0; j<26; j++){
    for(int i=0; i<a.length(); i++){
        if(char(j+'a')==a[i]){
            count++;  
        }
    }
    if(count>0){
        cout << char(j+'a') << ": " << count << endl;
    }
    count = 0; 
}
cout << "Enter message: ";
getline(cin,a);
}
return 0;
}
