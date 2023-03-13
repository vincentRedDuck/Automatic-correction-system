#include<iostream>
#include<string>

#include<cmath>
using namespace std;

const int size = 20;

int main(){

    string fp,sp;

    //char fp[size];
    //char sp[size];

    while(1){

        cout <<"Enter first point:";
        getline(cin,fp);

        int posfa = fp.find("(");
        int posfb = fp.find(",");
        int posfc = fp.find(")");

        int fp_1 = stoi (fp.substr(posfa+1,posfb-posfa-1)                                                                      );
        int fp_2 = stoi (fp.substr(posfb+1,posfc-posfb-1)                                                                      );

        cout <<"Enter second point:";
        getline(cin,sp);

        int possa = sp.find("(");
        int possb = sp.find(",");
        int possc = sp.find(")");

        int sp_1 = stoi (sp.substr(possa+1,possb-possa-1)                                                                      );
        int sp_2 = stoi (sp.substr(possb+1,possc-possb-1)                                                                      );


        if( ( (fp_1==0)&&(fp_2==0) )&&( (sp_1==0)&&(sp_2==0) ) ){
            break;
        }
        else{
            cout <<"Distance: ";
            int a = pow(fp_1-sp_1,2);
            int b = pow(fp_2-sp_2,2);
            cout <<sqrt(a+b) << endl;
        }




        /*cout <<fp_1 <<fp_2 << sp_1 <<sp_2 ;
        cout <<fp_1+fp_2<<endl;
        break;*/



        //cout <<fp<<endl<<sp<<endl;
        //break;



    }





return 0;
}

