#include <bits/stdc++.h>

using namespace std;

vector <string> en;
vector <string> zh;

int find_poke(string s) {
  for (int i = 0; i < en.size(); ++i) {
    if (s == en[i]) {
      return i;
    }
  }
  return -1;
}

int main(int a, char *b[]) {
  char *file1 = b[1];
  char *file2 = b[2];
  char *file3 = b[3];
  char *file4 = b[4];
  ifstream fin(file1);
  ofstream fout;
  fout.open(file2, ios::trunc);
  string s;
  int i = 0;
  string l = "";
  while (fin >> s) {
    if (i == 1) {
      zh.push_back(s);
      i = 0;
    }
    else if (isalpha(s[0])) {
      en.push_back(s);
      i = 1;
    }
  }

  for (int j = 0; j < en.size(); ++j) {
    fout << setw(3) << setfill('0') << j + 1;
    fout << " " << en[j] << " " << zh[j] << endl;
  }
  fin.close();
  fout.close();
  fin.open(file3);
  vector <int> cnt (1000, 0);
  string n;
  while (fin >> n) {
    if (isdigit(n[0])) {
      int x = stoi(n);
      ++cnt[x - 1];
    }
    else {
      int x = find_poke(n);
      ++cnt[x];
    }
  }
  fout.open(file4, ios::trunc);
  for (int i = 0; i < 1001; ++i) {
    if (cnt[i] != 0) {
      fout << i + 1 << " " << en[i] << endl;
    }
  }
}
