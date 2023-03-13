#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int* sort(int *arr, int size){
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (key > arr[j] && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return arr;
}

struct student{
    string ID;
    string name;
    int *score;
    int num_score;
    double average; //top 10 scores average
};

int main(int argc, char *argv[]){
    string iFn = argv[1];
    ifstream iFs;
    iFs.open(iFn.c_str());

    string line;
    int MAX = 20;
    int count = 0;//index of the recent student 
    student* list = new student [MAX];//total list
    while(getline(iFs, line)){
        
        //expanding the list by 20 when needed
        if(count >= MAX){
            MAX += 20;
            student *tmp = new student [MAX];
            for (int i=0; i < MAX - 20 -1; i++){
                tmp[i] = list[i]; 
            }
            delete [] list;
            list = tmp;
        }

        //entering the data
        stringstream input(line);
        input >> list[count].ID >> list[count].name >> list[count].num_score;

        //define the score array
        list[count].score = new int [list[count].num_score];
        for (int i=0; i < list[count].num_score; i++){
            input >> list[count].score[i];
        }
    
       
        cout << list[count].ID << " " << list[count].name << " ";
        for(int idxS = 0; idxS < list[count].num_score; idxS++){
            cout << list[count].score[idxS] << " ";
        }
        //sort the score from high to low
        int *sorted;
        sorted = sort(list[count].score, list[count].num_score);

        //counting the average
        double sum =0;
        int size; //size of array, which contains the top 10 scores (when number of origional scores is above or equal to 10)
        
        //assigning size
        if(list[count].num_score >= 10){
            size = 10;
        }
        else{
            size = list[count].num_score;
        }

        //adding (top 10) scores to the sum
        for(int l=0; l < size; l++){
            sum += sorted[l];
        }

        //calculating the average and save it into the list
        list[count].average = sum/size;
        //cout << sum << " " << size << endl;


        cout << list[count].average << endl;
        count++;
    }//when the while loop ends, count = number of the students that have been recorded into the list

    double SumAvg = 0;//sum of average
    double TAvg = 0;//total average
    double SDsqT = 0;//sum of square of (Avg - TAvg)
    double SD = 0;//standard deviation
    for(int p = 0; p < count; p++){
        SumAvg += list[p].average;
    }
    TAvg = SumAvg/count;
    for(int q = 0; q < count; q++){
        SDsqT += pow((list[q].average - TAvg), 2);
    }
    SD = sqrt(SDsqT/count);
    cout << SD << endl;
    return 0;    

}
