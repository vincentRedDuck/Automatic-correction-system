#include <iostream>
#include <string.h> //strcpy()
using namespace std;

int main() {
    string text;  
    int len = 0; 

    while(1){
        cout <<"Enter message: ";
        getline(cin, text);//使用者輸入(整行讀取包含空白)
        
        if(text=="Stop"){break;}
        int arr[26][2];//儲存大小寫英文的數量，[0]大寫,[1]小寫
        int count = text.size();//string 長度
        char result[count]; //存入結果

        strcpy(result, text.c_str());//string to char
        
        for(int i = 0;i < 26;i++){
            for(int j = 0;j < 2;j++){      
                arr[i][j] = 0;
            }
        }
        for(int i = 0;i < count;i++){
            
            if(90 >= result[i] && result[i] >= 65)//大寫
            {
                arr[result[i]-65][0]++;
            }
            else if(122 >= result[i] && result[i] >= 97)//小寫
            {
                arr[result[i]-97][1]++;
            }

     }
     /*
        
     }  */
    if(text=="Stop"){
        break;

    }
    else{

    for(int j = 0;j < 2;j++){
        for(int i = 0;i < 26;i++){
            if(arr[i][j] != 0){
                if(j==0){    
                    cout << char(i+65) << ": " << arr[i][j]<< endl;
                }
                else if(j==1){
                    cout << char(i+97) << ": " << arr[i][j]<< endl;
                }
            }
        }
    }

    }


    }
    return 0;
}
