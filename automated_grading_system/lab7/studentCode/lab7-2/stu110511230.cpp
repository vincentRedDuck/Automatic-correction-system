#include<iostream>
using namespace std;

int swi,len;
char ha[100],hb[100],fs[100];

int main () {
	cout << "1: encoder 2: decoder 3: quit: ";
	cin >> swi;
	while (1){
		switch(swi){
			case 1 :
				cout <<"Please enter sentences length: ";
				cin >> len;
				for(int i=0;i<(len/2);i++){
					cin >> ha[i] >> hb[i];
				}
				if (len%2==1)
					cin >> ha[len/2];
				for(int i=0;i<=(len/2);i++){
					cout << ha[i];
					if((len%2==0) && i==((len/2)-1))
						break;
				}
				for(int i=0;i<(len/2);i++){
					cout << hb[i];
				}
				cout << endl;
				break;
			case 2 :
                        	cout <<"Please enter sentences length: ";
                        	cin >> len;
                        	for(int i=0;i<(len/2);i++){
                                	cin >> ha[i];
                        	}
				if(len%2==1)
					cin >> ha[len/2];
                        	for(int i=0;i<(len/2);i++){
                                	cin >> hb[i];
                        	}
                        	for(int i=0;i<(len/2);i++){
                                	cout << ha[i];
					cout << hb[i];
				}
				if(len%2==1)
					cout << ha[len/2];
                        	cout << endl;
                        	break;
			case 3 :
		        	break;
			default :
		        	cout << "invalid input" << endl;
				break;	
		}
	if (swi!=3)
		cout << endl;
	if (swi==3)
		break;
	cout << "1: encoder 2: decoder 3: quit: ";
	cin >> swi;
	}
return 0;
}
