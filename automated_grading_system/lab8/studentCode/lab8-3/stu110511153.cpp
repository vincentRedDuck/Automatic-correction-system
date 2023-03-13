#include<bits/stdc++.h>
using namespace std;

int main(){
    while(1)
    {
        string s,s2;
        int b[20]={0};
        int j=0;
        cout<<"Enter the sentence: ";
        getline(cin,s);
        if(s=="Stop the program")
            break;
        int a=s.length();
        for(int i=a-2;i>=0;i--)
        {
           if(!isalpha(s[i]) && isalpha(s[i+1]))
           {
                    b[j]=i+1;
                    j++;

           }
            
        }
        if(isalpha(s[0]))
           { b[j]=0;
            j++;}
        for(int i=0;i<j;i++)
         {       
            for(int k=b[i];;k++)
            {
                    if(isalpha(s[k]))
                        cout<<s[k];
                        else
                            break;
                    
                    }
                    cout<<" ";
        
        }cout<<endl;
        
    }
    return 0;
}
