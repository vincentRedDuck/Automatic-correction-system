#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    cout<<"Enter a num : "<<endl;
    double n;
    cin >> n;

    for(int i = 0 ;i <8;i++){
        cout<<"123456789~";
    }
    cout<<endl;
    cout<<left<<setw(20)<<"number"<<right<<setw(20)<<"scientific"<<setw(20)<<"signed"<<setw(20)<<"precision4"<<endl;
    cout<<left<<fixed<<setw(20)<<n<<right<<uppercase<<scientific<<setw(20)<<n<<fixed<<showpos<<setw(20)<<n;
    cout<<noshowpos<<setw(20)<<setprecision(4)<<n<<endl;

    return 0;
}
