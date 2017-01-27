#include <iostream>
#include <string>

using namespace std;

int GetRightNumber(int digit, int notUsed) {
	int b, c;
	for(int i = 0; i < 10; ++i) {
		if(digit == 1) {
			cout << i << notUsed << notUsed << notUsed << endl;
		} else if(digit == 2) {
			cout << notUsed << i << notUsed << notUsed << endl;
		} else if(digit == 3) {
			cout << notUsed << notUsed << i << notUsed << endl;
		} else {
			cout << notUsed << notUsed << notUsed << i << endl;
		}

		cin >> b >> c;
		if(b == 1) {
			return i;
		}
	}
}

int main() {
	int b, c;
	string test[] = {"0000", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"};

	int notUsed;
	for(int i = 0; i < 10; ++i) {
		cout << test[i] << endl;
		cin >> b >> c;
		if(b == 0 && c == 0) {
			notUsed = i; 
			break;
		}
	}

	int st = GetRightNumber(1, notUsed);
	int nd = GetRightNumber(2, notUsed);
	int rd = GetRightNumber(3, notUsed);
	int th = GetRightNumber(4, notUsed);

	cout << st << nd << rd << th << endl;
}
