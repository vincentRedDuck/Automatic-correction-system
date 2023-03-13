#include<iostream>
#include<string>
using namespace std;

int main(){
int len, end ,start;
cout << "Enter the sentence: ";
string sentence;
getline(cin,sentence);
while(sentence != "Stop the program"){
len = sentence.length();
end = len-1; 
start = len-1;
int i = len-1;
while(i>0){
    for(; i>=0; i--){
        if(!isalpha(sentence[i])){
            if(end!=start){
                break;
            }
            end--;
            start--;
        }
        if(isalpha(sentence[i])){
            start--;
        }
    }
    cout << sentence.substr(start+1, end-start) << ' ';
    end = start;
}
cout << "\nEnter the sentence: ";
getline(cin,sentence);
}
return 0;
}
