#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
	string str;

	while (1) {
		cout << "Enter the sentence: ";
		getline(cin, str);
		if (str == "Stop the program")break;

		vector<string> vec = {""};
		
		for (size_t i = 0; i < str.size(); i++) {
			if (isalpha(str[i])) {
				vec.back().push_back(str[i]);
			}
			else {
				if(!vec.back().empty())vec.push_back("");
			}
		}

		if (vec.back().empty())vec.pop_back();

		reverse(vec.begin(), vec.end());

		for (size_t i = 0; i < vec.size(); i++) {
			cout << vec[i];
			if (i != vec.size() - 1)cout << " ";
		}
		cout << endl;
	}

	return 0;
}
