#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;

bool check(string,string);
bool min(string);
int ati(string);
void convert(string,string,string,string);
int main(){
    string p1,p2;
    int x1,x2,y1,y2,pos1,pos2;
    cout<<"Enter first point:";
    getline(cin,p1);
    cout<<"Enter second point:";
    getline(cin,p2);
    while (check(p1,p2)){
        string p1x(""),p1y(""),p2x(""),p2y("");
        pos1=p1.find(",");
        pos2=p2.find(",");
        p1x+=p1.substr(1,pos1-1); 
        p2x+=p2.substr(1,pos2-1);
        p1y+=p1.substr(pos1+1,p1.length()-pos1-2);
        p2y+=p2.substr(pos2+1,p2.length()-pos2-2);
        convert(p1x,p2x,p1y,p2y); 
        cout<<"Enter first point:";
        cin>>p1;
        cout<<"Enter second point:";
        cin>>p2; 
    }
    return 0;
}
bool check(string a1,string a2){
    if(a1=="(0,0)"&&a2=="(0,0)")
        return 0;
    else 
        return 1;
}
bool min(string a){
    if(a.find("-")<a.length())
        return true;
    else 
        return false;
}
int ati(string a){
    int sum=0;
    if(min(a)){
        for(int i=1;i<a.length();i++)
            sum+=(int(a[i])-48)*pow(10,a.length()-i-1);
        sum*=-1;
    }
    else{
        for(int i=0;i<a.length();i++)
            sum+=(int(a[i])-48)*pow(10,a.length()-i-1);
    }
    
    return sum;
}
void convert(string x1,string x2,string y1,string y2){
    int ix1=0,ix2=0,iy1=0,iy2=0;
        ix1=ati(x1);
        ix2=ati(x2);
        iy1=ati(y1);
        iy2=ati(y2);
        cout<<"Distance: "<<pow(pow(ix1-ix2,2)+pow(iy1-iy2,2),0.5)<<endl;
        
}

