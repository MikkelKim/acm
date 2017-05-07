#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const int mod = 1e9 + 7;;

int main() {
	string s;
	cin >> s;

	int count = 0;
	int start = 0;
	for (; start < s.size(); ++start) {
		if (s[start] == 'a') {
			break;
		}
	}

	long tempCount = 1;
	for (; start < s.size(); ++start) {
		if(s[start] == 'a') {
			tempCount *= 2;
			if (tempCount > mod) {
				tempCount -= mod;
			}
		} else {
			count += tempCount - 1;
			count %= mod;
		}
	}

	cout << count << endl;
	return 0;
}