#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

void cut_func(string in,string& out,int pos,int end)
{     
    int l=pos-end+1;
    out+=in.substr(pos,l);
}

void mark(int head[],int tail[],string in,int& head_l,int& tail_l)
{
    int l=in.length();
    int id_tail=0;
    for(int i=l-1;i>=1;i--)//mark tail
    {
        int a=in[i-1];
        int b=in[i];
        
        if((i==l-1)&&(isalpha(b)))
        {
            tail[id_tail]=i;
            id_tail+=1;
        }
        
        else if((!isalpha(b))&&(isalpha(a)))
        {
            tail[id_tail]=i-1;
            id_tail+=1;
        }
    }

    tail_l=id_tail;

    int id_head=0;
    for(int i=l-2;i>=0;i--)//mark head
    {
        int b=in[i];
        int c=in[i+1];

        if((i==0)&&(isalpha(b)))
        {
            head[id_head]=i;
            id_head+=1;
        }
        else if((!isalpha(b))&&(isalpha(c)))
        {
            head[id_head]=i+1;
            id_head+=1;
        }
    }

    head_l=id_head;
}

void grow(string in,string& out,int head[],int tail[],int l)
{
    for(int i=0;i<l;i++)
    {
        int pos=head[i];
        int end=tail[i];
        int sample_l=end-pos+1;
        out+=in.substr(pos,sample_l);

        if(i!=l-1)
        {
            out+=" ";
        }        
    }
}


int main()
{
    string input;
    cout<<"Enter the sentence: ";
    getline(cin,input);
    
    while(input!="Stop the program")
    {
        int l=input.length();

        string output="";
        int head[l];
        int tail[l];
        int head_l;
        int tail_l;
        
        mark(head,tail,input,head_l,tail_l);
        
        /*for (int i=0;i<head_l;i++)
        {
            cout<<head[i]<<" ";
        }

        cout<<endl;

        for(int i=0;i<tail_l;i++)
        {
            cout<<tail[i]<<" ";
        }

        cout<<endl;*/
        
        grow(input,output,head,tail,head_l);
        
        int idx=output.length();
        for(int i=0;i<idx;i++)
        {
            cout<<output[i];
        }
        cout<<endl;
        
        cout<<"Enter the sentence: ";
        getline(cin,input);     
    }    

    return 0;
}
