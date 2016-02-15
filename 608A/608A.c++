#include <stdio.h>
#include <iostream>

using namespace std;

int max(int a, int b) {
	if(a >= b) {
		return a; 
	} else {
		return b;
	}
}

int main() {
	int n, s;
	scanf("%d %d", &n, &s);

	int f, t;
	int minTimeRequired = s;
	for(int i = 0; i < n; ++i) {
		scanf("%d %d", &f, &t);

		minTimeRequired = max(minTimeRequired, f + t);
	}

	cout << minTimeRequired << endl;

	return 0;
}