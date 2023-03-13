#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

void point(string p, int po[]){
    string temp_str = "";
    int i, j, k;
    for(i = 0; i < 2; i++){
        po[i] = 0;
    }
    for(i = 0; i < p.length(); i++){
        temp_str += p[i];
        for(j = i+1; j < p.length(); j++){
            if(j > p.length()){
                break;
            }
            else if(isdigit(p[j])){
                i = j;
            }
            else if(p[j] == ','){
                temp_str = p.substr(1,j-1);
                po[0] = stoi(temp_str);
                k = j+1;
                break;
            }
            else if(p[j] == ')'){
                temp_str = p.substr(k,j-k); 
                po[1] = stoi(temp_str);
            }
            else{
                break;
            }
            temp_str.clear();
        }
    }
    return;
}
int main(){
    string p1, p2;;
    int i, j, x, y;
    double d;
    int po1[2], po2[2];
    cout << "Enter first point:";
    getline(cin,p1);
    point(p1, po1);
    cout << "Enter second point:";
    getline(cin,p2);
    point(p2, po2);
    while(po1[0] != 0 || po1[1] != 0 || po2[0] != 0 || po2[1] !=0){
        x = abs(po1[0]-po2[0]);
        y = abs(po1[1]-po2[1]);
        d = sqrt(x*x+y*y);
        cout << "Distance: " << d << endl;
        cout << "Enter first point:";
        getline(cin,p1);
        point(p1,po1);
        cout << "Enter second point:";
        getline(cin,p2);
        point(p2,po2);
    }
    return 0;
}
