#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int potential = (n + m) / 3;
	if(potential <= min(n, m)) {
		cout << potential << endl;
	} else {
		cout << min(n, m) << endl;
	}
}