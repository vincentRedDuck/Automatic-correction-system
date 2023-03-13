#include <iostream>
using namespace std;

struct CARD{
    char suit;
    int value;
};
void InsertionSort_Spade(CARD arr[], int );

void InsertionSort_Heart(CARD arr[], int );

int main(){

    
    CARD temp[10];

    for(int i = 0; i<10 ;i++){

        cout <<"#"<<i+1<<" card suit: ";
        cin >>temp[i].suit;
        cout <<"#"<<i+1<<" card number: ";
        cin >>temp[i].value;
   

    }   


    CARD card[10];

    int store_i =0;
    for(int i = 0;i<10;i++){
    
        if(temp[i].suit=='s'){
        
            card[store_i].suit = temp[i].suit;
            card[store_i].value = temp[i].value;

            store_i += 1;
            
        }

    }
    
    int heart_head = store_i;

    InsertionSort_Spade( card, store_i);//SORT  spade here!



    for(int i = 0;i<10;i++){
    
        if(temp[i].suit=='h'){
        
            card[store_i].suit = temp[i].suit;
            card[store_i].value = temp[i].value;

            store_i += 1;
            
        }

    }

    InsertionSort_Heart( card, heart_head);//SORT heart!

    cout <<endl;
    cout <<"after sort"<<endl;
    for(int i = 0; i<heart_head ;i++){

        cout <<"suit: Spades number: ";
        cout <<card[i].value<<endl;
   

    }
    for(int i = heart_head; i<10 ;i++){
        
        cout <<"suit: Heart number: ";
        cout <<card[i].value<<endl;
 
    }
   
    return 0;
}

void InsertionSort_Spade(CARD  arr[], int size){

    for (int i = 1; i < size; i++) {
        int key = arr[i].value;
        int j = i - 1;
        while (key < arr[j].value && j >= 0) {
            arr[j+1].value = arr[j].value;
            j--;
        }
        arr[j+1].value = key;
    }
}

void InsertionSort_Heart(CARD  arr[], int heart_head){

    for (int i = heart_head +1 ; i < 10 ; i++) {
        int key = arr[i].value;
        int j = i - 1;
        while (key < arr[j].value && j >= heart_head) {
            arr[j+1].value = arr[j].value;
            j--;
        }
        arr[j+1].value = key;
    }
}







