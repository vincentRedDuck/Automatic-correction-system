#include <bits/stdc++.h>

using namespace std;

int main() {
  string a;
  while (1) {
    printf ("Enter message: ");
    getline(cin, a);
    if (a == "Stop") {
      return 0;
    }

    vector<int> x(70, 0);

    for (int i = 0; i <= a.length(); ++i) {
      if (!(isalpha(a[i]))) {
        continue;
      }
      int tmp = int(a[i]) - 65;
      x[tmp]+=1;
    }

    for (int i = 0; i < 70; ++i) {
      if (x[i] != 0) {
        printf ("%c: %d\n", char(int(65 + i)), x[i]);
      }
    }
  }
}
