#include <bits/stdc++.h>

using namespace std;

struct student{
  string ID;
  string name;
  int num_score;
  int* score;
  double avg;
};

vector <student> v;

int main(int asdv, char* a[]) {
  int sn;
  ifstream fin(a[1]);
  string s;
  stringstream ss;
  while (getline(fin, s, '\n')) {
    ss << s;
    student a;
    ss >> a.ID >> a.name >> a.num_score;
//    cout << a.ID << " " << a.name << a.num_score << endl; 
    a.score = new int [a.num_score];
    double n = 0;
    double ll = 0;
    for (int i = 0; i < a.num_score; ++i) {
      ss >> a.score[i];
      ll += a.score[i];
//      cout << a.score[i];
    }
    if (a.num_score > 10) {
      int x[a.num_score];
      for (int i = 0; i < a.num_score; ++i) {
        x[i] = a.score[i];
      }
      sort(x, x + a.num_score);
      for (int i = 0; i < 10; ++i) {
        n += x[a.num_score - i - 1];
      }
      a.avg = n / 10;
    }
    else 
    a.avg = ll / a.num_score;
    v.push_back(a);
    ss.clear();
    ss.str("");
  }
  double ans, mu, tmp = 0.0;
  for (int i = 0; i < v.size(); ++i) {
    tmp += v[i].avg;
  }
  mu = tmp / v.size();
  double d = 0.0;
  for (int i = 0; i < v.size(); ++i) {
    d += (pow((v[i].avg - mu), 2));
  }
  d /= v.size();
  ans = sqrt(d);
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i].ID << " " << v[i].name << " ";
    for (int j = 0; j < v[i].num_score; ++j) {
      cout << v[i].score[j] << " ";
    }
    cout << v[i].avg << endl;
  }
  cout << ans << endl;
}
