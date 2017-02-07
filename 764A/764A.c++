#include <iostream>
#include <numeric>

using namespace std;

long long gcd(long long n, long long m) {
	while(m != 0) {
		long long temp = m;
		m = n % m;
		n = temp;
	}
	return n;
}

long long lcm(long long n, long long m) {
	return n * m / gcd(n, m);
}

int main() {
	long long n, m, z;
	cin >> n >> m >> z;

	long long hcf = n > m ? lcm(n, m) : lcm(m, n);

	cout << z / hcf << endl;
}
