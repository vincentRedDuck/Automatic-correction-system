#include <iostream>
#include <cstring>
using namespace std;

const int MAX=100;
int cmp(char str[],int, int);

int main() {
    char sen[MAX];
    for(int i=0; i<MAX; i++)
        sen[i]='\0';
    cout << "Enter message: ";
    cin.getline(sen, MAX);
    while (strcmp(sen, "Stop")) {
        for(int i=0; i<26; i++) {
            if(cmp(sen, i, 1)!=0)   //uppercase:1
                cout << char('A'+i) << ": " << cmp(sen, i, 1) << endl;
        }
        for(int i=0; i<26; i++) {
            if(cmp(sen,i, 2)!=0)    //lowercase:2
                cout << char('a'+i) << ": " << cmp(sen, i, 2) << endl;
        }
        cout << "Enter message: ";
        cin.getline(sen, MAX);
   
    }
    return 0;
}

int cmp(char str[], int n, int t) {
    int total = 0 ;
    if (t==1) {
        for(int i=0; i<MAX; i++) {
            if (str[i]==('A'+n))
                total++;
        }
    }
    else {
        for(int i=-0; i<MAX; i++) {
            if (str[i]==('a'+n))
                total++;
        }
    }
    return total;
}
