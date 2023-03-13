
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv){
    string s,s3,s4;
    char ch;

    string s1;
    //string s1[3];

    string s2;
    //string s2[8];

    int i=0;
    int j=0;
    int pos;
    int pos2;
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    fout<<"====="<<endl;

        //fin.ignore(50,'/');
        //fin.ignore(8,'/');

    while (getline(fin,s))
    {

        /*fin.ignore(50,'/');
        fin.ignore(8,'/');
        getline(fin,s);*/

        stringstream x(s);

        x.ignore(50,'/');//*
        x.ignore(8,'/');//*

        getline(x,s1,'/');
        fout<<"Domain name: "<<s1<<endl;


        getline(x,s1,'?');
        s1.erase(0,s1.rfind('/')+1);//erase(開始位置,擦去字元數)
        fout<<"Method: "<<s1<<endl;


        while(getline(x,s1,'='))
        {

            /*if(strlen(s2[j].c_str())>2)
            {
                stringstream y(s2[j]);
                getline(getline(y,s3,'='),s4);
                fout<<s3<<": "<<s4;
                j++;
                fout<<endl;
            }*/


            getline(x,s2,'&');
            if(s2.length()>0)fout<<s1<<": "<<s2<<endl;


       }

       fout<<"====="<<endl;

     //fin.ignore(50,'/');
     //fin.ignore(8,'/');

    }

    return 0;
}/*#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv){
    string s,s3,s4;
    char ch;
    string s1[3];
    string s2[8];
    int i=0;
    int j=0;
    int pos;
    int pos2;
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    fout<<"====="<<endl;
       fin.ignore(50,'/');
        fin.ignore(8,'/');
while (getline(fin,s))
    {   
        //fin.ignore(50,'/');
        //fin.ignore(8,'/');
        //getline(fin,s);
        stringstream x(s);
        getline(x,s1[i],'/');
        fout<<"Domain name: "<<s1[i]<<endl;
        i++;

        getline(x,s1[i],'?');
        pos = s1[i].length();
        pos2=s1[i].rfind('/',pos);
        s1[i]=s1[i].substr(pos2+1,pos-pos2);
        
       // s1[i].erase(0,s1[i].rfind('/'));
        
        fout<<"Method: "<<s1[i]<<endl;
        
        i=0;

       while(getline(x,s2[j],'&'))
        {   
            if(strlen(s2[j].c_str())>2)
            {
                stringstream y(s2[j]);
                getline(getline(y,s3,'='),s4);
                fout<<s3<<": "<<s4;
                j++;
                fout<<endl;
            }
        }

        fout<<"====="<<endl; 
        fin.ignore(50,'/');
        fin.ignore(8,'/');

    }

    return 0;
}*/
