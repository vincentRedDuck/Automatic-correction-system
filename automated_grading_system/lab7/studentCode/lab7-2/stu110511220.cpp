#include<iostream>
using namespace std;
int main () {
    while(true) {
        int option,length;
        cout << "1: encoder 2: decoder 3: quit: ";
        cin >> option;
        if(option==3)
            break;
        if(option!=1&&option!=2) {
            cout << "invalid input" << endl;
            cout << endl;
            continue;
        }
        cout << "Please enter sentences length: ";
        cin >> length;
        char ary[100]={0};
        for(int i=0;i<length;i++) {
            cin >> ary[i];
        }
        if(option==1) {
            for(int i=0;i<length;i++) {
                cout << ((length%2==1) ? ((i<=length/2) ? ary[2*i] : ary[2*(i-length/2)-1]) : ((i<length/2) ? ary[2*i] : ary[2*(i-length/2)+1]));
            }
        }
        else if(option==2) {
            for(int i=0;i<length;i++) {
                cout << ((i%2==0) ? ary[i/2] : ((length%2==1) ? ary[(i+1)/2+length/2] : ary[(i-1)/2+length/2]));
            }
        }
        cout << endl << endl;
    }

    return 0;
}
