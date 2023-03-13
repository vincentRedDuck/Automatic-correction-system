#include <string.h>
#include <iostream>
using namespace std;

int main() {
    cout << "1: encoder 2: decoder 3: quit: ";
    int input; cin >> input;
    while(input!=3) {
        if(input!=1 && input!=2) {
            cout << "invalid input" << endl << endl;
        }
        else {
            cout << "Please enter sentences length: ";
            int sLen; cin >> sLen;
            char sen[100];
            for(int len=0; len<sLen; len++) {
                cin >> sen[len];
            }
            if(input==1) {
                if(sLen%2!=0) {
                    char sen1[50];
                    char sen2[50];

                    for(int len=0; len<sLen; len++) {
                        if(len%2==0)
                            sen1[len/2] = sen[len];
                        else
                            sen2[len/2] = sen[len];
                    }
                    for(int len=0; len<sLen/2+1; len++) {
                        cout << sen1[len] << flush;
                    }
                    for(int len=0; len<sLen/2; len++) {
                        cout << sen2[len] << flush;
                    }
                    cout << endl << endl;
                }
                else {
                    char sen1[50];
                    char sen2[50];
                    for(int len=0; len<sLen; len++) {
                        if(len%2==0)
                            sen1[len/2] = sen[len];
                        else
                            sen2[len/2] = sen[len];
                    }
                    for(int len=0; len<sLen/2; len++) {
                        cout << sen1[len] << flush;
                    }
                    for(int len=0; len<sLen/2; len++) {
                        cout << sen2[len] << flush;
                    }
                    cout << endl << endl;
                }
            }
            else {
                char senNew[sLen] = "";
                if(sLen%2!=0) {
                    for(int len=0; len<sLen/2+1; len++) {
                        senNew[2*len]= sen[len]; 
                    }
                    for(int len=sLen/2; len<sLen; len++) {
                        senNew[2*(len-sLen/2)+1] = sen[len];
                    }
                }
                else {
                    for(int len=0; len<sLen/2; len++) {
                        senNew[2*len]= sen[len]; 
                    }
                    for(int len=sLen/2; len<sLen; len++) {
                        senNew[2*(len-sLen/2)+1] = sen[len];
                    }
                }
                for(int len=0; len<sLen; len++) {
                      cout << senNew[len] << flush;
                }   
                cout << endl << endl;
            }
        }
        cout << "1: encoder 2: decoder 3: quit: ";
        cin >> input;
    }

    return 0;
}

