#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    cout<<"Enter message: ";
    getline(cin,str);
    while(str!="Stop"){
        int arr[123];
        for (int i=0;i<124;i++)
            arr[i]=0;
        for(int i=65;i<123;i++)
            for(int j=0;j<str.length();j++)
                if (str[j]==char(i))
                    arr[i]++;
        for(int i=65;i<123;i++)
            if (arr[i]!=0)
                cout<<char(i)<<": "<<arr[i]<<endl;
    cout<<"Enter message: ";
    getline(cin,str);
    }   
    return 0;
}

