#include <iostream>
using namespace std;

int main(){

    int x;
    int len;
    char ch;
    while(1){
        char s1[100]={};
        char s2[100]={};	
        cout<<"1: encoder 2: decoder 3: quit: ";
	cin>>x;
	if(x==3)
	    break;
	cout<<"Please enter sentences length: ";
	cin>>len;
		
	if(x==1){
	    for(int i=0;i<len;i++){
	        cin >>ch;
		if(i%2==0){
		    s1[i]=ch;
		}
		else
		    s2[i]=ch;
	    }
	    for(int i=0;i<len;i++){
	        if(i%2==0)
		    cout<<s1[i];
	    }	
            for(int i=0;i<len;i++){
                if(i%2==1)
                    cout<<s2[i];
	    }
	    cout<<endl;
	}
	if(x==2){
            for(int i=0;i<len;i++){
	        if(i%2==0){
		cin>>ch;
		s1[i]=ch;
		}
	    }
	    for(int i=0;i<len;i++){
	        if(i%2==1){
		  cin>>ch;
		  s2[i]=ch;
		}
	    }
	    for(int i=0;i<len;i++){
	       
	        if(i%2==0){
		   cout<<s1[i];
		}
		else
	           cout<<s2[i];
	    }
	    cout<<endl;
	}
	
    }
  	
}
