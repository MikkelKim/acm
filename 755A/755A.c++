#include <iostream>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	if(n > 2) {
		// n(n - 2) + 1 = n^2 - 2n + 1 = (n - 1)^2. Thus not prime.
		printf("%d\n", n - 2);
	} else {
		printf("7\n");
	}
}