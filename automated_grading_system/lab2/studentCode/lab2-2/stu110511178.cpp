#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    cout<<"Enter a num :";
    double  num ;
    cin>>num;

    cout<<"\n";
    for(int i=0;i<=7;i++)cout<<"123456789~";
    cout<<"\n";

    cout<<left<<setw(30)<<"number";
    cout<<setw(24)<<"scientific";
    cout<<setw(16)<<"signed";
    cout<<"precision4\n";



    
    cout<<fixed<<setw(27)<<num;
     
    cout.unsetf(ios::left);
   cout<<setw(13)<<uppercase<<scientific<<num;
    cout.unsetf(ios::scientific);
    cout<<fixed<<showpos<<setw(20)<<setprecision(6)<<num;
    

    cout.unsetf(ios::showpos);
    cout<<fixed<<setw(20)<<setprecision(4)<<num<<endl;
        
    






return 0;
}
