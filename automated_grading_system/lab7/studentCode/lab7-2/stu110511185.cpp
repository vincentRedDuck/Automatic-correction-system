#include <iostream> 
using namespace std;
int main(){
    //options
    int choice;
    cout << "1: encoder 2: decoder 3: quit: ";
    cin >> choice;
    while(choice != 3){
        switch(choice){
            case 1:{
                //define the length of the sentence
                int lens;
                cout << "Please enter sentences length: ";
                cin >> lens;
                
                //define the input sentence
                char in[lens];
                cin >> in;

                //define the output sentence
                char out[lens];

                //output = even number char part + odd number char part
                //assign the char to out[startOfE] when i is even, while out[startOfO] when odd
                int startOfE = 0;
                int startOfO = (lens-1)/2+1;
                for(int i=0; i<=lens-1; i++){
                    if(i%2 == 0){
                        out[startOfE] = in[i];
                        startOfE++;
                    }
                    else if(i%2 == 1){
                        out[startOfO] = in[i];
                        startOfO++;
                    }
                }
                for(int j=0; j<=lens-1; j++){
                    cout << out[j];
                }
                cout << endl;
                cout << endl;
                break;
            }

            case 2:{
                //define the length of the sentence
                int lens;
                cout << "Please enter sentences length: ";
                cin >> lens;
                
                //define the input sentence
                char in[lens];
                cin >> in;

                //define the output sentence
                char out[lens];

                //output = even number char part + odd number char part
                //assign the char to out[startOfE] when i is even, while out[startOfO] when odd
                int startOfE = 0;
                int startOfO = (lens-1)/2+1;
                for(int i=0; i<=lens-1; i++){
                    if(i%2 == 0){
                        out[i] = in[startOfE];
                        startOfE++;
                    }
                    else if(i%2 == 1){
                        out[i] = in[startOfO];
                        startOfO++;
                    }
                }
                for(int j=0; j<=lens-1; j++){
                    cout << out[j];
                }
                cout << endl;
                cout << endl;
                break;
            }

            default:{
                cout << "invalid input" << endl;
                cout << endl;
            }
        }
    cout << "1: encoder 2: decoder 3: quit: ";
    cin >> choice;
    }
}
