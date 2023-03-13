#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

string decode(char a) {
    switch (a) {
    case 'A': return ".-"; case 'O': return "---";
    case 'B': return "-..."; case 'P': return ".--.";
    case 'C': return "-.-."; case 'Q': return "--.-";
    case 'D': return "-.."; case 'R': return ".-.";
    case 'E': return "."; case 'S': return "...";
    case 'F': return "..-."; case 'T': return "-";
    case 'G': return "--."; case 'U': return "..-";
    case 'H': return "...."; case 'V': return "...-";
    case 'I': return ".."; case 'W': return ".--";
    case 'J': return ".---"; case 'X': return "-..-";
    case 'K': return "-.-"; case 'Y': return "-.--";
    case 'L': return ".-.."; case 'Z': return "--..";
    case 'M': return "--"; case '1': return ".----";
    case 'N': return "-."; case '2': return "..---";
    case '6': return "-...."; case '3': return "...--";
    case '7': return "--..."; case '4': return "....-";
    case '8': return "---.."; case '5': return ".....";
    case '9': return "----."; case '0': return "-----";
    }
    return "";
}
char encode(string a) {
    if (a == ".-") return 'A'; if (a == "---") return 'O';
    if (a == "-...") return 'B'; if (a == ".--.") return 'P';
    if (a == "-.-.") return 'C'; if (a == "--.-") return 'Q';
    if (a == "-..") return 'D'; if (a == ".-.") return 'R';
    if (a == ".") return 'E'; if (a == "...")return 'S';
    if (a == "..-.") return 'F'; if (a == "-") return 'T';
    if (a == "--.")return 'G'; if (a == "..-") return 'U';
    if (a == "....") return 'H'; if (a == "...-") return 'V';
    if (a == "..") return 'I'; if (a == ".--") return 'W';
    if (a == ".---") return 'J'; if (a == "-..-") return 'X';
    if (a == "-.-") return 'K'; if (a == "-.--") return 'Y';
    if (a == ".-..") return 'L'; if (a == "--..") return 'Z';
    if (a == "--") return 'M'; if (a == ".----") return '1';
    if (a == "-.") return 'N'; if (a == "..---") return '2';
    if (a == "-....") return '6'; if (a == "...--") return '3';
    if (a == "--...") return '7'; if (a == "....-") return '4';
    if (a == "---..") return '8'; if (a == ".....") return '5';
    if (a == "----.")return '9'; if (a == "-----") return '0';
    return 'N';
}
int main(int argc, char* argv[]) {
    string in1, out1;
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);
    char mode = argv[3][0];
    if (mode == 'e') {
        string a, b;
        while (getline(infile, a)) {
            for (int i = 0; i < a.length(); i++) {
                outfile << decode(a[i]) << ((a[i] != ' ' && a[i + 1] == ' ') ? "       " : ((a[i] != ' ') ? "   " : ""));
                string str2 = decode(a[i]);
            }
            outfile << endl;
        }
    }
    if (mode == 'd') {
        string a, b;
        while (getline(infile, a)) {
            for (int i = 0; i < a.length(); i++) {
                if ((a[i] == '-' || a[i] == '.') && a[i + 1] == ' ' && a[i + 2] == ' ' && a[i + 3] == ' ' && a[i + 4] == ' ') {
                    a.erase(i + 2, 6);
                    a[i + 1] = ',';
                }
            }
            for (int i = 0; i < a.length(); ) {
                stringstream ss1;
                int nu = a.find(',', i);
                if (nu == -1) nu = a.length() ;
                ss1.str(a.substr(i, nu - i));
                while (ss1 >> b)
                    outfile << encode(b);
                outfile << " ";
                i = nu + 1;
            }
            outfile << endl;
        }
    }
}


