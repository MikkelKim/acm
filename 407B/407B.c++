#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int p[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d", p + i);
	}

	long long visit[n];
	fill(visit, visit + n, 2);

	for(int i = 1; i < n; ++i) {
		if(p[i] - 1 != i) {
			for(int j = p[i] - 1; j < i; ++j) {
				visit[i] += visit[j];
			}
			if(visit[i] > 1000000007) {
				visit[i] %= 1000000007;
			}
		}
	}

	long long path = 0;
	for(int i = 0; i < n; ++i) {
		path += visit[i];
	}

	printf("%lld\n", path % 1000000007);
}