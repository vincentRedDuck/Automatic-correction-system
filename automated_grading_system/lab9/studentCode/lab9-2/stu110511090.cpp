#include <iostream>
#include <fstream>
#include<string>
#include <iomanip>
using namespace std;
int main(int argc, char** argv){
struct stu{
    string name;
    int s1,s2,s3;
    double avg;
};
stu data[100];
int n;
ifstream in_file(argv[2]);
in_file >> n ;
for(int i=0;i<n;i++){
in_file>>data[i].name>>data[i].s1>>data[i].s2>>data[i].s3;
data[i].avg=(data[i].s1+data[i].s2+data[i].s3)/3.0;
}
ofstream outfile;
string sOutFile;
if(argc==3) sOutFile=string(argv[2])+".out";
else sOutFile=string(argv[3]);
outfile.open(sOutFile.c_str());

for (int i=n-1;i>0;i--){
  for(int j=0;j<=i-1;j++){
    if(string(argv[1])=="1"){
      if (data[j].avg>data[j+1].avg){
        stu tmp=data[j];
        data[j]=data[j+1];
        data[j+1]=tmp;
//        cout << "-";
        }
      }
      else {
         if(data[j].name>data[j+1].name ) {
            stu tmp=data[j];
            data[j]=data[j+1];
            data[j+1]=tmp;
//            cout << ".";
            }
    

    }
  }
 }

for (int i=0;i<n;i++){
    outfile<<data[i].name << " " << data[i].s1 << " " << data[i].s2
           << " " << data[i].s3 << " " << fixed << setprecision(4) 
           << data[i].avg << endl;
}
outfile.close();
in_file.close();
return 0;
}
 
