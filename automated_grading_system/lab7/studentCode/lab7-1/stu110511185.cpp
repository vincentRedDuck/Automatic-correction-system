#include <iostream> 
using namespace std;

void printsuit(char s){
    if(s == 's') cout << "Spade";
    else cout << "Heart";
}
int main(){
    struct card{
        char suit;
        int num;
        };

    //input card array
    card cardin[10];
    for(int i=0; i<=9; i++){
        cout << "#" << i+1 << " card suit: ";
        cin >> cardin[i].suit;
        cout << "#" << i+1 << " card number: ";
        cin >> cardin[i].num;
    }

    //the quantity of each suit , 0 for Spade, 1 for Heart, 2 for Diamond, 3 for Clubs
    int suit[4] = {0};

    //sorting cards of each suit
    //put spades from the front ,hearts from the back
    card swap;
    for(int j=0; j<=9; j++){
        if(cardin[j].suit == 'h'){
            for(int k=9; k>=j; k--){
                if(cardin[k].suit == 's' && k>j){
                    swap = cardin[k];
                    cardin[k] = cardin[j];
                    cardin[j] = swap;
                }
            }
        }
    }

    //find the start of Heart
    int startH = 10;
    for(int l=0; l<=9; l++){
        if(cardin[l].suit == 'h'){
            startH = l;
            break;
        }
    } 
    
    //sorting number
    //step 1. pick up a card (must be or behind the second card)
    for(int a=1; a<=startH-1; a++){
        //step 2. compare it with the formers
        for(int b=0; b<=a-1; b++){
            //if smaller than this one, move the bigger one and those behind it backward for a blank
            if(cardin[a].num < cardin[b].num){
                swap = cardin[a];
                for(int c = a-1; c >= b; c--){
                    cardin[c+1] = cardin[c];
                }
                cardin[b] = swap;
            }
        }
    }
    //step 1. pick up a card (must be or behind the second card)
    for(int a=startH+1; a<=9; a++){
        //step 2. compare it with the formers
        for(int b=startH; b<=a-1; b++){
            //if smaller than this one, move the bigger one and those behind it backward for a blank
            if(cardin[a].num < cardin[b].num){
                swap = cardin[a];
                for(int c = a-1; c >= b; c--){
                    cardin[c+1] = cardin[c];
                }
                cardin[b] = swap;
            }
        }
    }
    cout << endl;
    cout << "after sort" << endl;
    for(int k=0; k<=9; k++){
        cout << "suit: ";
        if (cardin[k].suit == 's') cout << "Spade ";
        else cout << "Heart ";
        cout << "number: " << cardin[k].num << endl;
    }
}
