#include <cmath>
#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

inline double factorial(int x) {
  return (x == 1 || x == 0) ? 1 : x * factorial(x - 1);
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	
	int p1 = count(s1.begin(), s1.end(), '+');
	int p2 = count(s2.begin(), s2.end(), '+');
	int m1 = count(s1.begin(), s1.end(), '-');
	int m2 = count(s2.begin(), s2.end(), '-');

	if(p1 == p2 && m1 == m2) {
		cout << 1 << endl;
	} else if(p2 > p1 || m2 > m1) {
		cout << 0 << endl;
	} else {
		int p = p1 - p2;
		int m = m1 - m2;
		int t = p + m;
		
		double ans = factorial(t) / (factorial(p) * factorial(m));
		ans = ans * pow(0.5, t);
		printf("%.10f\n", ans);
	}
}
