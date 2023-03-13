#include<iostream>
using namespace std;

struct CARD{
	char suit;
	int value;
};
void insertion_sort(CARD arr[],int len);
int main()
{  
   CARD card[10];
   for(int i=1; i<=10; i++){
	   cout<<"#"<<i<<" card suit: "; cin>>card[i-1].suit;
	   cout<<"#"<<i<<" card number: "; cin>>card[i-1].value;
   }
   cout<< endl;
   cout<<"after sort"<<endl;

   insertion_sort(card ,10);
	       

    
   

return 0;
}

	
void insertion_sort(CARD arr[],int len){
        for(int i=1;i<len;i++){
                CARD key=arr[i];
               int j=i-1;
                while((j>=0) && (key.value<arr[j].value)){
                        arr[j+1]=arr[j];
                        j--;
                }
                arr[j+1]=key;
        }
	for(int j=0; j<10;j++){
		if(arr[j].suit=='s')
		cout<<"suit: Spades number: "<<arr[j].value<<endl;
	        else
		continue;}
        for(int j=0; j<10;j++){
                if(arr[j].suit=='h')
                cout<<"suit: Heart number: "<<arr[j].value<<endl;
                else
                continue;}
	
}
