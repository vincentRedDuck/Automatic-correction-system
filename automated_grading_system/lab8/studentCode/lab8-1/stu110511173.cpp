#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;


int main()
{
    while(1)
    {
        string first;
        string second;
        cout << "Enter first point:";
        cin >> first;
        cout << "Enter second point:";
        cin >> second;
        int a,b,c,d;
        if(first == "(0,0)" && second == "(0,0)")
            break;
        else
        {
            for(int i = 0 ; i < first.length() ; i++ )
            {
                if(first[i]=='('||first[i]==')' )
                    first.erase(i,1);
                else if(first[i] == ',') 
                {
                    a = stoi(first.substr(0,i));
                    b = stoi(first.substr(i+1,first.length()-2-i));

                }
            }   
            for(int i = 0 ; i < second.length() ; i++ )
            {
                if(second[i]=='('||second[i]==')' )
                    second.erase(i,1);
                else if(second[i] == ',') 
                {
                    c = stoi(second.substr(0,i));
                    d = stoi(second.substr(i+1,second.length()-2-i));

                }
            }   
            cout << "Distance: " << sqrt(abs(c-a)*abs(c-a)+abs(d-b)*abs(d-b)) << endl;
        }
        
    }
    return 0;
}
