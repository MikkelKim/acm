#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	while(n > 0) {
		int a, b;
		scanf("%d %d", &a, &b);

		long long ret = 0;

		if(b < a) {
			swap(a, b);
		}

		while(a != 0) {
			ret += b / a;
			b = b % a;
			if(b < a) {
				swap(a, b);
			}
		}

		cout << ret << endl;

		--n;
	}
}