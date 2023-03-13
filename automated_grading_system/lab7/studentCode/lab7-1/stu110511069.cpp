#include<iostream>
#include<iomanip>
using namespace std;
void insertsort(int arr[],int size,char c);
struct CARD{
    char suit;
    int value;
};
int main(){
    int s[10];
    int h[10];
    int s_sz = 0;
    int h_sz = 0;
    for(int i = 0;i<10;i++){
        char c;
        cout<<"#"<<i+1<<" card suit: ";
        cin>>c;
        int a;
        cout<<"#"<<i+1<<" card number: ";
        cin>>a;
        if(c=='s'){
            s[s_sz] = a;
            s_sz++;
        }
        else{
            h[h_sz] = a;
            h_sz++;
        }
    }
    cout<<endl<<"after sort"<<endl;
    insertsort(s,s_sz,'s');
    insertsort(h,h_sz,'h');

    
    return 0;
}
void insertsort(int arr[],int size,char c){
    for(int i = 1;i<size;i++){
        int j;
        for(j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                    
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
           for(int i = 0;i<size;i++){
                 cout<<"suit: "<<((c=='s')? "Spades": "Heart")<<" number: ";

               cout<<arr[i]<<endl;
    }
}


