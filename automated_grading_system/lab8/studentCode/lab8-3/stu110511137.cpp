#include<iostream>
#include<cctype>
#include<string>
using namespace std;

void noalpha (string& s, int len) {
    for (int i=0; i<len; i++) {
        if (!(isalpha(s.at(i))))
            s[i] = '\0';
    }
}

int lastanspos (const string& s, int len, int ans[]) {
    int n=0;
    if (s[0] !='\0') {
        ans[0] = 0;
        n=1;
    }
    for (int i=1; i<len; i++) {
        if (s[i-1] == '\0' && s[i] != '\0')
            ans[n++] = i;
    }
    return n-1;
}

int main () {
    string s;
    cout << "Enter the sentence: ";
    getline(cin,s);
    while (s != "Stop the program") {
        int ans[100];
        int len = s.length();
        noalpha (s,len);
        int end = lastanspos(s, len, ans);
        for (int i=end; i>=0; i--) {
            for (int j=ans[i]; s[j]!='\0'; j++)
                cout << s[j];
            cout << " ";
        }
        cout << endl;
        cout << "Enter the sentence: ";
        getline(cin,s);
    }
    return 0;
}
