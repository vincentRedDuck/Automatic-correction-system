#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char **argv) {
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	

	string url;
	while(getline(fin, url)) {
        fout << "=====" << endl;
		stringstream sin(url);
		string domain, http;
        getline(sin, http, '/');
        char ch; sin >> ch;
        getline(sin, domain, '/');
		fout << "Domain name: " << domain << endl;

		string method;
		getline(sin, method, '?');
		int slash = -1;
		for(int i=0; i<method.size(); i++) {
			if(method[i]=='/') {
				slash = i;
			}
		}
		if(slash!=-1) {
			method = method.substr(slash+1, method.size()-slash-1);
		}
		fout << "Method: " << method << endl;

		string str, str1, str2;
		while(getline(sin, str, '&')) {
			for(int i=0; i<str.size(); i++) {
				if(str[i]=='=') {
					str1 = str.substr(0, i);
					str2 = str.substr(i+1, str.size()-i-1);
				}
			}
            if(str1!="" && str2!="")
                fout << str1 << ": " << str2 << endl;
		}

	}
	fout << "=====" << endl;

	return 0;
}
