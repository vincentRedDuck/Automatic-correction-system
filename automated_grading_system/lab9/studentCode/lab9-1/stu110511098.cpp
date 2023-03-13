#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
int main(int argc,char *argv[]){
        ifstream in_file;
        in_file.open(argv[1]);

        string textline;
        int arr[10000];int j=0;double sum=0.0;
        while(getline(in_file,textline,'\n')){
            textline.erase(0,textline.find(':')+1);
            if(textline==""){
                arr[j]=0;
            }
            else{
                arr[j]=stoi(textline);
            }
            //cout<<arr[j]<<"\n"<<j<<endl;
            j++;
        }
        for(int k=0;k<=j;k++){
            sum+=arr[k];
        }
        double avg=sum/(j);
        ofstream out_file(argv[2]);
        out_file <<"The average is: "<<fixed<<setprecision(4)<<avg;
    
    in_file.close();
    out_file.close();
    return 0;
}
