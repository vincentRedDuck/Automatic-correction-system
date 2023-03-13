#include <bits/stdc++.h>

using namespace std;

int find_num(string s) {
  string a = "";
  for (int i = 1; i < s.size(); ++i) {
    if (isdigit(s[i])) {
      a += s[i];
    }
  }
  if(a == "") {
    return 0;
  }
  int num = stoi(a);
  return num;
}

int main(int a, char *arg1[]) {
  char *file1 = arg1[1];
  char *file2 = arg1[2];
  ifstream fin(file1);
  ofstream fout;
  fout.open(file2, ios::trunc);
  vector <string> v1;
  vector <int> v2;
  string s;
  while (getline(fin, s, '\n')) {
    v1.push_back(s);
  }
  fin.close();
  for (int i = 0; i < v1.size(); ++i) {
    int a = find_num(v1[i]);
    v2.push_back(a);
  }
  double sum = 0;
  for (int i = 0; i < v2.size(); ++i) {
    sum += v2[i];
  }
  sum /= v2.size();
  fout << "The average is: " << fixed << setprecision(4) << sum;
  fout.close();
  return 0;
}
