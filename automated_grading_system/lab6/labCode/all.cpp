#include <iostream>
#include <math.h>

using namespace std;

struct number;

void Is_Prime(number&);
void ICP_Hanoi(int,char,char,char);
int ICP_Ackerman(int,int);

struct number{
    int num;
    bool prime;
}in;

// int main(){
//     while(cin>>in.num, in.num != 0 ){
//         if(in.num < 0)
//             continue;
//         else{
//             Is_Prime(in);
//             cout<<((in.prime)? "True!\n" : "False!\n");
//         }
//     }
//     return 0;
// }

// int main(){
//     int in;
//     char c1,c2,c3;
//     while(cin>>in,in > 0){
//         cin >> c1 >> c2 >> c3;
//         ICP_Hanoi(in,c1,c2,c3);
//     }
//     return 0;
// }

// int main(){
//     int m,n;
//     while(cin>>m>>n,m >= 0 && n >= 0)
//         cout<<ICP_Ackerman(m,n)<<endl;
//     return 0;
// }

void Is_Prime(number& a){
    if(a.num != 2)
        for(int i = 2; i < sqrt(a.num) + 1 ; i++ )
            if( a.num % i == 0){
                a.prime = 0;
                return;
            }
    a.num == 1? a.prime = 0 : a.prime = 1;
    return;
}

void ICP_Hanoi(int n,char A,char B,char C){
    if(n == 1)
        cout<<"Move Disk_"<<n<<" from "<<A<<" to "<<C<<endl;
    else{
        ICP_Hanoi(n-1,A,C,B);
        cout<<"Move Disk_"<<n<<" from "<<A<<" to "<<C<<endl;
        ICP_Hanoi(n-1,B,A,C);
    }
    return;
}

int ICP_Ackerman(int m,int n){
    if(m == 0)
        return n+1;
    else if(n == 0 && m > 0)
        return ICP_Ackerman(m-1,1);
    else
        return ICP_Ackerman(m-1,ICP_Ackerman(m,n-1));
}