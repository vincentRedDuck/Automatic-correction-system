#include <bits/stdc++.h>
using namespace std;

int main(){
    bool neg=0;
    string str1,str2;
    int x1=0,x2=0,y1=0,y2=0,temp=0,mid=0;
    double dis=0;
    while(1){
        cout << "Enter first point:";
        getline(cin,str1);
        for(int i=1; str1[i]!=','; i++,mid++){
            if(str1[i]=='-'){
                neg=1;
                continue;
            }
            temp*=10;
            temp+=int(str1[i]-48);
        }
        if(neg==0)x1=temp;
        else x1=(-1)*temp;
        temp=0;
        neg=0;
        for(int i=mid+2; str1[i]!=')'; i++){
            if(str1[i]=='-'){
                neg=1;
                continue;
            }
            temp*=10;
            temp+=int(str1[i]-48);
        }
        if(neg==0)y1=temp;
        else y1=(-1)*temp;
        temp=0;
        neg=0;
        mid=0;
        //cout << x1 << " " << y1 << endl;
        cout << "Enter second point:";
        getline(cin,str2);
        for(int i=1; str2[i]!=','; i++,mid++){
            if(str2[i]=='-'){
                neg=1;
                continue;
            }
            temp*=10;
            temp+=int(str2[i]-48);
        }
        if(neg==0)x2=temp;
        else x2=(-1)*temp;
        temp=0;
        neg=0;
        for(int i=mid+2; str2[i]!=')'; i++){
            if(str2[i]=='-'){
                neg=1;
                continue;
            }
            temp*=10;
            temp+=int(str2[i]-48);
        }
        if(neg==0)y2=temp;
        else y2=(-1)*temp;
        temp=0;
        neg=0;
        mid=0;
        //cout << x2 << " " << y2 << endl;
        if(x1==0&&x2==0&&y1==0&&y2==0)break;
        dis = pow(abs(x1-x2)*abs(x1-x2)+abs(y1-y2)*abs(y1-y2),0.5);
        cout << "Distance: " << dis << endl;
        x1=0; y1=0; x2=0; y2=0; dis=0;
    }
    return 0;
}
