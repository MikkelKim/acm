#include <iostream>

using namespace std; 

int main() {
	int n;
	cin >> n;

	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (count < 2) {
			cout << 'a';
		} else {
			cout << 'b';
			if (count == 3) {
				count = -1;
			}
		}
		++count;
	}
	cout << endl;
	return 0;
}