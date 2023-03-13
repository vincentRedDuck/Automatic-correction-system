#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	srand(2001);
        int a, b, c;
	cout<<"Please enter rows and cols of 1st matrix: ";
        cin >> a >> b;
        cout << "Please enter cols of 2nd matrix: ";	
	cin>> c;
        int array1[100][100] = {0};
        int array2[100][100] = {0};
        int array3[100][100] = {0};
	cout<<"Matrix1"<<endl;
        for (int i = 1; i <= a; i++) {
                for (int j = 1; j <= b; j++) { 
                        array1[i][j] = rand()%100;
                        cout<<array1[i][j]<<" ";
                }
		cout<<endl;
        }
	
	cout<<"Matrix2"<<endl;
        for (int i = 1; i <= b; i++) {
                for (int j = 1; j <= c; j++) {
                        int y1;
                        array2[i][j] = rand()%100;
                        cout<<array2[i][j]<<" ";
		}
		cout<<endl;
        }
        for (int i = 1; i <= a; i++) {

                for (int in1 = 1; in1 <= c; in1++) {
                        for (int j = 1; j <= b; j++) {
                                int s1 = array1[i][j];
                                int s2 = array2[j][in1];
                                array3[i][in1] += s1 * s2;
                        }
                }
        }
        cout<<"Matrix3"<<endl;
        for (int i = 1; i <= a; i++) {
                for (int j = 1; j <= c; j++) {
                        cout << array3[i][j] << " ";
                }
                cout << endl;
        }
}

