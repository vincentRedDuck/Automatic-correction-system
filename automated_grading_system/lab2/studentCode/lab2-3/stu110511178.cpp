#include<iostream>
#include<iomanip>

using namespace std;

int main(){
cout<<"\nPlease enter a char : ";
char a;
cin>>a;
cout<<"Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
int b;
cin>>b;
 
switch(b){

 case 1 : cout<<a;
         break;
 case 2 :printf("%d",a);
        break;
 case 3 :
        cout<<0;
        printf("%o",a);
        break;
 case 4 :cout<<"0x";
        printf("%x",a);
  break;
 default : cout<<"No this option.";
}
return 0;
}
