#include<iostream>
#include<iomanip>
using namespace std;
const int MAX = 100;

int main(){
    int N;
    char v1[MAX];
    char v2[MAX];
    cout<<"1: encoder 2: decoder 3: quit: ";
    cin>>N;

    while(N!=3){
        if(N==1){
            cout<<"Please enter sentences length: ";
            int L;
            cin>>L;
            
            for(int i = 0;i<L;i++){
                cin>>v1[i];
            }
            for(int i = 0;i<L;i+=2){
                cout<<v1[i];
            }
            
            for(int i =1;i<L;i+=2){
                cout<<v1[i];
            }
            cout<<endl;
            cout<<endl;
            
        }
        else if(N==2){
            cout<<"Please enter sentences length: ";
            int L;
            cin>>L;
            for(int i=0;i<L/2+L%2;i++){
                cin>>v1[i];
            }
            for(int i =0;i<L/2;i++){
                cin>>v2[i];
            }
            for(int i=0;i<L/2+L%2;i++){
                cout<<v1[i];
                if(i<L/2)cout<<v2[i];
            }
            cout<<endl;
            cout<<endl;
        }
        else{
            cout<<"invalid input";
        }
        cout<<"1: encoder 2: decoder 3: quit: ";
        cin>>N;
    }       return 0;
}
