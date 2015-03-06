#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int possible[3];
	scanf("%d %d %d %d", &n, possible, possible + 1, possible + 2);

	int num[n + 1];
	num[0] = 0;
	fill(num + 1, num + n + 1, -1);

	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(num[i] != -1 && i + possible[j] <= n)
				num[i + possible[j]] = max(num[i + possible[j]], num[i] + 1);
		}
	}

	printf("%d\n", num[n]);
}