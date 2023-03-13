#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
    double x;
    cout<<"Enter a num : ";
    cin>>x;
    cout<<"\n123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~"<<endl;
    cout<<setw(6)<<"number";
    cout<<setw(34)<<"scientific";
    cout<<setw(20)<<"signed";
    cout<<setw(20)<<"precision4"<<endl;
    cout<<left<<setw(27)<<fixed<<setprecision(6)<<x;
    cout<<setw(13)<<right<<std::scientific<<uppercase<<x;
    cout<<setw(20)<<right<<fixed<<std::showpos<<x;
    cout<<setw(20)<<right<<fixed<<std::noshowpos<<setprecision(4)<<x<<endl;
    return 0;
}

