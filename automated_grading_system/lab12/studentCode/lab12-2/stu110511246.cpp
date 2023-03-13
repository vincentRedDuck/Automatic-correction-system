#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;
//const int max=20;
bool cmp(int a,int b){
    return a>b;
}
struct student{
    string id;
    string n;
    int num;
    int *sc;
    double avg;
};
int main(int argc,char *argv[]){
    int max=20; 

    ifstream fin;
    fin.open(argv[1]);

    student *s = new student[max];
    string line;
    int k = 0;

    while(getline(fin, line)){
        if(k==max-1){
            student *s2 = new student[max];
            for(int i=0;i<k;i++){
                s2[i]=s[i];
            }
            delete [] s;
            s=s2;
        }
        stringstream ll(line);
        ll>>s[k].id>>s[k].n>>s[k].num;
        cout << s[k].id  << " " << s[k].n << " " ;
        int j=0;
        s[k].sc=new int[max];
        while(ll>>s[k].sc[j]){
            if(j==max-1){
                int *sc2=new int[max];
                for(int i=0; i<j; i++){
                    sc2[i]=s[k].sc[i];
                }
                delete [] s[k].sc;
                s[k].sc=sc2;
            }
            cout<<s[k].sc[j]<<" ";
            j++;
        }

        sort(s[k].sc, s[k].sc+j, cmp);
        int sum=0;
        for(int i=0;i<((j<=10)?j:10);i++){
            sum += s[k].sc[i];
        }
        s[k].avg = sum*1.0 / ((j<=10)?j:10);
        cout  << s[k].avg << endl;
        k++;
    }
    double suma=0;
    for(int i=0;i<k;i++){
        suma+=s[i].avg;

    }
    double m=suma/k;
    double sumsd=0;

    for(int i=0;i<k;i++){
        sumsd+=(s[i].avg-m)*(s[i].avg-m);
    }
    double sd=sqrt(sumsd/k);
    cout<<sd<<endl;
    return 0;
}

