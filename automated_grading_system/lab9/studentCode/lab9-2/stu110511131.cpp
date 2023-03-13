#include <bits/stdc++.h>

using namespace std;

vector <double> avg;

void calc_avg (vector <string> v) {
  for (int i = 0; i < v.size(); ++i) {
    vector <string> n;
    string s = v[i];
    string temp = "";
    for (int t = 0; t < s.size(); ++t) {
      if (s[t] == ' ' && temp != "") {
        n.push_back(temp);
        temp = "";
      }
      if (isdigit(s[t])) {
        temp += s[t];
      }
      if(t == s.size() - 1) {
        n.push_back(temp);
      }
    }
    double sum = 0;
    for (int j = 0; j < n.size(); ++j) {
      sum += stoi(n[j]);
    }
    sum /= n.size();
    avg.push_back(sum);
  }
}

void sort_name(char *a, char *b) {
  ifstream fin(a);
  ofstream fout;
  string s;
  vector <string> l;
  while (getline(fin, s, '\n')) {
    if(!isdigit(s[0])) {
      l.push_back(s);
    }
    s = "";
  }
  calc_avg(l);
  for (int i = 0; i < l.size() * l.size(); ++i) {
    for (int j = 0; j < l.size() - 1; ++j) {
      if (l[i] < l[i + 1]) {
        swap(avg[j], avg[j + 1]);
        string temp = l[j];
        l[j] = l[j + 1];
        l[j + 1] = temp;
      }
    }
  }
  fout.open(b, ios::trunc);
  for (int i = 0; i < l.size(); ++i) {
    fout << l[i] << " " << fixed << setprecision(4) << avg[i] << "\n";
    fout.flush();
  }
  fin.close();
  fout.close();
}

void sort_avg(char *a, char *b) {
  ifstream fin(a);
  ofstream fout;
  string s;
  vector <string> l;
  while (getline(fin, s, '\n')) {
    if(!isdigit(s[0])) {
      l.push_back(s);
    }
  }
  calc_avg(l);
  for (int i = 0; i < l.size() * l.size(); ++i) {
    for (int j = 0; j < l.size() - 1; ++j) {
      if (avg[j] > avg[j + 1]) {
        swap(avg[j], avg[j + 1]);
        string temp = l[j];
        l[j] = l[j + 1];
        l[j + 1] = temp;
      }
    }
  }
  fout.open(b, ios::trunc);
  for (int i = 0; i < l.size(); ++i) {
    fout << l[i] << " " << fixed << setprecision(4) << avg[i] << "\n"; 
    fout.flush();
  }
  fin.close();
  fout.close();
}

int main(int a, char *argv[]) {
  char *file1 = argv[2];
  char file2[100];
  if (a == 4) {
    strcpy(file2, argv[3]);
  }
  else {
    strcpy(file2, argv[2]);
    strcat(file2, ".out");
  }

  if (!strcmp(argv[1], "1")) {
    sort_avg(file1, file2);
  }
  else {
    sort_name(file1, file2);
  }
}
