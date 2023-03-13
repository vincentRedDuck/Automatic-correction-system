#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    ifstream fd(argv[1]);
    double ans = 0;
    int cnt = 0;
    string tmp;
    while(getline(fd, tmp, '\n')){
        int pos = tmp.find(":");
        if(pos != tmp.length() - 1)
            ans += stoi(tmp.substr(pos + 1));
        cnt++;
    }
    fd.close();

    ofstream fd2(argv[2]);
    fd2 << fixed << setprecision(4) << "The average is: " << ans/cnt ;
    fd2.close();

    return 0;
}