#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
    int A_code=65;
    int Z_code=90;
    int a_code=97;
    int z_code=122;
    string input;
    cout<<"Enter message: ";
    getline(cin,input);

    while(input!="Stop")
    {
        int l=input.length();

        for(int i=0;i<26;i++)
        {
            int code = i+A_code;
            char letter=(char)code;
            
            int count=0;
            for(int j=0;j<l;j++)
            {
                char ch=(char)input[j];
                //cout <<"ch = "<< ch << endl;
//int abc;
//cin>>abc;
                int code=(int)ch;
                if((code>=A_code)&&(code<=Z_code))
                {
                    int adder= ((ch==letter) ? 1 : 0);
                    //cout<<ch<<" "<<letter<<endl;
                    count+=adder;
                }
            }
            
            if(count>0)
            {
                cout<<letter<<": "<<count<<endl;
            }            
        }

        for(int i=0;i<26;i++)
        {
                int code = i+a_code;
                char letter=(char)code;
   
                int count=0;
                for(int j=0;j<l;j++)
                {
                    char ch=input[j];
                    int code=(int)ch;
                    if((code>=a_code)&&(code<=z_code))
                    {
                       
                        int adder=((ch==letter) ? 1 : 0);
                        count+=adder;
                    }
                }
   
                if(count>0)
                {
                    cout<<letter<<": "<<count<<endl;
                }
        }


        cout<<"Enter message: ";
        getline(cin,input);

    }    
    
    return 0;
}
