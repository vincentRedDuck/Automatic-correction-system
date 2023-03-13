#include<iostream>
#include<string>
using namespace std;

int main() {
    while (1) {
        string x;
        string y[100];
        int num =0;
        cout << "Enter the sentence: ";
        getline(cin,x);
        if (x == "Stop the program")
            break;
        for (int i=0;i<x.length();i++) {
            int z= int(x[i]);
            if ((z>=65&&z<=90)||(z>=97&&z<=122))
                y[num]+=x[i];
            if ((!(isalpha(x[i])))&&isalpha(x[i+1]))
                num++;
        }
        for (int i=num;i>=0;i--) 
            cout << y[i] <<((i==0)?"":" ");
        cout << endl;
    }
    return 0;
}
