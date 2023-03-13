#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
struct student{
    string id;
    string name;
    int num;
    int *sc;
    double avg;
};
int main(int argc, char *argv[]){
    int max = 20;
    int MAX = 20;
    ifstream fin;
    fin.open(argv[1]);
    student *s = new student[max];
    string line;
    int n = 0;

    while(getline(fin, line)){
        if(n == max-1){
            max *= 2;
            student *s2 = new student[max];
            for(int i=0; i<n; i++){
                s2[i] = s[i];
            }
            delete [] s;
            s = s2;
        }
        stringstream ll(line);
        ll >> s[n].id >> s[n].name >> s[n].num;
        // cout << s[n].id << s[n].name << s[n].num << endl;
        cout << s[n].id  << " " << s[n].name << " " ;
        int j = 0;
        s[n].sc = new int[MAX];
        int k = 0;
        while(ll >> s[n].sc[j]){
        //while(ll >> k){
            if(j == MAX-1){
                MAX *= 2;
                int *sc2 = new int[MAX];
                for(int i = 0; i < j; i++ ){
                    sc2[i] = s[n].sc[i];
                }
                delete [] s[n].sc;
                s[n].sc = sc2;
            }
            // cout << s[n].sc[j] << endl;
            // cout << k << endl;
            //cout << s[n].id  << " " << s[n].name << " " ;
            cout << s[n].sc[j] << " ";
            j++;
        }

        sort(s[n].sc, s[n].sc+j, cmp);
        int sum = 0;
        for(int i = 0; i < ((j<=10)?j:10); i++){
            sum += s[n].sc[i]; 
        }
        s[n].avg = sum*1.0 / ((j<=10)?j:10);
        //cout << s[n].id  << " " << s[n].name << " " ;
        cout  << s[n].avg << endl;
        n++;
    }
    //for(int i = 0; i < n; i++) 
    //    cout << s[i].avg << " ";
    //cout << endl; 
    double sumofa = 0;
    for(int i = 0; i < n; i++){
        sumofa += s[i].avg;
        
    }
    //cout << n << " " << sumofa << endl;
    double m = sumofa / n;
    double sumofsd = 0;
    
    for(int i = 0; i < n; i++){
        //sumofsd += pow((s[i].avg - m),2);
        sumofsd += (s[i].avg-m)*(s[i].avg-m);
    }
    //cout << sumofsd << endl;
    //double sd = pow(sumofsd/n, 0.5);
    double sd = sqrt(sumofsd/n);
    cout << sd << endl;
    return 0;
}
