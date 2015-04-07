#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	if(n == k) {
		printf("-1\n");
		return 0;
	}

	int diff = n - k;
	printf("%d ", diff);
	for(int i = 1; i < diff; ++i) {
		printf("%d ", i);
	}

	for(int i = diff + 1; i <= n; ++i) {
		printf("%d ", i);
	}

	printf("\n");
}