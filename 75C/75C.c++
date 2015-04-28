#include <cmath>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	int c;
	while(a != 0) {
	    c = a; 
	    a = b % a;  
	    b = c;
	}
	return b;
}

int main() {
	int a, b, n;
	scanf("%d %d\n%d", &a, &b, &n);

	int g = gcd(a, b);
	vector<int> factors;
	vector<int> temp;

	int sq = ceil(sqrt(g));
	for(int i = 1; i < sq; ++i) {
		if(g % i == 0) {
			factors.push_back(i);
			temp.push_back(g / i);
		}
	}

	if(g % sq == 0) {
		factors.push_back(sq);
	}
	factors.insert(factors.end(), temp.rbegin(), temp.rend());

	int low, high;
	while(n > 0) {
		--n;
		scanf("%d %d", &low, &high);

		if(low > g) {
			printf("-1\n");
			continue;
		} else {
			if(high >= g) {
				printf("%d\n", g);
				continue;
			}
		}

		auto c = upper_bound(factors.begin(), factors.end(), high);
		if(c != factors.begin()) {
			--c;
			if(*c <= high && *c >= low) {
				printf("%d\n", *c);
				continue;
			} 
		}
		printf("-1\n");
	}
}