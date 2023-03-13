#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    while(1){
        int count=0;
        cout << "Enter the sentence: ";
        getline(cin,str);
        if(str=="Stop the program")break;
        for(int i=0; str[i]!='\0'; i++){
            count++;
        }
        count++;
        int start[count]={0};
        for(int i=0; i<count; i++){
            if(isalpha(str[i])){
                start[i]=1;
                while(isalpha(str[i])){
                    i++;
                }
            }
        }
        for(int i=count-1; i>=0; i--){
            if(start[i]==1){
                int j=i;
                while(isalpha(str[j])){
                    cout << str[j];
                    j++;
                }
                cout << " ";
            }
        }
        cout << endl;
    }
return 0;
}
