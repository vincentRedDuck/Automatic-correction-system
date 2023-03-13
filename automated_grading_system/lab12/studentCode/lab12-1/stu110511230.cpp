#include<iostream>
#include<iomanip>
using namespace std;

//int c;
int r;
int w;
int n = 0;
int d = 0;
int tog = 0;

int **arr(int);
void del(int** ,int);

int main(){
	cin >> w;
	while(w!=(-1)){
		int MAX = w*w;
		int num[MAX];
		r = w-1;
//		c = w;
		int **a = arr(w);
		for (int i = 0;i < (w*w/2+(w%2));i++){
			num[i] = 2*i+1;
		}
		int j = 1;
		for (int i = (w*w/2+(w%2));i < w*w;i++){
			num[i] = 2*j;
			j++;
		}
		for(int i=0; i < w/2;i++){
			for (int j = 0;j<r;j++){
				a[n][d] = num[tog++];
				d++;
			}
			for (int j = 0;j<r;j++){
				a[n][d] = num[tog++];
				n++;
			}
			for (int j = 0;j<r;j++){
				a[n][d] = num[tog++];
				d--;
			}
			for (int j = 0;j<r;j++){
				a[n][d] = num[tog++];
				n--;
			}
			n++;
			d++;
			r -= 2;
		}
		if(w%2)
			a[w/2][w/2] = 2*(w*w/2);
		for (int i = 0;i < w;i++){
			for (int j = 0;j < w;j++)
				cout << setw(5) << right << a[i][j];
			cout << endl;
		}
		tog = 0;
		d = 0;
		n = 0;
		del(a,w);
		cin >> w;
			
	}
	return 0;
}

int **arr(int w){
	int **m = new int *[w];
	for (int i = 0;i < w;i++)
		m[i] = new int [w];
	return m;
}

void del(int **a,int w){
	for (int i = 0; i < w; i++)
		delete [] a[i];
	delete [] a;
}
