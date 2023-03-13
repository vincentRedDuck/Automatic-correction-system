#include<iostream>
using namespace std;

void encoder(char s[], int len){
    char temp[50],temp2[50];
    int t=0,t2=0;
    for(int i=0; i<len; i++){
        if(i%2==0)
            temp[t++] = s[i];
        else
            temp2[t2++] = s[i];
    }
    t--; t2--;
    for(int i=len-1; i>=0; i--){
        s[i] = ((t2<0)? temp[t--]:temp2[t2--]);
    }
}

void decoder(char s[], int len){
    char temp[50],temp2[50];
    int t=0,t2=0;
    for(int i=0; i<len; i++){
        if(i<(len+1)/2)
            temp[t++] = s[i];
        else
            temp2[t2++] = s[i];
    }
    t--; t2--;
    for(int i=len-1; i>=0; i--){
        if(i%2==0)
            s[i] = temp[t--];
        else
            s[i] = temp2[t2--];
    }
}

int main () {
    int type;
    cout << "1: encoder 2: decoder 3: quit: ";
    cin >> type;
    while(type != 3){
        if(type != 1 && type != 2)
            cout << "invalid input" << endl;
        else{
            cout << "Please enter sentences length: ";
            int len;
            cin >> len;
            char s[100];
            for (int i=0; i<len; i++) {
                cin >> s[i];
            }
            if (type == 1) 
                encoder(s,len);
            else
                decoder(s,len);
            for (int i=0; i<len; i++) 
                cout << s[i];
            cout << endl;
        }
        cout << "1: encoder 2: decoder 3: quit: ";
        cin >> type;
    }
    return 0;
}
