#include<bits/stdc++.h>
using namespace std;

struct CARD{
    char suit;
    int value;
};

int main(){
    CARD c[10];  
    for(int i=0; i<10; ++i){
        cout << "#" << i+1 << " card suit: ";
        cin >> c[i].suit;
        cout << "#" << i+1 << " card number: ";
        cin >> c[i].value;
    }
    
    const char color[] = {'s', 'h'};
    for(int i=1; i<10; ++i){
        int key = c[i].value;
        char t = c[i].suit;
        for(int j=i-1; j>=0; --j){
            if(c[j].value > key){
                c[j+1].value = c[j].value;
                c[j+1].suit = c[j].suit;
                if(j == 0){
                    c[0].value = key;
                    c[0].suit = t;
                }
                /*cout << i << j << " ";
                for(auto x: c)
                    cout << x.value << " ";
                cout << endl;*/
            }

            else{
                c[j+1].value = key;
                c[j+1].suit = t;
                /*cout << i << j << " ";
                for(auto x: c)
                    cout << x.value << " ";
                cout << endl;*/
                break;
            }
        
        }
    }
  
    cout << "\nafter sort\n";
    for(int i=0; i<2; ++i)
        for(int j=0; j<10; ++j){
            if(c[j].suit == color[i]){
                 cout << "suit: " << (i==0? "Spades": "Heart");
                 cout << " number: " << c[j].value << "\n";
            }
        }
}

