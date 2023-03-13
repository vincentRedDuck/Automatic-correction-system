#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;
int main(int argc, char **argv){
    ifstream inf1,inf2;
    ofstream outf1,outf2;
    inf1.open(argv[1]);
    outf1.open(argv[2]);
    struct poke{
        int num;
        string eg,tw;
        };
    int max = 1000;
    poke po[max];
    string line;
    string tmp;
    int n = 0,m = 0,k = 0,p = 0;
    char ch;
    while(inf1.get(ch)){
        //cout << ch;
        if(isdigit(ch)){
            inf1.putback(ch);
            inf1 >> po[n++].num;
        }
        else if(isalpha(ch)){
            if(k == 0){
                inf1.putback(ch);
                inf1 >> po[m++].eg;
                k++;
            }
            else{
                inf1.putback(ch);
                inf1 >> tmp;
                po[m-1].eg = po[m-1].eg+" "+tmp;
            }
        }        
        else if(k == 1 && ch != ' '){
            inf1 >> po[p++].tw;
            k = 0;
        }
    }
    //cout << po[121].eg <<"::"<<po[122].eg <<endl;
    //cout << n<< "," <<m <<" ," << p <<endl;
    ostringstream oss;
    for(int i = 0; i<p; i++){
        if(po[i].num>99)
            oss << po[i].num << " " << po[i].eg << " " << po[i].tw << endl;
        else if(po[i].num<10)
            oss << "00" << po[i].num << " " << po[i].eg << " " << po[i].tw << endl;
        else 
            oss << "0" << po[i].num << " " << po[i].eg << " " << po[i].tw << endl;
    }
    string t = oss.str();
    outf1 << t;
    inf2.open(argv[3]);
    outf2.open(argv[4]);
    poke my[max];
    n = 0;
    int q;
    stringstream ss;
    while(inf2.get(ch)){ 
        ss.str("");ss.clear();
        if(isdigit(ch)){
            inf2.putback(ch);
            inf2 >> tmp;
            ss.str(tmp);
            ss >> q;               
            for(int i = 0; i<p; i++){
                if(q == po[i].num)
                    my[n++] = po[i];
            }
        }
        else if(isalpha(ch)){
            inf2.putback(ch);
            inf2 >> tmp;
            for(int i = 0; i<p; i++){
                if(tmp == po[i].eg)
                    my[n++] = po[i];
            }            
        }
    }
    for(int i = 1; i<n; i++){
        poke key = my[i];
        int idx = i-1;
        while(idx >= 0 && my[idx].num > key.num){
            my[idx+1] = my[idx];
            --idx;
        }
        my[idx+1] = key;
    }
    for(int i = 0; i<n; i++){
        if(i != n-1){
            if(my[i].num == my[i+1].num) continue;
            outf2 << my[i].num << " " << my[i].eg << endl;
        }
        else
            outf2 << my[i].num << " " << my[i].eg << endl;
    }
    return 0;
}
