#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;

	int size = s.size();
	if(size % 2 != 0) {
		cout << -1 << endl;
		return 0;
	}

	int l = 0;
	int r = 0;
	int u = 0;
	int d = 0;
	for(int i = 0; i < size; ++i) {
		if(s[i] == 'L') {
			++l;
		} else if(s[i] == 'R') {
			++r;
		} else if(s[i] == 'U') {
			++u;
		} else if(s[i] == 'D') {
			++d;
		}
	}

	cout << (abs(l - r) + abs(u - d)) / 2 << endl;
	return 0;
}