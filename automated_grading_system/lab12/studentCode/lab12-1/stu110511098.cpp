#include<iostream>
#include<iomanip>
using namespace std;

int counter(int &x,int &y,int &times,int a){
    if(x<(a%2==0?a*a-1:a*a)){
        x+=2;
        times++;
        return x;
    }
    else{
        y+=2;
        return y;
    }
}

int main(){
    int x;
    while(cin >> x){
        if(x == -1)
            break;
        int **vec = new int*[x];
        for(int i=0;i<x;i++){
            vec[i] = new int [x];
        }
        int k=1; 
        int i=0,j=0;
        int o=-1,e=0,t=0;
        for (int idx = 0;idx < x;idx++){
            for (int jdx = 0; jdx < x; jdx++){
                vec[idx][jdx] = 0;
            }
        }
        int m=x,n=x;
	    for (int count = 0; count < x/ 2; count++)  {
		    for (; j < n - 1; j++) {
			    vec[i][j] = counter(o,e,t,x);
		    }
		    for (; i < m - 1; i++) {
			    vec[i][j] = counter(o,e,t,x);
		    }
		    for (j = n - 1; j > count; j--) {
			    vec[i][j] = counter(o,e,t,x);
		    }
		    for (i = m- 1; i > count; i--) {
			    vec[i][j] = counter(o,e,t,x);
		    }
		    m--;
		    n--;
		    i++;
            (t<((x%2==1)?x*x/2:x*x/2+1)?o-=2:e-=2); 
	    }
	    if (x % 2 != 0){ 
		    vec[x/2][x/2] =(x%2==1&&x!=1?counter(o,e,t,x)+2:counter(o,e,t,x));
	    }
        for (int idx = 0;idx < x; idx++){
            for(int jdx = 0;jdx < x ;jdx++){
                    cout <<right<<setw(5)<<vec[idx][jdx];   
            }
            cout << "\n";
        }
    }
    return 0;
}
