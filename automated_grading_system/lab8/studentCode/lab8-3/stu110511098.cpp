#include<iostream>
#include<string>
using namespace std;
int main(){
    while(1){
        string a;
        cout<<"Enter the sentence: ";
        getline(cin,a);
        int k=0;
        if(a=="Stop the program")
            break;
        for(int i=a.length()-1;i>=0;i--){
            if(isalpha(a[i]))
                k++;
            if(i>0){
                if((isalpha(a[i-1])==false&&isalpha(a[i]))||(i==1&&isalpha(a[0]))){
                    cout<<a.substr((i==1?0:i),(i==1?k+1:k))<<" ";
                    k=0;
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
