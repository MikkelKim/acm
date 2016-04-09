#include <iostream>

using namespace std;

int gcd(int m, int n) {
    if(m == 0 && n == 0)
        return -1;

    if(m < 0) m = -m;
    if(n < 0) n = -n;

    int r;
    while(n) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

bool isCoPrime(int a, int b) {
	return gcd(a, b) == 1 ? true : false;
}

int main() {
	int n;
	cin >> n;

	int a[n];
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int c = 0;
	int p[n];
	for(int i = 0; i < n - 1; ++i) {
		if(!isCoPrime(a[i], a[i + 1])) {
			p[c] = i;
			++c;
		}
	}
	cout << c << endl;

	int j = 0;
	for(int i = 0; i < n - 1; ++i) {
		cout << a[i] << " ";
		if(c > 0 && p[j] == i) {
			cout << 1 << " ";
			++j;
		}
	}
	cout << a[n - 1] << endl;
}
