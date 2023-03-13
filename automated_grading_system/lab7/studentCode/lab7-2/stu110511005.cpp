#include<iostream>
using namespace std;
const int MAX_SIZE=100;
int main() {
    char word[MAX_SIZE];
    char first[MAX_SIZE];
    char second[MAX_SIZE];
    int sel;
    int len;
    while (cout << "1: encoder 2: decoder 3: quit: " , cin >> sel , sel!=3) {
        while (sel!=1 and sel!=2) {
            cout << "invalid input" << endl;
            cout << "\n1: encoder 2: decoder 3: quit: ";
            cin >> sel;
            if (sel==3)
                break;
        }
        if (sel==3)
            break;
        cout << "Please enter sentences length: ";
        cin >> len;
        for (int i=0 ; i<len ; i++) {
            cin >> word[i];
        }
        if (sel==1) {
            int j=0;
            int k=0;
            for (int i=0 ; i<len ; i++) {
                if (i%2==0) {
                    first[j]=word[i];
                    j++;
                }
                else {
                    second[k]=word[i];
                    k++;
                }
            }
            if (len%2==0) {
                for (int i=0 ; i<j ; i++) {
                      cout << first[i] << flush;
                }
                for (int i=0 ; i<k ; i++) {
                      cout <<  second[i] << flush;
                }
                cout << endl << endl;
            }
            else {
                for (int i=0 ; i<j ; i++) {
                    cout << first[i] << flush;
                }
                for (int i=0 ; i<k ; i++) {
                    cout << second[i] << flush;
                }
                cout << endl << endl;
            }   
        }
        if (sel==2) {
            if (len%2==0) {
                for (int i=0 ; i<len/2 ; i++) {
                    first[i]=word[i];
                }
                for (int i=0 ; i<len/2 ; i++) {
                    second[i]=word[i+len/2];
                }
                for (int i=0 ; i<len/2 ; i++) {
                    cout << first[i] << second[i]<<flush;
                }
                cout << endl << endl;
            }
            else {
                for (int i=0 ; i<len/2+1 ; i++) {
                    first[i]=word[2*i];
                }
                for (int i=0 ; i<len/2 ; i++) {
                    second[i]=word[1+i*2];
                }
                for (int i=0 ; i<len/2+1 ; i++) {
                    cout << first[i];
                }
                for (int i=0 ; i<len/2 ; i++) {
                    cout << second[i];
                }
                cout << endl << endl;
            }    
        }
    }
    return 0;
}
