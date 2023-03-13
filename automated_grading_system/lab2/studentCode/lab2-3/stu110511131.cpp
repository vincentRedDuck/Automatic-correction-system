#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  char input;
  int selection;

  cout << "Please enter a char : ";
  cin >> input;
  cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
  cin >> selection;
  
  int ascii = (int)input;

  if (selection == 1) cout << input << endl;

  else if (selection == 2) 
    cout << ascii << endl;

  else if (selection == 3) 
    cout << "0" << oct << ascii << endl;

  else if (selection == 4) 
    cout << hex << showbase << ascii <<endl;

  else cout << "No this option." << endl;

  return 0;

}
