//******************************
// File name: ex12-1.cpp
// Author: stu109101006
// Date: 2021/12/27
//******************************

#include <iostream>
#include <iomanip>

using namespace std;

void PrintArray(int**, int);
void BuildArray(int**, int);

int main () {
	int size = 0;	// Size of array
	
	int **array; 	// Array for output

	cin >> size;
	
	while (size != -1) {
		// Create blank array

		array = new int *[size];
		for (int i = 0; i < size; i++) {
			array[i] = new int [size]; //Why no * ?
		}

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				array[i][j] = 0;		
			}
		}

		
		// Build and print array

		BuildArray(array, size);
		PrintArray(array, size);


		// Delete memory to release memory

		for (int i = 0; i < size; i++) {
			delete [] array [i];
		}
		delete [] array;

		cin >> size;
	}


	return 0;
}

void BuildArray (int **array, int size) {
	bool turn = 0;
	short dx = 0;
	short dy = 0;
	short posx = 0;
	short posy = 0;
	int area = size * size;
	int num = 0;	// Current number

	num = -1;	// Number starts from 1

	dx = 1;
	dy = 0;
	posx = -1;
	posy = 0;

	for (int i = 0; i < area; i++) {
		// Calculate current position

		// - Check for Position
		turn = 0;
		if (posy + dy < 0 || posy + dy >= size) turn = 1;
		else if (posx + dx < 0 || posx + dx >= size) turn = 1;
		else if (array[posy + dy][posx + dx] != 0) turn = 1;


		// - Change direction if needed
		if (turn) {
			if (dx == 1 && dy == 0) {
				dx = 0;
				dy = 1;
			}
			else if (dx == 0 && dy == 1) {
				dx = -1;
				dy = 0;
			}
			else if (dx == -1 && dy == 0) {
				dx = 0;
				dy = -1;
			}
			else if (dx == 0 && dy == -1) {
				dx = 1;
				dy = 0;
			}
			else cerr << "FALSE TURNING: " << dx << ", " << dy << endl;
		}


		// - Move
		posx += dx;
		posy += dy;


		// Calculate current number
		num += 2;
		if (num > area) num = 2;


		// Write number to cell
		array[posy][posx] = num;

		// cout << posy << ", " << posx << "  dx, dy = " << dx << ", " << dy << endl;
	}
	
}

void PrintArray (int **array, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << setw(5) << right
				<< array[i][j];
		}
		cout << endl;
	}
}
