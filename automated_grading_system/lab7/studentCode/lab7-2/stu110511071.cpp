#include<iostream>
using namespace std;

int main (){
    
    int mode,len;
    cout<<"1: encoder 2: decoder 3: quit: ";
    cin>>mode;
    char sen[100];
        while(mode!=3){
            switch(mode){
                case 1:
                    cout<<"Please enter sentences length: ";
                    cin>>len>>sen;
                    for (int i=0;i<len;i+=2)
                        cout<<sen[i];
                    for (int i=1;i<len;i+=2)
                        cout<<sen[i];
                    cout<<endl<<endl; 
                    break;
                case 2:
                    cout<<"Please enter sentences length: ";
                    cin>>len>>sen;
                    if (len%2==1){
                        int t;t=len/2+1;
                        for (int i=0;i<t;i++)
                            if (i==t-1)
                                cout<<sen[i];
                            else
                                cout<<sen[i]<<sen[i+t];
                    }
                    else{
                        int t;t=len/2;
                        for (int i=0;i<t;i++)
                            cout<<sen[i]<<sen[i+t];
                    }
                    cout<<endl<<endl;
                    break;
                    
                default:
                    cout<<"invalid input"<<endl<<endl;
            }
        cout<<"1: encoder 2: decoder 3: quit: ";
        cin>>mode;
        }
    return 0;
}
