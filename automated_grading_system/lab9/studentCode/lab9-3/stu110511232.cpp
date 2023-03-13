#include<iostream>
#include<fstream>
#include<iomanip>
#include<cctype>
#include<cstring>
using namespace std;

struct morse
{
    char letter;
    string code;
};

void encode(ifstream &in_file,ofstream &out_filemorse,morse dict[]);
void decode(ifstream &in_file,ofstream &out_file,morse dict[]);

void make_dict(morse dict[],ifstream &in_file)
{
    string input;
    for(int i=0;i<36;i++)
    {
        getline(in_file,input);
        int l=input.length();
        char ch=input[0];
        string line=input.substr(2,l-2);
        morse item={ch,line};
        dict[i]=item;
        input.clear();
    }
}

void prt_dict(morse dict[])
{
    for(int i=0;i<36;i++)
    {
        cout<<dict[i].letter<<" "<<dict[i].code<<endl;
    }
}

int main(int argc,char* inp[])
{
    ifstream in_file;
    ifstream in_dict;
    ofstream out_file;
    char mode;
    
    in_dict.open("code.txt");
    if(in_dict.fail())
    {
        cout<<"dict error"<<endl;
        exit(1);
    }
    in_file.open(inp[1]);
    out_file.open(inp[2]);
    mode=inp[3][0];
    
    morse dict[36];
    make_dict(dict,in_dict);
    //prt_dict(dict);

    char ch;
    if(mode=='e')
    {
        encode(in_file,out_file,dict);
    }
    else if(mode=='d')
    {
        decode(in_file,out_file,dict);
    }

    //prt_dict(dict);

    in_file.close();
    out_file.close();
    return 0;
}

void encode(ifstream &in_file,ofstream &out_file,morse dict[])
{
    string sen;
    while(getline(in_file,sen))
    {
        //cout<<sen;//test input
        int l=sen.length();
        for(int i=0;i<l;i++)
        {
            char c=sen[i];
            if((isalpha(c))||(isdigit(c)))
            {
                string out;
                int l_dict=36;
                
                for(int j=0;j<l_dict;j++)
                {
                    if(dict[j].letter==c)
                    {
                        out=dict[j].code;
                        out_file<<out;
                        //cout<<dict[i].code;//test
                        break;
                    }
                }
                
                if((i!=l-1))
                {
                    if((isalpha(sen[i+1]))||(isdigit(sen[i+1])))
                    {
                        out_file<<"   ";
                        //cout<<"   ";//test
                    }
                }
            }
            else if(c==' ')
            {
                for(int k=0;k<7;k++)
                {
                    out_file<<" ";
                    //cout<<"       ";//test
                }
            }
        }

        out_file<<endl;
        //cout<<endl;//test

        sen.clear();
    }
}

void decode(ifstream &in_file,ofstream &out_file,morse dict[])
{
    string sen;
    while(getline(in_file,sen))
    {
        int sen_l=sen.length();
        int head[sen_l];
        int tail[sen_l];
        int i_h=0;
        int i_t=0;

        for(int i=1;i<sen_l-1;i++)
        {
            if(sen[i]==' ')
            {
                if(sen[i-1]!=' ')
                {
                    head[i_h]=i;
                    i_h++;  
                }
                if(sen[i+1]!=' ')
                {
                    tail[i_t]=i;
                    i_t++;
                }
            }
        }

        int h_l=i_h;
        int t_l=i_t;

        /*cout<<"head: ";
        for(int i=0;i<h_l;i++)//print index of spaces
        {
            cout<<head[i]<<" ";
        }
        cout<<endl;

        cout<<"tail: ";
        for(int i=0;i<t_l;i++)
        {
            cout<<tail[i]<<" ";
        }
        cout<<endl;*/

        int beg=0;
        for(int i=0;i<h_l;i++)
        {
            int sp_l=tail[i]-head[i]+1;
            int str_l=head[i]-beg;
            string out=sen.substr(beg,str_l);
            
            for(int i=0;i<36;i++)
            {
                if(dict[i].code==out)
                {
                    out_file<<dict[i].letter;
                    cout<<dict[i].letter;
                    break;
                }
            }

            if(sp_l==7)
            {
                    out_file<<" ";
                    cout<<" ";

            }

            beg=tail[i]+1;
        }

        string final_ch=sen.substr(beg,sen_l-beg);
        for(int i=0;i<36;i++)
        {
            if(dict[i].code==final_ch)
            {
                out_file<<dict[i].letter;
                cout<<dict[i].letter;
                break;
            }
        }

        out_file<<endl;
        cout<<endl;
    }
}

