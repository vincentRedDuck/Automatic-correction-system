#include <iostream>
using namespace std;
bool alp(char c){//to show whether a character is an alphabat
    if(65<=(int)c && (int)c<=90) return true;
    else if(97<=(int)c && (int)c<=122) return true;
    else return false;
}
int countpts(string st){//to count how many alphabatical parts are there in the string
    int pts = 0;//number of parts
    if(alp(st[0])==true) pts++;//if the first character is an alphabat
    for(int i=1; i<=st.length()-1; i++){
        if(alp(st[i-1]) == false && alp(st[i]) == true){//later, number of parts adds one when it comes to the starting character of every parts
            pts++;
        }
    }
    return pts;
}
int main(){
    string in;
    cout << "Enter the sentence: ";
    getline(cin,in);
    while(in != "Stop the program"){
        int pts = countpts(in);
        string inparts[pts];
        //cout << pts << endl;
        bool rec = 0;//receive characters when true
        int step = 0;//which part is receiving characters
        for(int i=0; i<=in.length()-1; i++){
            if(alp(in[i])==true && i==0){
                rec = true;//start receiving
                //cout << "step" << step << endl;
            }
            else if(alp(in[i])==true && (i>0 && alp(in[i-1])==false)){
                rec = true;//start receiving
                step++;//move forward
            }
            if(alp(in[i])==false){
                continue;
            }
            if(rec == true){
                inparts[step] += in[i];
            }
            //cout <<  in[i] << endl;
        }
        for(int j=0; j<=pts-1; j++){
            cout << inparts[(pts-1)-j];
            if(j<pts-1){
                cout << " ";
            }
            //cout << "j" << j << endl;
        }
        cout << endl;
        cout << "Enter the sentence: ";
        getline(cin,in);
    }
}
