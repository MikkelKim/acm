#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	scanf("%d\n%d", &n, &m);

	int a[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}

	sort(a, a + n);

	int count = 0;
	for(int i = n - 1; i >= 0; --i) {
		m -= a[i];
		++count;

		if(m <= 0) {
			break;
		}
	} 

	cout << count << endl;

	return 0;
}