#include <iostream>
#include <string>
using namespace std;
int main(){
    string a="",b="";
    int k = 0, m = 0;
    cout << "Enter the sentence: ";
    getline(cin,a);
    while(a != "Stop the program"){
    for(int i = 0; i < a.length(); i++){
        b[0] = ',';
        if((a[i]>64 && a[i]<91)||(a[i]>96 && a[i]<123)){
            k++;
            m = 0;
            b[k] = a[i];
        }
        else{
            if(m == 0){
                m++;
                k++;
                b[k] = ',';
            }
        }
    }
    /*for(int i = 0; i<=k; i++){
        cout << b[i];
    }
    cout << endl;*/
    int j = k;
    for(int i = k; i>=0; i--){
        if(b[i] == ','){
            for(int s = i+1; s<=j; s++){ 
            cout << b[s];
            }
            if (i!=0){
            cout <<" ";
            j = i-1;
            }    
        }
    }
    cout << endl;
    a="",b="";
    k = 0, m = 0;
    cout << "Enter the sentence: ";
    getline(cin,a);
    }
    return 0;
}
