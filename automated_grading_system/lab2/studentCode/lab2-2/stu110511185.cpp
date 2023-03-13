#include<iostream>
#include<iomanip>
using namespace std;
using std::right;
int main(){
cout<<"Enter a num : ";
double  num;
cin>>num;
cout<<endl;
for(int t=0;t<8;t++){
   cout<<"123456789~";
    }
cout<<endl;
/*cout<<"number               scientific              signed           precision4"<<endl; not recommanded*/
/*wrong eg. cout<<setprecision(ios::right);
cout<<scientific;
cout<<showpos<<setprecision(4)<<num;*/
cout << setw(20) << left << "number";/*20 characters width 靠左*/
cout << setw(20) << right << "scientific";
cout << setw(20) << right << "signed";
cout << setw(20) << right << "precision4"<< endl;
cout << setw(20) << left << fixed << setprecision(6) << num;/*用fixed表示小數點後第setprecision(位數)*/
cout << setw(20) << right << uppercase << scientific << num;/*用uppercase 強制大寫 用scientific 科學記號*/
cout.unsetf(ios::scientific);/*撤消科記*/
cout << setw(20) << right << fixed << setprecision(6) << showpos << num;/*use showpos to show positive sign*/
cout.unsetf(ios::showpos);
cout << setw(20) << right << fixed << setprecision(4) << num <<endl;
}
