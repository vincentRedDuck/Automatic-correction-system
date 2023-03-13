#include<iostream>
#include<iomanip>
using namespace std;

void encode(char input[100],int size);
void decode(char input[100],int size);

int main()
{
    int mode;
    cout<<"1: encoder 2: decoder 3: quit: ";
    cin>>mode;
    while(mode!=3)
    {
        if((mode==1)||(mode==2))
        {
            int size;
            cout<<"Please enter sentences length: ";
            cin>>size;
            char input[size];
            cin>>input;
            if(mode==1)
            {
                encode(input,size);
            }
            else if(mode==2)
            {
                decode(input,size);
            }
        }
        else
        {
            cout<<"invalid input"<<endl;
        }
        cout<<endl;
        cout<<"1: encoder 2: decoder 3: quit: ";
        cin>>mode;
    }
    return 0;
}

void encode(char input[100],int size)
{
    int l2=size/2;
    char s2[l2];
    int l1=(size%2==0) ? l2 : l2+1;
    char s1[l1];

    for(int i=0;i<size;i++)
    {
        if(i%2==0)
        {
            s1[i/2]=input[i];
        }
        else
        {
            s2[(i-1)/2]=input[i];
        }
    }
    
    for(int i=0;i<l1;i++)
    {
        cout<<s1[i];
    }
    for(int i=0;i<l2;i++)
    {
        cout<<s2[i];
    }
    cout<<endl;
}

void decode(char input[100],int size)
{
    char result[size];
    int l2=size/2;
    int l1=(size%2==0) ? size/2 : size/2+1;
    for (int i=0;i<size;i++)
    {
        if(i<l1)
        {
            result[2*i]=input[i];
        }
        else
        {
            int j=i-l1;
            result[2*j+1]=input[i];
        }
    }

    for(int i=0;i<size;i++)
    {
        cout<<result[i];
    }
    cout<<endl;
    
}
