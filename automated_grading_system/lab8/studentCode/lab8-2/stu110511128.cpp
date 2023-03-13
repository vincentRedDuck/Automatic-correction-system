#include<iostream>
#include<string>
using namespace std;

int main(){
 int times[52], num;
 string message;
 while(1){
  for(int i = 0; i < 52; i++){
   times[i] = 0;
  }
  cout << "Enter message: ";
  getline(cin, message);
  if(message == "Stop"){
   break;
  }
  for(int i = 0; 1; i++){
   if(message[i] == '\0'){
    break;
   }
   num = int(message[i]);
   if(num >= 'A' && num <= 'Z'){
    times[num-'A'] += 1;
   }else if(num >= 'a' && num <= 'z'){
    times[26+num-'a'] += 1;
   }
  }
  for(int i = 0; i < 52; i++){
   if(times[i] != 0){
    if(i < 26){
     cout << char('A' + i) << ": " << times[i] << endl;
    }else{
     cout << char('a' + i - 26) << ": " << times[i] << endl;
    }
   }
  }
 }
 return 0;
}
