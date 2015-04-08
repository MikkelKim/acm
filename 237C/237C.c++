#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a, b, k;
	cin >> a >> b >> k;

	bool prime[b + 1];
	int numPrime[b - a + 2];
	fill(prime + 2, prime + b + 1, true);

	int constant;
	int limit = sqrt(b) + 1;

	prime[1] = false;
	for(int i = 4; i <= b; i += 2) {
		prime[i] = false;
	}

	for(int i = 3; i <= limit; i += 2) {
		if(prime[i]) {
			constant = 2 * i;
			for(int j = 3 * i; j <= b; j += constant) {
				prime[j] = false;
			}
		}
	}

	int j = 0;
	int count = 0;
	for(int i = 1; i <= b; ++i) {
		if(i >= a) {
			numPrime[j] = count;
			++j;
		}

		if(prime[i]) {
			++count;
		}
	}
	numPrime[j] = count;

	if(numPrime[b - a + 1] - numPrime[0] < k) {
		cout << -1 << endl;
		return 0;
	}

	int* x = lower_bound(numPrime, numPrime + b - a + 2, numPrime[0] + k);
	int* end = numPrime + b - a + 2;
	int* begin = numPrime;
	int index = 0;

	while(x < end) {
		int low = *x - *begin;
		if(low < k) {
			x = lower_bound(begin, end, *begin + k);
		} else {
			++x;
			++begin;
			++index;
		}
	}

	cout << end - begin << endl;
}
