#include <bits/stdc++.h>
using namespace std;
void insertionsort(int *score,int num,int *scoresort){
    int i,j;
    int key;
    for(i=0;i<num;i++)
        scoresort[i]=score[i];
    for (j=1; j<num; j++)
    {
        key = scoresort[j];
        i = j-1;
        while (i>=0 && scoresort[i]>key)
        {
            scoresort[i+1] = scoresort[i];
            --i;
        }
        scoresort[i+1] = key;
    }
}

struct student{
    string id;
    string name;
    int num_score;
    int *score;
    double average;
};
int main (int argc, char **argv){
    ifstream fin(argv[1]);
    //student *arr = new student;
    int count=0;
    int *scoresort = new int;
    double sum;
    string line,tok;
    while(getline(fin,tok))
    {
        count++;
    }
    fin.close();
    fin.open(argv[1]);
    double *average = new double[count];
    int i=0;
    double sumaverage;
    double Z;
    double S;
    int index;
    for(int i =0;i<count;i++)
      average[i]=0;

    index=0;
    while (getline(fin,line))
    {
    student *arr = new student;
        sum = 0;
        istringstream iss;
        iss.str(line);
        iss >> arr->id >> arr->name >> arr->num_score;
        arr->score = new int[arr->num_score];
        for(int i=0; i<arr->num_score; i++)
        {
            iss >> arr->score[i];
        }
        if(arr->num_score<=10)
        {
            for(int i=0;i<arr->num_score;i++) sum += arr->score[i];
            arr->average = sum/arr->num_score;

        }
        if(arr->num_score>10)
        {
            scoresort = new int[arr->num_score];
            insertionsort(arr->score,arr->num_score, scoresort);
            //cout << "DD = " << arr->num_score << " " ;
            for(int i=arr->num_score-1; i>=arr->num_score-10;i--)
            {    
             //   cout << scoresort[i] << " ";
                sum+=scoresort[i];
                arr->average = sum/10;
            }
            //cout << endl;
        }
        average[index] = arr->average;
        
        cout<<arr->id<<" "<<arr->name<<" ";
        for(int i=0;i<arr->num_score; i++)
          cout<<arr->score[i]<<" ";

        cout<<average[index]<<endl;
        index++;
        
    }
    for(int i=0;i<count;i++)
    {
       sumaverage+= average[i];
    }
    sumaverage/=count;
    
    for(int i = 0; i<count;i++)
    {
        Z+=pow((average[i] - sumaverage),2);
    }
    Z/=count;
    cout<<sqrt(Z)<<endl;


    return 0;
}
