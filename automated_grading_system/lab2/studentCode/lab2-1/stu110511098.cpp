#include<iostream>
using namespace std;
int main(){

	int a;
	cout <<"Enter your score : ";
	cin>>a;
	a=a/10;

	switch(a){
		
		case 10:
			cout<<"You got a grade : A"<<endl;
			break;
		case 9:
			cout<<"You got a grade : A"<<endl; 	
                	break;
	       	case 8:
	           	cout<<"You got a grade : A"<<endl;
	       	        break;                           
		case 7:

	           	cout<<"You got a grade : B"<<endl;

	       	        break;                           
	       	case 6:
	       
	           	cout<<"You got a grade : C"<<endl;

	       	        break;                           
	       	case 5:	

	           	cout<<"You got a grade : D"<<endl;

	       	        break;                           
            	default:			
      			cout<<"You got a grade : E"<<endl;
                        break;			

	}
	return 0;
}
