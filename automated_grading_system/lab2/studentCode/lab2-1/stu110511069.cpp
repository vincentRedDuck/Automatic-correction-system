#include <iostream>
using namespace std;
int main(){
int g;
cout << "Enter your score : ";
cin>>g;
cout<< "You got a grade : ";
if (g>80) cout<<"A";
else if(g>70) cout<<"B";
else if(g>60) cout<<"C";
else if(g>50) cout<<"D";
else cout<<"E";
cout<<endl;
return 0;
}
