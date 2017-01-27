#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	char c;
	int space = 0;
	bool firstHit = false;
	for(int i = 0; i < n; ++i) {
		cin >> c;
		if(firstHit && space == k) {
			if(c == 'G' || c == 'T') {
				cout << "YES" << endl;
				return 0;
			} else if(c == '#') {
				cout << "NO" << endl;
				return 0;
			}
			space = 0;
		}

		if(c == 'G' || c == 'T') {
			firstHit = true;
			space = 0;
		}
		++space;
	}

	cout << "NO" << endl;
}