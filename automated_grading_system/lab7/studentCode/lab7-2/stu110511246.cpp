#include<iostream>
#include<string>
using namespace std;
int main()
{
    int num,l;

    while(1){
        char x[100]={0},a[100]={0},b[100]={0};
        cout<<"1: encoder 2: decoder 3: quit: ";
        cin>>num;
        if(num==3){
            break;
        }
        else if(num!=1&&num!=2){
        cout<<"invalid input"<<endl;
        }
        
        else if(num==1){
            cout<<"Please enter sentences length: ";
            cin>>l;
            cin>>x;
            for(int i=0;i<l;i++){
                if(i%2==0){
                    a[(i)/2]=x[i];
                }
                else{
                    b[(i+1)/2-1]=x[i];
                }
            }   
            cout<<a<<b<<endl;
        }
        else if(num==2){
            cout<<"Please enter sentences length: ";
            cin>>l;
            for(int i=0;i<(l+1)/2;i++){
                cin>>a[i];
            }
            if(l%2==0){
                for(int i=0;i<(l+1)/2;i++){
                    cin>>b[i];
                }
            }
            else{
                for(int i=0;i<l/2;i++){
                    cin>>b[i];
                }
            }
            for(int i=0;i<(l+1)/2;i++){
                cout<<a[i];
                cout<<b[i];
            }
    
            cout<<endl;
        }
    }
    return 0;
}      
