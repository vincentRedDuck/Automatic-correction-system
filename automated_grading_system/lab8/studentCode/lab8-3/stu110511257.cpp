#include <iostream>
#include <string>
using namespace std;
const int MAX = 80;

int main () {
    cout << "Enter the sentence: ";
    string str, str1, str2; 
    getline(cin, str);
    while (str!="Stop the program") {
        str2 = "";
        for (int i=0; i<str.length(); i++) {
            if (isalpha(str[i])) {
                str1 = str1 + str[i];
                if (i==str.length()-1) {
                    str1 = str1 + "" + str2;
                    str2 = " " + str1;
                    str1 = "";
                }          
            }
            
            else {
                str1 = str1 + "" + str2;
                str2 = " " + str1;
                str1 = "";
            }
        }

        for (int j=1; j<str2.length(); j++) {
            if (str2[j-1]!=' '||str2[j]!=' ') 
                cout << str2[j];
        }
        
        cout << "\nEnter the sentence: ";
        getline(cin, str);
    }

    return 0;
}
