#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int f = 1;
	int l = n;
	int m = (l + f) / 2;

	int min = n;
	int cur, tea;
	long long iter;

	while(f <= l) {
		cur = 0;
		iter = 1;

		do {
			tea = m / iter;
			cur += tea;
			iter *= k;
		} while(tea != 0);
		if(cur >= n) {
			l = m - 1;
			if(m < min)
				min = m;
		} else {
			f = m + 1;
		}
		m = (l + f) / 2;
	}

	cout << min << endl;
}