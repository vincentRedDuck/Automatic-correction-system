#include <bits/stdc++.h>

using namespace std;

int main(){
 char ch;
 cout << "Please enter a char : ";
 cin >> ch;
 
 char op;
 cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
 cin >> op;

 char dic[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E'};

 switch (op){
 case '1':
  cout << ch << endl;
  break;
 case '2':
  cout << ch-0 << endl;
  break;
 case '3':
  cout << ( ((ch-0)/8/8)%8 ? "01" : "0" ) << ((ch-0)/8)%8 << (ch-0)%8 << endl;
  break;
 case '4':
  cout << "0x" << dic[((ch-0)/16)%16] << dic[(ch-0)%16] << endl;
  break;
 default:
  cout << "No this option." << endl;
  break;
 }

}
