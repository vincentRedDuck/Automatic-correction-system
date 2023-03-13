#include<bits/stdc++.h>
using namespace std;

int main(){
    while(1)
    {
        string s;
        cout<<"Enter message: ";
        getline(cin,s);
        if(s=="Stop")
            break;
        int a=s.length();
        for(char i='A';i<='Z';i++)
        {   
            int j=0;
            int c=0;
            while(j<a)
            {
                
               if( s[j]== i)
                {   
                    c++;
                

                }
                j++;
            }
            if(c!=0)
            cout<<i<<": "<<c<<endl;

        }
         for(char i='a';i<='z';i++)
        {   
            int j=0;
            int c=0;
            while(j<a)
            {
                
               if( s[j]== i)
                {   
                    c++;
                 
                }
                j++;
            }
            if(c!=0)
   cout<<i<<": "<<c<<endl;

        }
        

    }
    return 0;
}
