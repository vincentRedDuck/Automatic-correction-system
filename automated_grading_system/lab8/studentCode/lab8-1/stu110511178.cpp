#include<bits/stdc++.h>

using namespace std;
double dis(double,double,double,double);
int main() {

    string px,py,p1x,p1y,redu;
    while(1){
        py.clear();
        px.clear(); 
        p1x.clear();
        p1y.clear();
        redu.clear();   
        double ax,ay,bx,by;
        
        cout<<"Enter first point:";
        getline(getline(getline(cin,redu,'('),px,','),py,')');
        cout<<"Enter second point:";
        getline(getline(getline(cin,redu,'('),p1x,','),p1y,')');

        ax=atof(px.c_str());
        ay=atof(py.c_str());
        bx=atof(p1x.c_str());
        by=atof(p1y.c_str());


        if(ax==0 && ay==0 && bx==0 && by==0)break;

        cout<<"Distance: "<<dis(ax,ay,bx,by)<<endl;

    }

return 0;

}


double dis(double a,double b, double c,double d) {

        return sqrt((a-c)*(a-c)+(b-d)*(b-d));

}

