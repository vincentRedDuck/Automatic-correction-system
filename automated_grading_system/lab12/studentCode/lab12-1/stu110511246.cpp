#include<iostream>
#include<iomanip>
using namespace std;
int main() {
    int n;
    while(cin>>n) {
        int **vec;
        int flag=0;
        if(n==-1)
            break;
        else {
            vec=new int *[n];
            int tmpx=n;
            int tmpy=n;
            for(int i=0; i<n; i++) {
                vec[i]=new int[n];
            }
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    vec[i][j]=0;
                }
            }
            int x=0,y=0;
            int border =0;
            for(int i=1; i<=n*n; i++) {

                if(flag==0) { /*right*/
                    if(y==n-border) {
                        flag=1;
                        x=x+1;
                        y=y-1;
                        i--;
                        continue;
                    }
                    vec[x][y]=(i<=(n*n+1)/2?2*i-1:(i-(n*n+1)/2)*2);
                    y++;
                }
                else if(flag==1) { /*down*/
                    if(x==n-border) {
                        flag=2;
                        y=y-1;
                        x--;
                        i--;
                        continue;
                    }
                    vec[x][y]=(i<=(n*n+1)/2?2*i-1:(i-(n*n+1)/2)*2);
                    x++;
                }
                else if(flag==2) { /*left*/
                    if(y<border) {
                        flag=3;
                        x=x-1;
                        y++;
                        border++;
                        i--;
                        continue;
                    }
                    vec[x][y]=(i<=(n*n+1)/2?2*i-1:(i-(n*n+1)/2)*2);
                    y--;
                }
                else if(flag==3) { /*up*/
                    if(x<border) {
                        flag=0;
                        y=y+1;
                        x++;
                        i--;
                        continue;
                    }
                    vec[x][y]=(i<=(n*n+1)/2?2*i-1:(i-(n*n+1)/2)*2);
                    x--;
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<setw(5)<<right<<vec[i][j];
            }
            cout<<endl;
        }
        for(int i=0; i<n; i++) {
            delete []vec[i];
        }
        delete []vec;

    }

return 0;

}

