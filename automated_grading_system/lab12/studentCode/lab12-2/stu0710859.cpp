#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

struct student{
    string ID;
    string name;
    int *score;
    int num_score;
    double average;
};

int main(int argc, char* argv[]){
    ifstream file1;
    string inf = argv[1];
    file1.open(inf);
    
    int i = 0, j, k, p, num = 0, tmp;
    double avg = 0, std = 0, s = 0;
    string temp;
    
    while(getline(file1, temp)){
        num++;
    }
    file1.close();
    
    file1.open(inf);
    student* stu = new student[num];
    while(getline(file1, temp)){
        p = temp.find(' ');
        stu[i].ID = temp.substr(0,p);
        temp.erase(0,p+1);
        p =temp.find(' ');
        stu[i].name = temp.substr(0,p);
        temp.erase(0,p+1);
        p = temp.find(' ');
        cout << stu[i].ID << " " << stu[i].name << " ";
        stu[i].num_score = stoi(temp.substr(0,p));
        stu[i].average = 0;
        stu[i].score = new int [stu[i].num_score];
        temp.erase(0,p+1);
        for(j = 0; j < stu[i].num_score-1; j++){
            p = temp.find(' ');
            stu[i].score[j] = stoi(temp.substr(0,p));
            temp.erase(0,p+1);
            cout << stu[i].score[j] << " ";
        }
        p = temp.length();
        stu[i].score[stu[i].num_score-1] = stoi(temp.substr(0,p));
        cout << stoi(temp.substr(0,p)) << " ";
        for(j = 0; j < stu[i].num_score-1; j++){
            for(k = j+1; k < stu[i].num_score; k++){
                if(stu[i].score[j] < stu[i].score[k]){
                    tmp = stu[i].score[j];
                    stu[i].score[j] = stu[i].score[k];
                    stu[i].score[k] = tmp;
                }
            }
        }
        if(stu[i].num_score > 10){
            for(j = 0; j < 10; j++){
                stu[i].average += stu[i].score[j];
            }
            stu[i].average /= 10;
            avg += stu[i].average;
            cout << stu[i].average;
        }
        else{
            for(j = 0; j < stu[i].num_score; j++){
                stu[i].average += stu[i].score[j];
            }
            stu[i].average /=stu[i].num_score;
            avg += stu[i].average;
            cout << stu[i].average;
        }
        cout << endl;
        i++;
    }
    avg /= num;
    for(i = 0; i < num; i++){
        s += (stu[i].average-avg)*(stu[i].average-avg);
    }
    s /= num;
    std = sqrt(s);
    cout << std << endl;;
    file1.close();
    return 0;
}
