#include <iostream>

using namespace std;

long long max(long long a, long long b) {
	if(abs(a) > abs(b)) {
		return abs(a);
	} else {
		return abs(b);
	}
}

int main() {
	long long x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	long long a = x2 - x1;
	long long b = y2 - y1;

	cout << max(a, b) << endl;

	return 0;
}