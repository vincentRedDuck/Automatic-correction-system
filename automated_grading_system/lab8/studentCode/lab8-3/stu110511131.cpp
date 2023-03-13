#include <bits/stdc++.h>

using namespace std;

int delimiter(string a, int s) {
  for (int i = s; i < a.length(); ++i) {
    if (!(isalpha(a[i]))) {
      return i;
    }
  }
  return a.length();
}

bool check(string a) {
  for (int i = 0; i < a.length(); ++i) {
    if (isalpha(a[i])) return false;
  }
  return true;
}

int main() {
  while (1) {
    vector <string> v1;
    string a;
    int s = 0;
    int t = 0;
    cout << "Enter the sentence: ";
    getline(cin, a);
    if (check(a)) {
      cout << endl;
      continue;
    }
    if (a == "Stop the program") {
      return 0;
    }
    while (t < a.length()) {
      string tmp = "";
      t = delimiter(a, s) + 1;
      for(int i = s; i < t - 1; ++i) {
        tmp = tmp + a[i];
      }
      v1.insert(v1.begin(), tmp);
      s = t;
    }
    for (int i = 0; i < v1.size(); ++i) {
      cout << v1[i];
      if (i == v1.size() - 1) {
        cout << "\n";
      }
      else if (v1[i] != "") cout << " ";
    }
  }
}
