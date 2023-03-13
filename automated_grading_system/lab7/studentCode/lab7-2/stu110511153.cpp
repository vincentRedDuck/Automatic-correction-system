#include <bits/stdc++.h>
using namespace std;

void fE(char o[], int l)
{   
    for(int i=0;i<l;i+=2)
    {
            cout<<o[i];
    }
    for(int i=1;i<l;i+=2)
        cout<<o[i];
        cout<<endl<<endl;

}

void fD(char o[], int l)
{   char d[l];
    for(int i=0;i<l/2;i++)
        d[2*i]=o[i];
    for(int i=l/2;i<l;i++)
        d[2*i-l+1]=o[i];
    for(int j=0;j<l;j++)    
    cout<<d[j];
    cout<<endl<<endl;
}
int main(){
    int n,l,s;
    cout<<"1: encoder 2: decoder 3: quit: ";
    cin>>n;
while(n!=3)
   {        
       switch(n)
        {  
        case 1:
          {  cout<<"Please enter sentences length: ";
            cin>>l;
            char o[l];
            for(int i=0;i<l;i++)
            {
                cin>>o[i];
            }
            fE(o,l);
           } break;
            
        case 2:
          {  cout<<"Please enter sentences length: ";
            cin>>s;
            char a[s];
            for(int i=0;i<s;i++)
            {
                cin>>a[i];
            }
            fD(a,s);
           } break;
        default:
            cout<<"invalid input"<<endl<<endl;
            break;
        }
         cout<<"1: encoder 2: decoder 3: quit: ";
    cin>>n;

    }
    return 0;
}
