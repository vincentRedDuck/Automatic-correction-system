#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
// #include <cctype>

using namespace std;

string alphabet[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                        "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                        "-.--", "--.."};
string digit[10] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

int main(int argc, char* argv[]){
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    
    if(argv[3][0] == 'e'){
        string run;
        while(getline(in, run, '\n')){
            vector<string> str_;
            stringstream ss;
            ss << run;
            while(ss >> run){ str_.push_back(run);}

            string out_data;
            for(int i = 0 ; i < str_.size() ; i++){
                for(int j = 0 ; j < str_[i].size() ; j++){
                    if(isalpha(str_[i][j]))
                        out_data += alphabet[str_[i][j] - 'A'];
                    else if(isdigit(str_[i][j]))
                        out_data += digit[str_[i][j] - '0'];
                    if(j != str_[i].size() - 1)
                        out_data += "   ";
                }
                if(i != str_.size() - 1)
                    out_data += "       ";
            }
            out << out_data << endl;
        }
    }
    else{
        string run;
        while(getline(in, run, '\n')){
            int cnt = 0;
            string morse_code, out_data;
            for(int i = 0 ; i < run.length() ; i++){
                if(run[i] == ' ')
                    cnt++;    
                else{
                    if(cnt != 0){
                        for(int r = 0 ; r < 26 ; r++)
                                if(morse_code == alphabet[r])
                                    out_data += char(65 + r);
                            for(int r = 0 ; r < 10 ; r++)
                                if(morse_code == digit[r])
                                    out_data += char(48 + r);
                        if(cnt > 3)
                            out_data += " ";  
                        cnt = 0;
                        morse_code = run[i];
                    }
                    else
                        morse_code += run[i];                                           
                }
                if( i == run.length() - 1){
                    for(int r = 0 ; r < 26 ; r++)
                            if(morse_code == alphabet[r])
                                out_data += char(65 + r);
                    for(int r = 0 ; r < 10 ; r++)
                        if(morse_code == digit[r])
                            out_data += char(48 + r);

                    out << out_data << endl;
                    out_data = "";
                }
                    
            }
        }
    }
    in.close();
    out.close();
    return 0;
}