#include <bits/stdc++.h>

using namespace std;

int main() {
  int a1, a2, b1, b2;
  char c;
  while (1) {
    printf ("Enter first point:");
    cin >> c >> a1 >> c >> a2 >> c;
    printf ("Enter second point:");
    cin >> c >> b1 >> c >> b2 >> c;
    double x = pow((a1 - b1), 2);
    double y = pow((a2 - b2), 2);
    double ans = sqrt(x + y);
    if (ans == 0) {
      break;
    }
    cout << "Distance: " << ans << endl;
  }
}
