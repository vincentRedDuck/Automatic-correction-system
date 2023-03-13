#include<iostream>

#include<fstream>
#include<sstream>
#include<string>

using namespace std;

//void encode(stream&, string);

struct moscode{
    string a;
    string b;
};

int main(int argc, char *argv[]){
    //create moscode
    ifstream f;
    f.open("code.txt");
    moscode *mos = new moscode[40];
    string s;
    int i = 0;
    while(getline(f, s)){
        stringstream ss(s);
        ss >> mos[i].a >> mos[i].b;
        i++;
    }
    /*for(int j = 0; j < i; j++){
        cout << mos[j].a << " " << mos[j].b <<  endl;
    }*/
    f.close();

    if(argv[3][0] == 'e'){
        //cout << "t";
        ifstream fin;
        fin.open(argv[1]);
        string ll;
        ofstream fout;
        fout.open(argv[2]);
        while(getline(fin, ll)){
            for(int i = 0;i < ll.length(); i++){
                if(ll[i] == ' '){
                    fout << "       ";}
                else{
                    string tmp;
                    tmp.append(1, ll[i]);
                    for(int j = 0; j < 36; j++){
                        if(mos[j].a == tmp){
                            fout << mos[j].b << "   ";
                        }
                    }
                }
            }
            fout << endl;
        }
        fin.close();
        fout << endl;
        fout.close();
    }

    else{
        ifstream fin2;
        fin2.open(argv[1]);
        string lll;
        ofstream fout2(argv[2]);
        while(getline(fin2, lll)){
            stringstream ss(lll);
            string tok;
            int blank = 0;
            //string blank;
            //string word;
            while(getline(ss, tok, ' ')){
                if(tok == ""){
                    //cout << "t";
                    blank++;
                    if(blank == 6) {
                        fout2 << " ";
                        blank = 0;
                    }   
                }
                else{
                    blank = 0;
                    for(int i = 0; i < 36; i++){
                        if(mos[i].b == tok){
                            fout2 << mos[i].a;
                        }
                    }
                }
            }
            fout2 << endl;    
        }
        fout2.close();
    }

        
    
    return 0;
}

/*void encode(stream &fin, string ll){
    while(getline(fin, ll)){
        for(int i = 0;i < ll.length(); i++){
            if(ll[i] == ' '){
                cout << "       ";}
            else{
                string tmp;
                tmp.append(1, ll[i]);
                for(int j = 0; j < 36; j++){
                    if(mos[j].a == tmp){
                        cout << mos[j].b << "   ";
                        }
                    }
                }
            }                                                                                                                                                       
        cout << endl;
    }
}*/
