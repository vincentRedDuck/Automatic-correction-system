#include<bits/stdc++.h>

using namespace std;

void encode(int length){
    char a[length];
    cin>>a;
    for(int i=0;i<length;i+=2) {

        cout<<a[i];
    }
    for(int i=1;i<length;i+=2)cout<<a[i];
cout<<endl<<endl;
}    


void decode(int length) {
    char a[length];
    cin>>a;
    for(int i=0;i<length/2;i++ ) {
        cout<<a[i]<<a[i+length/2];
    }
    cout<<endl<<endl;

}
    

int main () {

    
    int op;
    int len;
    while(cout<<"1: encoder 2: decoder 3: quit: ") {
        cin>>op;
                
        if(op>3 || op < 1)cout<<"Invalid input\n"<<endl;

        switch(op) {
        
            case 1 :
                cout<<"Please enter sentences length: ";
                cin>>len;
                encode(len);
                break;

            case 2 :
                cout<<"Please enter sentences length: ";
                cin>>len;
                
                decode(len);
                break;

            case 3 :               

                return 0;

    }
    }
return 0;
}
