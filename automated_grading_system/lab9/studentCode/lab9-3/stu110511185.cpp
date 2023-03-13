#include <iostream> 
#include <fstream>
#include <sstream>
using namespace std;


//string function: Encoder,alphabat or number to morse
string enc(string ap){
    if(ap == "A"){
        return ".-";
    }
    else if(ap == "B"){
        return "-...";
    }
    else if(ap == "C"){
        return "-.-.";
    }
    else if(ap == "D"){
        return "-..";
    }
    else if(ap == "E"){
        return ".";
    }
    else if(ap == "F"){
        return "..-.";
    }
    else if(ap == "G"){
        return "--.";
    }
    else if(ap == "H"){
        return "....";
    }
    else if(ap == "I"){
        return "..";
    }
    else if(ap == "J"){
        return ".---";
    }
    else if(ap == "K"){
        return "-.-";
    }
    else if(ap == "L"){
        return ".-..";
    }
    else if(ap == "M"){
        return "--";
    }
    else if(ap == "N"){
        return "-.";
    }
    else if(ap == "O"){
        return "---";
    }
    else if(ap == "P"){
        return ".--.";
    }
    else if(ap == "Q"){
        return "--.-";
    }
    else if(ap == "R"){
        return ".-.";
    }
    else if(ap == "S"){
        return "...";
    }
    else if(ap == "T"){
        return "-";
    }
    else if(ap == "U"){
        return "..-";
    }
    else if(ap == "V"){
        return "...-";
    }
    else if(ap == "W"){
        return ".--";
    }
    else if(ap == "X"){
        return "-..-";
    }
    else if(ap == "Y"){
        return "-.--";
    }
    else if(ap == "Z"){
        return "--..";
    }

    //numbers
    else if(ap == "1"){
        return ".----";
    }
    else if(ap == "2"){
        return "..---";
    }
    else if(ap == "3"){
        return "...--";
    }
    else if(ap == "4"){
        return "....-";
    }
    else if(ap == "5"){
        return ".....";
    }
    else if(ap == "6"){
        return "-....";
    }
    else if(ap == "7"){
        return "--...";
    }
    else if(ap == "8"){
        return "---..";
    }
    else if(ap == "9"){
        return "----.";
    }
    else if(ap == "0"){
        return "-----";
    }

    //blank
    else if(ap == " "){
        return "       ";
    }

    //not found
    else{
        cout << ap << ": alphabet not found" << endl;
        return "Error";
    }
}

//string function: Decoder, morse to alphabat or number
string dec(string mo){
    //alphabets
    if(mo == ".-"){
        return "A";
    }
    else if(mo == "-..."){
        return "B";
    }
    else if(mo == "-.-."){
        return "C";
    }
    else if(mo == "-.."){
        return "D";
    }
    else if(mo == "."){
        return "E";
    }
    else if(mo == "..-."){
        return "F";
    }
    else if(mo == "--."){
        return "G";
    }
    else if(mo == "...."){
        return "H";
    }
    else if(mo == ".."){
        return "I";
    }
    else if(mo == ".---"){
        return "J";
    }
    else if(mo == "-.-"){
        return "K";
    }
    else if(mo == ".-.."){
        return "L";
    }
    else if(mo == "--"){
        return "M";
    }
    else if(mo == "-."){
        return "N";
    }
    else if(mo == "---"){
        return "O";
    }
    else if(mo == ".--."){
        return "P";
    }
    else if(mo == "--.-"){
        return "Q";
    }
    else if(mo == ".-."){
        return "R";
    }
    else if(mo == "..."){
        return "S";
    }
    else if(mo == "-"){
        return "T";
    }
    else if(mo == "..-"){
        return "U";
    }
    else if(mo == "...-"){
        return "V";
    }
    else if(mo == ".--"){
        return "W";
    }
    else if(mo == "-..-"){
        return "X";
    }
    else if(mo == "-.--"){
        return "Y";
    }
    else if(mo == "--.."){
        return "Z";
    }

    //numbers
    else if(mo == ".----"){
        return "1";
    }
    else if(mo == "..---"){
        return "2";
    }
    else if(mo == "...--"){
        return "3";
    }
    else if(mo == "....-"){
        return "4";
    }
    else if(mo == "....."){
        return "5";
    }
    else if(mo == "-...."){
        return "6";
    }
    else if(mo == "--..."){
        return "7";
    }
    else if(mo == "---.."){
        return "8";
    }
    else if(mo == "----."){
        return "9";
    }
    else if(mo == "-----"){
        return "0";
    }

    else{
        cout << mo << ": code not found" << endl;
        return "Error";
    }
}

//total function of encoding and decoding 
string Mor(string in, bool fn){
    if(fn == true){
        return enc(in);
    }
    else{
        return dec(in);
    }
}

//main
int main(int argc, char *argv[]) {
    //name of input and output file
    string iFn = argv[1];
    string oFn = argv[2];

    //define the filestreams and open the demanded files
    ifstream iFs;
    ofstream oFs;
    iFs.open(iFn.c_str());
    oFs.open(oFn.c_str(), ios::out);

    //function boolean, true for encoding, false for decoding
    bool fn;
    if(argv[3][0] == 'd'){//compare char with char, to avoid the "\0" in the back of cstring 
        fn = false;
    }
    else if(argv[3][0] == 'e'){
        fn = true;
    }
    else{
        cout << "Function not found!" << endl;
        return 404;
    }
    if(fn == true){
        string line;
        while(getline(iFs, line)){
            while(line != ""){
                string out;
                cout << out << endl;
                out += line[0];//change the first letter into a string type variable, to let enc() function receive
                oFs << enc(out);
                //break after encoded the last character, without outputting a blank in the back
                if(line.length() == 1){
                    break;
                }
                //output blank between morse code when both of the recent and the next character aren't blank
                if(line[0] != ' ' && line[1] != ' ' ){
                    oFs << " ";
                } 
                line.erase(0,1);
            }
            oFs << endl;
        }
    }


    else{
        string line;
        while(getline(iFs, line)){
            while(line != ""){
                //checking if the first 7 characters are blanks
                bool blank7 = true;
                for(int idxC = 0; idxC <= 6; idxC++){
                    if(line[idxC] != ' '){
                        blank7 = false;
                        break;
                    }
                }
                //if so, output a blank, and remove the first 7 characters of line
                if(blank7 == true){
                    oFs << " ";
                    line.erase(0,7);
                }
                //if not, and there are any blanks in the front, delete them
                else if(line[0] == ' '){
                    line.erase(0,1);
                }
                //if not, find the location of next blank (also the end of the recent morse code set), cut the recent morse code set off
                else{
                    //no blanks found (reaching the last set)
                    if(line.find(" ") == std::string::npos){
                        oFs << dec(line);
                        line.erase(0, line.length());
                    }
                    else{
                        int setL = line.find(" ");
                        string set = line.substr(0, setL);
                        oFs << dec(set);
                        line.erase(0, setL);
                    }
                }
            }
            oFs << endl;
        }
    }

    iFs.close();
    oFs.close();
    
    return 0;
}
