#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void parseCoord (char coord [], int &x, int &y) {
	x = 0;
	y = 0;
	bool minus = 0;
	int i = 0;

	for (i = 1; coord[i] != ','; i++) {
		if (coord[i] == '-'){
			minus = 1;
			continue;
		}
		x *= 10;
		x += int(coord[i]) - 48;	
	}
	if (minus == 1) x *= -1;
	i++;
	for (; coord[i] != ')'; i++) {
		if (coord[i] == '-'){
			minus = 1;
			continue;
		}
		y *= 10;
		y += int(coord[i]) - 48;	
	}
	if (minus == 1) y *= -1;
}

int main() {
	char coord1[100];
	char coord2[100];
	int x1, x2, y1, y2 = 0;

	while (true) {
		cout << "Enter first point:";
		cin >> coord1;
		cout << "Enter second point:";
		cin >> coord2;
		
		parseCoord (coord1, x1, y1);
		parseCoord (coord2, x2, y2);
		
		if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0) {
			break;
		}

		cout << "Distance: " << pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5) << endl;
	}

	return 0;
}
