#include <iostream>
#include <string>
using namespace std;

int main(){
    int sel;
    string in;

    while(cout<<"1: encoder 2: decoder 3: quit: ",cin>>sel,sel != 3 ){
        if(sel == 1){
            int l;
            cout << "Please enter sentences length: ";
            cin >> l; 
            //cin.ignore();
            // cin.ignore();
            cin>>in;

            for(int i = 0 ; i < in.length() ; i += 2)
                cout << in[i];
            for(int i = 1 ; i < in.length() ; i += 2)
                cout << in[i];
            cout << endl ;
        }
        else if(sel == 2){
            int l;
            cout << "Please enter sentences length: ";
            cin >> l; 

            //cin.ignore();
            //getline(cin,in);
            cin>>in;

            
            if(l%2 != 0){
                for(int i = 0 ; i < in.length()/2 ; i++ )
                    cout << in[i] << in[i+in.length()/2+1];
                cout<<in[in.length()/2];
            }
            else{
                for(int i = 0 ; i < in.length()/2 ; i++ )
                    cout << in[i] << in[i+in.length()/2];
            }
                
            cout << endl;
        }
        else
            cout<<"invalid input\n";
        cout << endl;
    }

    return 0;
}