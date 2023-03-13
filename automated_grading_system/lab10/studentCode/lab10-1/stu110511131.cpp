#include <bits/stdc++.h>

using namespace std;

string cut(string s, int a, int b) {
  string ans = "";
  for (;a < b; ++a) {
    ans += s[a];
  }
  return ans;
}

int main(int a, char *b[]) {
  char *file1 = b[1];
  char *file2 = b[2];
  ifstream fin(file1);
  ofstream fout;
  fout.open(file2, ios::trunc);
  string s1;
  while (getline(fin, s1, '\n')) {
    vector <string> v1;
    vector <string> v2;
    stringstream ss1;
    string s2;
    int m = s1.find("/", 8);
    int n = s1.find(":") + 3;
    int p = s1.find("?", n);
    int q = s1.find_last_of("/");
    string domain = cut(s1, n, m);
    string method = cut(s1, q + 1, p);
    s2 = cut(s1, p + 1, s1.size());
    ss1 << s2;
    string s3;
    while (getline(ss1, s3, '&')) {
      stringstream ss2;
      ss2 << s3;
      string s4;
      int i = 1;
      while (getline(ss2, s4, '=')) {
        if (i == 1) {
          v1.push_back(s4);
          v2.push_back("");
        }
        else v2[v1.size() - 1] = s4;
        ++i;
      }
    }
    fout << "=====" << endl;
    fout << "Domain name: " << domain << endl;
    fout << "Method: " << method << endl;
    for (int i = 0; i < v2.size(); ++i) {
      if (v2[i] != "") {
        fout << v1[i] << ": " << v2[i] << endl;
      }
    }
  }
  fin.close();
  fout << "=====" << endl;
}
