#include<fstream>
#include<iomanip>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    char *infile = argv[1];
    char *outfile = argv[2];
    ifstream in_file(infile);
    if(in_file.fail())
    {
        cout << "File " << infile << " does not exist !!" << endl;
        exit(1);
    }
    double sum=0, num, count=0;
    char ch;
    string word;
    in_file.get(ch);
    while(!in_file.eof()){
        if(ch == ':'){
            ch = in_file.peek();
            if((ch>='0')&&(ch<='9')){
                in_file >> num;
                sum += num;
                count ++;
            }else {
                count ++;
            }
        }
        in_file.get(ch);
    }
    ofstream out_file(outfile);
    out_file << fixed << setprecision(4) << "The average is: " << sum/count;
    out_file.close();
    in_file.close();

return 0;
}
