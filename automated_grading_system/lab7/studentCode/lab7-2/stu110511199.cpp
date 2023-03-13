#include <iostream>
using namespace std;

const int MAXSIZE =100;
void fillAry(char ar[], int sz);
void enCode(char ar[], int sz);
void deCode(char ar[], int sz);
char sen[MAXSIZE], usedsized =0;

int main () {
    int type;
    int l;
    cout << "1: encoder 2: decoder 3: quit: ";
    cin >> type;
    while (type!=3) {
        if (type==1||type==2) {
            cout << "Please enter sentences length: ";
            cin >> l;
            fillAry(sen, l);
            if (type == 1)
                enCode(sen, l);
            else 
                deCode(sen, l);
        }
        else
            cout << "invalid input" << endl;
        cout << endl;
        cout << "1: encoder 2: decoder 3: quit: ";
        cin >> type;
    }
return 0;
}

void fillAry(char ar[], int sz) {
    for (int i=0; i<sz; i++) {
        cin >> ar[i];
    }
}
void enCode(char ar[], int sz) {
    for (int i=0; i<sz; i++) {
        if (i%2==0)
            cout << ar[i];
    }
    for (int i=0; i<sz; i++) {
        if (i%2!=0)
            cout << ar[i];
    }
    cout << endl;
}
void deCode(char ar[], int sz) {
    if (sz%2==0) {
        for (int i=0; i<(sz/2); i++) {
            cout << ar[i] << ar[sz/2+i];
        }
    }
    else {
        for (int i=0; i< (sz/2); i++) {
            cout << ar[i] << ar[sz/2+i+1];
        }
        cout << ar[sz/2];
    }
    cout << endl;
}
