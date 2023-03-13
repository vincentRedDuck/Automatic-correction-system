#include<iostream>
#include<algorithm>
using namespace std;
/*struct CARD{
    char suit;
    int value;
};*/

int main(){
    char suit;
    int s[10]={0};
    int h[10]={0};
    for(int i = 0; i<10; i++){
        cout << "#"<< i+1 << " card suit: ";
        cin >> suit;
        switch(suit){
            case 's':
            {   cout << "#"<< i+1 << " card number: " ;
                cin >> s[i];
                break;}
            case 'h':
            {   cout << "#"<< i+1 << " card number: ";
                cin >> h[i];
                break;}
        }}
        sort(s,s+10);
        sort(h,h+10);
    cout << endl << "after sort" << endl;
    for(int i=0; i <10;i++){
        if(s[i]!=0){
            cout << "suit: Spades " << "number: " << s[i]<< endl;
        }}
    for(int i=0; i <10;i++){
        if(h[i]!=0){
            cout << "suit: Heart " << "number: " << h[i]<< endl;}}
        

    return 0;
}
