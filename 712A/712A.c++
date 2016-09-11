#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int a[n];
	int b[n];

	for(int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}

	for(int i = 0; i < n - 1; ++i) {
		printf("%d ", a[i] + a[i + 1]);
	}
	printf("%d\n", a[n - 1]);
}