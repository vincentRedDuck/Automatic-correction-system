#include <bits/stdc++.h>
using namespace std;

struct student{
 string ID;
 string name;
 int *score;
 int num_score;
 double average; //top 10 scores average
};

int main(int argc, char **argv){
    ifstream in_file;
    in_file.open(argv[1]);
    if(in_file.fail())cout << "ERROR in_file";
    int count=0; string s;
    while(getline(in_file, s))count++;
    in_file.close();

    in_file.open(argv[1]);
    if(in_file.fail())cout << "ERROR in_file";
    student *stu;
    string str; istringstream iss;
    stu = new student[count];

    for(int k=0; k<count; k++) {   
        getline(in_file, str);
        int temp=0;
        double avg=0;
        iss.str(str);
        iss >> stu[k].ID >> stu[k].name >> stu[k].num_score;
        stu[k].score = new int[stu[k].num_score];
        for(int i=0; i<stu[k].num_score; i++){
            iss >> stu[k].score[i];
        }
        if(stu[k].num_score > 10){
            int mtx[stu[k].num_score];
            for(int l=0; l<stu[k].num_score; l++){
                mtx[l] = stu[k].score[l];
            }
            for(int i=0; i<stu[k].num_score; i++){
                for(int j=0; j<stu[k].num_score; j++){
                    if(mtx[i] > mtx[j]){
                        temp = mtx[i];
                        mtx[i] = mtx[j];
                        mtx[j] = temp;
                    }
                }
            }
            for(int i=0; i<10; i++){
                avg += mtx[i];
            }
            stu[k].average = avg/10;
        }
        else{
            for(int i=0; i<stu[k].num_score; i++){
                avg += stu[k].score[i];
            }
            stu[k].average = avg/stu[k].num_score;
        }
        iss.clear();
    }

    for(int i=0; i<count; i++){
        cout << stu[i].ID << " " << stu[i].name << " ";
        for(int j=0; j<stu[i].num_score; j++){
            cout << stu[i].score[j] << " ";
        }
        cout << stu[i].average << endl;
    }

    double dev=0, avg=0, temp=0;
    for(int i=0; i<count; i++){
        avg+=stu[i].average;
    }
    avg = avg/count;
    for(int i=0; i<count; i++){
        temp+=(stu[i].average-avg)*(stu[i].average-avg);
    }
    dev = pow(temp/count, 0.5);
    cout << dev << endl;
    in_file.close();
    return 0;
}
