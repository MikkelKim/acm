#include <string>
#include <iostream>

using namespace std;

int map[10];

int main() {
	string a, s;
	cin >> a >> s;

	int b = a.size();
	int c = s.size();

	for(int i = 0; i < c; ++i) {
		++map[s[i] - '0'];
	}

	int i = 0;
	int curr = 9;
	while(i < b) {
		if(map[curr] == 0) {
			--curr;
			if(curr == 0) {
				break;
			}
		} else {
			if(curr + '0' > a[i]) {
				a[i] = curr + '0';
				--map[curr];
			}
			++i;
		}
	}
	
	cout << a << endl;
}
