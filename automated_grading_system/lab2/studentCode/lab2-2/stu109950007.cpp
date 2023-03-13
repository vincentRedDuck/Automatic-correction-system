#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
        double num;

        cout << "Enter a num : ";
        cin >> num;

        cout << endl;
        cout << "123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~"<<endl;
        cout << "number" << setw(34) <<"scientific" << setw(20) <<"signed" << setw(20) <<"precision4"<< endl;

        cout<<left<<setw(20)<<fixed<<setprecision(6)<<num;


        cout<<scientific;
	cout<<setiosflags(ios::uppercase);
        cout<<right<<setw(20)<<num;

        cout.unsetf(ios::scientific);
	cout<<resetiosflags(ios::uppercase);
        cout<<showpos;
        cout<<right<<fixed<<setprecision(6)<<setw(20)<<num;

        cout.unsetf(ios::showpos);
	cout.unsetf(ios::scientific);
        cout<<right<<setw(20)<<fixed<<setprecision(4)<<num<<endl;

        return 0;
}
