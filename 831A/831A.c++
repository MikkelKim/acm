#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	if(n > 2) {
		int prev = 0;
		int curr = 0;
		int state = 0;

		for(int i = 0; i < n; ++i) {
			cin >> curr;

			if(state == 0) {
				if(prev == curr) {
					++state;
				} else if(prev > curr) {
					state += 2;
				}
			} else if(state == 1) {
				if(prev > curr) {
					++state;
				} else if(prev < curr) {
					cout << "NO" << endl;
					return 0;
				}
			} else {
				if(prev == curr || prev < curr) {
					cout << "NO" << endl;
					return 0;
				}
			}

			prev = curr;
		}
	}

	cout << "YES" << endl;
}