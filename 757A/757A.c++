#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string Bulbasaur("Bulbasr");

	string s;
	getline(cin, s);

	int count[Bulbasaur.size()];
	fill(count, count + 7, 0);	

	for(int i = 0; i < s.size(); ++i) {
		for(int j = 0; j < Bulbasaur.size(); ++j) {
			if(s[i] == Bulbasaur[j]) {
				++count[j];
			}
		}
	}

	count[1] = count[1] / 2;
	count[4] = count[4] / 2;

	printf("%d\n", *min_element(count, count + 7));
}