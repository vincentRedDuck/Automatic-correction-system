#include<iostream>
using namespace std;
int main(){

	char a;
	int b;
	cout<<"Please enter a char : ";
	cin>>a;
	cout<<"Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
        cin>>b;
	switch(b){
	
	    case 1:
		    cout<<a<<endl;
		    break;

	    case 2:
		    cout<<(int)a<<endl;
		    break;
	    case 3: 
		    cout<<showbase<<oct<<(int)a<<endl;
		    break;    
	    case 4:
                    cout<<showbase<<hex<<(int)a<<endl;
		    break;
            default:
	            cout<<"No this option."<<endl;	    
	}
        	

	return 0;
}
