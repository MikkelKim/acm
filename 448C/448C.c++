#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long min_stroke(long long* a, int n) {
	if(n == 1)
		return 1;

	long long min = *min_element(a, a+n);

	if(min == 0)
		return 0;

	int prev = 0;
	long long temp = 0;
	long long count = 0;

	for(int i = 0; i < n; ++i) {
		a[i] -= min;
		if(a[i] == 0) {
			if(i - prev > 0)
				temp += min_stroke(a + prev, i - prev);
			prev = i + 1;
		}
	}
	if(n - prev > 0)
		temp += min_stroke(a + prev, n - prev);

	if(min + temp <= n) {
		count += min + temp;
	} else {
		count += n;
	}

	return count;
}

int main() {
	int n;
	scanf("%d", &n);

	long long a[n];
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cout << min_stroke(a, n) << endl;;
}