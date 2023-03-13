#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double num;
  cout << "Enter a num : ";
  cin >> num;
  cout << endl;
  cout <<"123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~" << endl;

  cout << left << setw(20) << "number";
  cout << right << setw(20) << "scientific";
  cout << right << setw(20) << "signed";
  cout << right << setw(20) << "precision4" << endl;
  cout << left << setw(20) << fixed << setprecision(6) << num;
  cout << right << setw(20) << uppercase << scientific << num;
  if (num >= 0)
     cout << right << setw(20) << showpos << fixed << setprecision(6) << num;
  if (num < 0) cout << right << setw(20) << fixed << setprecision(6) << num;

  cout << right << setw(20) << noshowpos << fixed << setprecision(4) << num << endl;
}
