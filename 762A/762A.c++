#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;

	if(k > n) {
		cout << -1 << endl;
		return 0;
	}

	long long c = 0;
	double sqrtn = sqrt(n);
	stack<long long> smallDivisors;
	for(long long i = 1; i <= sqrtn; ++i) {
		if(n % i == 0) {
			smallDivisors.push(i);
			++c;
		}

		if(c == k) {
			cout << i << endl;
			return 0;
		}
	}

	long long top;
	if(!smallDivisors.empty()) {
		top = smallDivisors.top();
		if(sqrtn == top) {
			smallDivisors.pop();
		}
	}

	while(!smallDivisors.empty()) {
		top = smallDivisors.top();
		smallDivisors.pop();

		++c;
		if(c == k) {
			cout << n / top << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}
