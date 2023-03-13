#include<bits/stdc++.h>

using namespace std;

void sort(char (&poc)[10],int (&value)[10]) {

    for(int s=0;s<10;s++) {
    for(int i=0;i<10;i++) {
        int k=i,rei;
        char rec;
        while((poc[k]=='h' && poc[k+1]=='s') || (value[k]>value[k+1] && poc[k]==poc[k+1])) {
            rec=poc[k];
            poc[k]=poc[k+1];
            poc[k+1]=rec;

            rei=value[k+1];
            value[k+1]=value[k];
            value[k]=rei;
            k++;        
        }

    }
    }
}            




int main() {

        char poc[10];
        int  value[10];
    for(int i=0;i<10;i++) {
        cout<<"#"<<i+1<<" card suit: ";
        cin>>poc[i];
        cout<<"#"<<i+1<<" card number: ";
        cin>>value[i];
    }
    
    sort(poc,value);
    cout<<"\nafter sort"<<endl;
    for(int k=0;k<10;k++) {
        cout<<"suit: "<<((poc[k]=='s')?"Spades " : "Heart ")<<"number: "<<value[k]<<endl;
    }

return 0;
}


