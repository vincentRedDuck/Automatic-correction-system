#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  char k;
  int j;
  cout<<"Please enter a char : "; 
  cin>>k;
  cout<<"Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
  cin>>j;
  switch(j)
  {
   case 1 :
   cout<<k;
   break;
   case 2 :
   cout<<dec<<(int)k;
   break;
   case 3 :
   cout<<showbase<<oct<<(int)k;
   break;
   case 4 :
   cout <<showbase<<hex<<(int)k;
   break;
   default :
   cout<<"No this option.";
}
cout<<endl;
return 0;

}
