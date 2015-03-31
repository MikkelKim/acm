#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int a, b, s;
	scanf("%d %d %d", &a, &b, &s);

	if(a < 0) {
		a *= -1;
	}

	if(b < 0) {
		b *= -1;
	}

	int possible = s - a - b;
	if(possible >= 0) {
		if((possible & 0x1) == 0) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
}