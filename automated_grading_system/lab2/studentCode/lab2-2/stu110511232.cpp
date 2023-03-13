#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double num;
    cout<<"Enter a num : ";
    cin>>num;
    cout<<"\n";

    int i;
    for (i=1;i<=8;i++){
        cout<<"123456789~";
    }
    cout<<endl;

    cout<<setw(30)<<left<<"number";
    cout<<setw(24)<<"scientific";
    cout<<setw(16)<<"signed";
    cout.unsetf(ios::left);
    cout<<setw(10)<<right<<"precision4"<<endl;
    cout.unsetf(ios::right);

    cout<<setw(27)<<fixed<<showpoint<<setprecision(6)<<left<<num;    
    cout.unsetf(ios::left);
    cout.unsetf(ios::fixed);
    cout<<setw(13)<<right<<uppercase<<scientific<<num;
    cout.unsetf(ios::scientific);
    cout.unsetf(ios::right);
    cout<<fixed<<setw(20)<<showpos<<right<<num;
    cout.unsetf(ios::showpos);
    cout<<setw(20)<<right<<setprecision(4)<<num<<endl;
    return 0;
}
