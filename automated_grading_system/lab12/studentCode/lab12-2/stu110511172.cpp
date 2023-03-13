#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;
struct student{
 string ID;
 string name;
 int *score;
 int num_score;
 double average; //top 10 scores average
};

student *New1DArray(const int);
void Display1DArray(student *,const int);
double getavg(int *,int);
void Delete1DArray(student *);



int main(int argc,char **argv)
{
    ifstream fin(argv[1]);
    int n;
    string x;
    while(getline(fin,x)){
        n++;
    }
    fin.close();
    fin.open(argv[1]);
    //cout << n<<endl;
    student *vec = New1DArray(n);
    for(int i=0;i<n;i++){
        getline(fin,x);
    stringstream ss(x);
        //cout << x<<endl;
        ss << x;
        ss >> vec[i].ID >> vec[i].name >> vec[i].num_score;

        int *score = new int[vec[i].num_score];
        for(int j=0; j<vec[i].num_score;j++){
            ss >> score[j];
            //cout << vec[i].score[j] <<endl;
        }
        vec[i].score = score;
        vec[i].average = getavg(score,vec[i].num_score);
        ss.clear();
    }
    
    Display1DArray(vec,n);
    double sum = 0.0;
    for(int i=0;i<n;i++){
        sum += vec[i].average;
    }
    double ave = sum/n;
    sum = 0.0;
   for(int i=0;i<n;i++){
        sum += (vec[i].average-ave)*(vec[i].average);
    }
    cout << sqrt(sum/n)<< endl;
    Delete1DArray(vec);

    fin.close();
 return 0;
}
student *New1DArray(const int n)
{
    student *vec = new student[n];
    return vec;
}
double getavg(int *vec,int len)
{
    int *newscore = new int[len];
    for(int i=0;i<len;i++)
        newscore[i] = vec[i];
    for (int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(newscore[j]<newscore[j+1]&&j!=len-1){
                int temp = newscore[j];
                newscore[j] = newscore[j+1];
                newscore[j+1] = temp;
            }
        }
    }
    int t = len;
    double sum=0.0;
    if (t>10)
        t=10;
    for(int i=0;i<t;i++){
        sum += newscore[i];
    }
    return sum/t;
}
void Display1DArray(student *vec, const int n)
{
    for(int i=0; i<n ;i++){
        cout << vec[i].ID << " " << vec[i].name <<" ";
        for(int j=0; j< vec[i].num_score;j++)
            cout << vec[i].score[j] << " ";
        cout << vec[i].average << endl;
    }

}
void Delete1DArray(student *vec)
{ 
 delete []vec;
}
