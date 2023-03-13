#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    string p1;
    string p2;
    cout << "Enter first point:";
    cin >> p1;
    cout << "Enter second point:";
    cin >> p2;
    while(p1 != "(0,0)" || p2 != "(0,0)"){
        int vp1[2]={0};
        int mv1 = 0;
        bool neg1[2]={false,false};
        int vp2[2]={0};
        int mv2 = 0;
        bool neg2[2]={false,false};
            
        //for the first point
        for(int i=1; i <= p1.length()-2 ; i++){//the first and the final character are '(' and ')', just neglect.
            if(p1[i] == ','){
                mv1++;//after the ',' , move to the next value to input
            }
            if(48 <= (int)p1[i] && (int)p1[i] <= 57){
                vp1[mv1]  = vp1[mv1]*10 + ((int)p1[i]-48);//obtain value first
            }
            if(p1[i] == '-'){
                neg1[mv1] = true;//to judge if the value is negative. mutiple it by -1 at last
            }
        }
        for(int a=0; a <= 1; a++){
            if(neg1[a] == true){
                vp1[a] *= -1;//to mutiple the -1 back
            }
        }   
    

        //for the second point 
        for(int j=1; j <= p2.length()-2 ; j++){//the first and the final character are '(' and ')', just neglect.
            if(p2[j] == ','){
                mv2++;//after the ',' , move to the next value to input
            }
            if(48 <= (int)p2[j] && (int)p2[j] <= 57){
                vp2[mv2]  = vp2[mv2]*10 + ((int)p2[j]-48);//obtain value first
            }
            if(p2[j] == '-'){
                neg2[mv2] = true;//to judge if the value is negative. mutiple it by -1 at last
            }
        }
        for(int b=0; b <= 1; b++){
            if(neg2[b] == true){
                vp2[b] *= -1;//to mutiple the -1 back
            }
        }
        //cout << vp1[0] << " " << vp1[1] << endl;
        //cout << vp2[0] << " " << vp2[1] << endl;
    
        int dx = vp1[0]-vp2[0];
        int dy = vp1[1]-vp2[1];
        double d = sqrt(dx*dx + dy*dy);//the distance
        cout << "Distance: " << d << endl;

        cout << "Enter first point:";
        cin >> p1;
        cout << "Enter second point:";
        cin >> p2;
    }
    cout << endl;
}
