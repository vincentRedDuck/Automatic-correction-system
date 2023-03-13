#include<iostream>
#include<cmath>
/*#include<cstring>
#include<string>
using namespace std;

int x1; int y1; int x2; int y2;
int main()
{
	string first;
	string second;
        cout<< "Enter first point:"; cin>> first; 
	cout<< "Enter second point:"; cin>> second;

        int key1;
        for(int i=0;i<100;i++){
   
            if(first[i]==','){
             key1=i;
             break;
                }
	}
	for( int i=0;i<key1;i++){
		x1=s(first);}

        for(int j=key1;j<100;j++){
              
               y1=stoi(first);
                        
        }
 
	int key2;
	for(int i=0;i<100;i++){
               
                if(second[i]==','){
                        key2=i;
                        break;
                }
        }
	for(int i=0; i<key2;i++){
		x2=stoi(second);
	}
        for(int j=key2;j<100;j++){
                if(isdigit(second[j])){
                        y2=stoi(second);
                        }
        }
    cout<< x1 << x2 << y1 <<y2<<endl;
    return 0;
} */
using namespace std;

int main()
{
	char up ,down;
	int x1,y1,x2,y2;
	
        cout<< "Enter first point:"; cin>> up >> x1 >> up >> y1 >> up;
        cout<< "Enter second point:"; cin>> down >> x2 >> down >> y2 >> down;
        while(1){
		if(x1==0&&x2==0&&y1==0&&y2==0)
			break;
	
	cout<< "Distance: "<<sqrt(pow((x1-x2),2)+pow((y1-y2),2))<<endl;
        cout<< "Enter first point:"; cin>> up >> x1 >> up >> y1 >> up;
        cout<< "Enter second point:"; cin>> down >> x2 >> down >> y2 >> down;
	}
return 0;
}

