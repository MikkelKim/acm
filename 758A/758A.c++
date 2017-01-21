#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int a[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d ", a + i);
	}

	int tot = 0;
	int max = a[0];
	for(int i = 1; i < n; ++i) {
		if(a[i] > max) {
			tot += (a[i] - max) * i;
			max = a[i];
		} else {
			tot += max - a[i];
		}
	}

	printf("%d\n", tot);
}