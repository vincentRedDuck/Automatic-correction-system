#include <iostream>

using namespace std;

int main(){

char char123;
int output_type;

int a;




cout<<"Please enter a char :";
cin>>char123;
//cout<<endl;

cout<<" Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
cin>>output_type;
//cout<<endl;

//a=(int)'char123';
cout.setf(ios::showbase);
    if(output_type == 1){
        cout<<char123;
        cout<<endl;
    }

    else if(output_type == 2){
        cout<<dec;
        cout<< (int)char123 ;
        cout<<endl;
    }
    else if(output_type == 3){

        cout<<oct;
        cout<<(int)char123;
        cout<<endl;
    }

    else if(output_type ==4 ){
    
        cout<<hex;
        cout<<(int)char123;
        cout<<endl;
    }


    else{

        cout<<"No this option.";
        cout<<endl;
    }
}
