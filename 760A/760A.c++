#include <iostream>

using namespace std;

int main() {
	int m, d;
	cin >> m >> d;

	int remainingDays;
	int numColumns = 1;
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		remainingDays = 31 - (8 - d);
	} else if(m == 2) {
		remainingDays = 28 - (8 - d);
	} else {
		remainingDays = 30 - (8 - d);
	}

	numColumns += remainingDays / 7;
	if(remainingDays % 7 != 0) {
		++numColumns;
	}

	cout << numColumns << endl;
}