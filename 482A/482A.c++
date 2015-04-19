#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	bool odd = true;

	int b = 1;
	int e = n;

	for(int i = 0; i < k; ++i) {
		if(odd) {
			printf("%d ", b);
			odd = false;
			++b;
		} else {
			printf("%d ", e);
			odd = true;
			--e;
		}
	}

	int limit = n - k;
	if(odd) {
		for(int i = 0; i < limit; ++i) {
			printf("%d ", e);
			--e;
		}
	} else {
		for(int i = 0; i < limit; ++i) {
			printf("%d ", b);
			++b;
		}
	}

	printf("\n");
}