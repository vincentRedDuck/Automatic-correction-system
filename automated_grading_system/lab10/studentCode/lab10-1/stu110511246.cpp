#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char *argv[]){
    ifstream infile;
    ofstream outfile;
    infile.open(argv[1]);
    string line;
    outfile.open(argv[2]);
    outfile<<"====="<<endl;
    while(getline(infile,line)){
            int q=line.find("/");
            line.erase(0,q+2);
            int a=line.find("/");
            int k=line.rfind("/");
            int b=line.find("?");
            int c=line.find("=");
            int j=line.rfind("=");
            int d=line.find("&");
            
            outfile<<"Domain name: "<<line.substr(0,a)<<endl;
            outfile<<"Method: "<<line.substr(k+1,b-k-1)<<endl;
            if(line.substr(c+1,d-c-1) != "")
                outfile<<line.substr(b+1,c-b-1)<<": "<<line.substr(c+1,d-c-1)<<endl; 
                cout<<line.substr(b+1,c-b-1)<<": "<<line.substr(c+1,d-c-1)<<endl; 
           
            /*while(c<=j){
                    if(line[c+1]=='\n'){
                        continue;
                    }
                    outfile<<line.substr(c+1,d-c-1)<<":";
                   // d=line.find("&",d+1);
                    outfile<<line.substr(d+1,c-d-1)<<endl;
                    if(c==j)
                    break;
                    c=line.find("=",c+1);
                    //d=line.find("&",d+1);
            }*/
           while(c<j){
                c=line.find("=",c+1);
                int last_d = d;
                //outfile<<line.substr(d+1,c-d-1)<<": ";
                cout<<line.substr(d+1,c-d-1)<<": ";
                d=line.find("&",d+1);
                
                //outfile<<line.substr(c+1,d-c-1)<<endl;
                cout<<line.substr(c+1,d-c-1)<<endl;
                if(line.substr(c+1,d-c-1) != ""){
                    outfile<<line.substr(last_d+1,c-last_d-1)<<": ";
                    outfile<<line.substr(c+1,d-c-1)<<endl;
                
                }

            }
            outfile<<"====="<<endl;
    }
    infile.close();
    outfile.close();

}
