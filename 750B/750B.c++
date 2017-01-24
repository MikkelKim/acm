#include <iostream>
#include <string>

using namespace std;

const int MAX = 20000;

int main() {
	int n;
	scanf("%d", &n);

	int t;
	string dir;
	int currentLocation = 0;
	for(int i = 0; i < n; ++i) {
		cin >> t >> dir;

		if(currentLocation == 0) {
			if(dir == "North" || dir == "East" || dir == "West") {
				cout << "NO" << endl;
				return 0;
			}
		} else if(currentLocation == MAX) {
			if(dir == "South" || dir == "East" || dir == "West") {
				cout << "NO" << endl;
				return 0;
			}
		}

		if(dir == "North") {
			currentLocation -= t;
			if(currentLocation < 0) {
				cout << "NO" << endl;
				return 0;
			}
		} else if(dir == "South") {
			currentLocation += t;
			if(currentLocation > MAX) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	if(currentLocation != 0) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	return 0;
}