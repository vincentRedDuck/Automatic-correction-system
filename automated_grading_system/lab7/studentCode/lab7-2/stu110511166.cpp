#include<iostream>
#include<string>
using namespace std;

int main() {
    int type;
    while(1) {
        cout << "1: encoder 2: decoder 3: quit: ";
        cin >> type;
        switch(type) {
        case 1:
        {   cout << "Please enter sentences length: ";
            int l;
            cin >> l;
            string s;
            char x[(l+1)/2];
            char y[(l+1)/2];
            cin >> s;
            for(int i=0; i < l; i++) {
                if(i%2==0)
                    x[i/2]=s[i];
                else
                    y[(i-1)/2]=s[i];
            }
            for(int i=0; i < (l+1)/2; i++) {
                cout << x[i];
            }
            if(l%2==0) {
                for(int i=0; i < (l+1)/2; i++) {
                    cout << y[i];
                }
            }
            else
                for(int i=0; i < (l+1)/2-1; i++) {
                    cout << y[i];
                }

            cout << endl;
            break;
            
        }
        case 2:
        {   cout << "Please enter sentences length: ";
            int l;
            cin >> l;
            //string a;
            //string b;
            char x[(l+1)/2];
            char y[(l+1)/2];
            for(int i=0; i < (l+1)/2; i++) {
                cin >> x[i];
            }
            for(int i=0; i < (l+1)/2; i++) {
                cin  >> y[i];
            }
            for(int i=0; i < (l+1)/2; i++) {
                cout << x[i];
                cout << y[i];
            }
            cout << endl;
            break;
        }
        case 3:
            break;
        default:
            cout << "Invalid input " << endl;
        }
        if(type == 3)
            break;
    }
    return 0;
}
