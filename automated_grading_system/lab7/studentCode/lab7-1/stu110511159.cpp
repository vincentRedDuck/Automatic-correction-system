#include <iostream>
using namespace std;

struct card{
    char suit;
    int value;
};

void gg(card s[],int n){
    cout<<"#"<<n+1<<" card suit: ";	
    cin>>s[n].suit;
    cout<<"#"<<n+1<<" card number: ";
    cin>>s[n].value;    
}
int main(){
    card s[10];
    for(int i=0;i<10;i++){
    
      gg(s,i);
    }
    cout<<endl<<"after sort"<<endl;
    for(int i=1;i<10;i++){
        card key;
 	key=s[i];
	int j=i-1;
	while(j>=0 && s[j].value>key.value){
	    s[j+1]=s[j];
	    --j;
	    
	}
        s[j+1]=key;
    }	
   
    for(int i=0;i<10;i++){
        if(s[i].suit=='s'){
	    cout<<"suit: Spades number: "<<s[i].value<<endl;
	}
    }
    for(int i=0;i<10;i++){
        if(s[i].suit=='h'){
	    cout<<"suit: Heart number: "<<s[i].value<<endl;
	}
    }

    
}
