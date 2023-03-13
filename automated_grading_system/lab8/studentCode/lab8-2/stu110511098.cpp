#include<iostream>
#include<string>
using namespace std;

int t[52]={0};

void count(int k){
    t[k]++;
    return ;
}

int main(){
    while(1){
        string a;
        cout<<"Enter message: ";
        getline(cin,a);
        if(a=="Stop")
            break;
        for(int i=0;i<a.length();i++){
            if(isupper(a[i])){
                count(int(a[i])-65);
            }
            else if(islower(a[i])){
                count(int(a[i])-71);
            }
        }
        for(int i=0;i<52;i++){
            if(t[i]!=0)
                cout<<(i<26?char(i+65):char(i+71))<<": "<<t[i]<<endl;
        }
        for(int i=0;i<52;i++){
            t[i]=0;
        }
    }
    return 0;
}
