#include<iostream>
#include<cctype>
using namespace std;

const int MAX = 100;
string word[MAX];
void parseprt(string);

int main(){
    string s;
    while(1){
        cout << "Enter the sentence: ";
        getline(cin, s);
        if(s == "Stop the program") break;
        parseprt(s);
        
    }
    return 0;
}

void parseprt(string line){
    int num = 0;
    string tok;
    for(int i = 0; i < line.size(); i++){
        if(!isalpha(line[i])) continue;
        tok += line[i];
        if(!isalpha(line[i+1]) || ((i+1)==line.size())){
            word[num++] = tok;
            tok.clear();
        }

    }
    for(int i = num-1; i >= 0; i--){
        cout << word[i] << " " ;
    }
    cout << endl;

}
