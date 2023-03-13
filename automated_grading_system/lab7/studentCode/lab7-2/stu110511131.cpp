#include <bits/stdc++.h>

using namespace std;

void encoder() {
  double l;
  string str;
  cin >> l;
  cin >> str;
  for (int i = 0; i < l; i += 2) {
    cout << str[i];
  }
  for (int i = 1; i < l; i += 2) {
    cout << str[i];
  }
  cout << "\n\n";
}

void decoder() {
  double l;
  string str, ans;
  cin >> l;
  cin >> str;
  for (int i = 0; i < ceil(l / 2); ++i) {
    cout << str[i] << str[ceil(l / 2) + i];
  }
  cout << "\n\n";
}

int main() {
  int c;
while (1){
    printf ("1: encoder 2: decoder 3: quit: ");
    cin >> c;
    if (c == 1) {
      printf ("Please enter sentences length: ");
      encoder();
    }
    else if (c == 2) {
      printf ("Please enter sentences length: ");
      decoder();
    }
    else if (c == 3) {
      break;
    }
    else {
      printf ("invalid input\n\n");
    }
  }
}
