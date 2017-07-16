#include <unordered_map>
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main() {
	string firstLayout, secondLayout, s;
	cin >> firstLayout >> secondLayout >> s;

	unordered_map<char, char> layoutMap;
	for(int i = 0; i < 26; ++i) {
		layoutMap[firstLayout[i]] = secondLayout[i];
		layoutMap[toupper(firstLayout[i])] = toupper(secondLayout[i]);
	}

	int outputLength = s.length();
	for(int i = 0; i < outputLength; ++i) {
		if(isalpha(s[i])) {
			cout << layoutMap[s[i]];
		} else {
			cout << s[i];
		}
	}
	cout << endl;
}
