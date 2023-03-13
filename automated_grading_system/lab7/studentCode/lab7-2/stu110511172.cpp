#include<iostream>
using namespace std;

void fillarray_1(char encoder_1[],int length,char code[]){
    for( int i=0; i<length;i++){
        if(i%2==0){
            encoder_1[i/2] = code[i];
        }
    }
}
void fillarray_2(char encoder_2[],int length,char code[]){
    for( int i=0; i<length;i++){
        if(i%2==1){
            encoder_2[(i-1)/2] = code[i];
        }
    }
}
void fillarray_3(char decoder_1[],int length,char code[]){
    int len;
    if(length%2==0){
    len = length/2;
    }
    else{
    len = (length+1)/2+1;}
    for(int i=0;i<len;i++){
        decoder_1[i] = code[i];
    }
}
void fillarray_4(char decoder_2[],int length,char code[]){
    int len;
    if(length%2==0){
    len = length/2;
    }
    else{
    len = (length+1)/2+1;}
    for(int i=len;i<length;i++){
        decoder_2[i-len] = code[i];
    }
}



void encode(char encoder_1[],char encoder_2[],int length){
    char finalcode[100];
    int len;
    if(length%2==0){
        len = length/2;}
    else{
        len = (length-1)/2+1;}
        
    for(int i=0; i<len;i++){
        finalcode[i] = encoder_1[i];
    }
    for(int i=len; i<length; i++){
        finalcode[i] = encoder_2[i-len];
    }
    for(int i=0;i<length;i++){
        cout << finalcode[i];
    }
    cout << endl;
}
void decode(char decoder_1[],char decoder_2[],int length){
    char finalcode[100];
    for(int i=0; i<length;i++){
        if(i%2==0){
        finalcode[i] = decoder_1[i/2];}
        else{
        finalcode[i] = decoder_2[(i+1)/2-1];}
    }
    for(int i=0;i<length;i++){
        cout << finalcode[i];
    }
    cout << endl;
}


int main(){
    
    int type;
    cout << "1: encoder 2: decoder 3: quit: ";
    cin >> type;
    while(type!=3){
        int length;
        string code;
        if(type==1){
            cout << "Please enter sentences length: ";
            cin >> length;
            char encoder_1[length];
            char encoder_2[length];
            char specode[100];
            cin >> specode;
            fillarray_1( encoder_1, length, specode);
            fillarray_2( encoder_2, length, specode);
            encode(encoder_1,encoder_2,length);
        }
        else if(type==2){
            cout << "Please enter sentences length: ";
            cin >> length;
            char decoder_1[length];
            char decoder_2[length];
            char specode[100];
            cin >> specode;
            fillarray_3( decoder_1, length, specode);
            fillarray_4( decoder_2, length, specode);
            decode(decoder_1,decoder_2,length);
        }
        else{
            cout << "invalid input" << endl;
        }
    cout << "1: encoder 2: decoder 3: quit: ";
    cin >> type;
    }


return 0;
}
