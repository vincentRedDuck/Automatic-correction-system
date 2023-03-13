#include<bits/stdc++.h>
#include<string>
using namespace std;

int count(char , string);


int main() {

    string word;
    while(1){
        word.clear();
        cout<<"Enter message: ";
        getline(cin,word);
        if(word=="Stop")break; 

        for(int i=0;i<26;i++){
            char t=char('A'+i);
            if(count(t,word)>0){
            cout<<t<<": "<<count(t,word)<<endl;
        }
        }
         for(int i=0;i<26;i++){
            char t=char('a'+i);
            if(count(t,word)>0){
            cout<<t<<": "<<count(t,word)<<endl;
        }
        }



    }

return 0;
}



int count(char c , string me){
    int sum=0;
    for(int i=0;i<=me.length()-1;i++){
        if(me.at(i)==c)sum++;
    }

return sum;
}
