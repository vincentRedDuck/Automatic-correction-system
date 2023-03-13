#include <bits/stdc++.h>

using namespace std;

int make_arr (int &odd, int &even, bool &flag,int num) {
    int k;
    if (flag) {
      k = even;
      even += 2;
    }
    else {
      k  = odd;
      odd += 2;
    }
    if (odd > num * num) flag = true;
    return k;
} 

int main() {
  int num;
  for (;;) {
    cin >> num;
    if (num == -1) return 0;
    int** arr = new int* [num];
    for (int i = 0; i < num; ++i) {
      arr[i] = new int [num];
    }
    bool flag = false;
    int odd = 1;
    int even = 2;
    int i = 0;
    int j = 0;
    int s = 1;
    int t = 0;
    int a = 0, b = 0, c = 0, d = 0;
    for (int l = 0; l < num * num;) {
      for (; i < num - (s / 4); ++i) {
        arr [i][j] = make_arr(odd, even, flag, num);
//        cout << make_arr(odd, even, flag, num);
        ++l;
      }
      s++;
      i--;
      j++;
      for (; j < num - (s / 4); ++j) {
  //      cout << make_arr(odd, even, flag, num);
        arr [i][j] = make_arr(odd, even, flag, num);
        ++l;
      }
      j--;
      i--;
      s++;
      for (; i >= 0 + (s / 4); i--) {
    //    cout << make_arr(odd, even, flag, num);
        arr [i][j] = make_arr(odd, even, flag, num);
        ++l;
      }
      i++;
      j--;
      s++;
      for (; j >= 0 + (s / 4); j--) {
      //  cout << make_arr(odd, even, flag, num);
        arr [i][j] = make_arr(odd, even, flag, num);
        ++l;
      }
      t++;
      i++;
      j++;
      s++;
    }
    for (int i = 0; i < num; ++i) {
      for (int j = 0; j < num; ++j) {
        cout << setw(5) << right << arr[j][i];
      }
      cout << endl;
    }
  }
}
