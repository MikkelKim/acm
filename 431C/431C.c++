#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long sum(int* b, int* e) {
	long long ret = 0;
	while(b != e) {
		ret += *b;
		++b;
	}
	return ret % 1000000007;
}

int main() {
	int n, k, d;
	scanf("%d %d %d", &n, &k, &d);

	if(d > n) {
		cout << 0 << endl;
		return 0;
	}

	--d;

	int dp[n + 1];
	dp[0] = 0;

	int di[n];
	di[0] = 0;

	for(int i = 1; i <= d; ++i) {
		di[i] = 1 + sum(di + 1, di + i);
		if(i == n - 1) {
			break;
		}
	}

	for(int i = d + 1; i < n; ++i) {
		di[i] = sum(di + i - d, di + i);
	}

	for(int i = 1; i <= k; ++i) {
		dp[i] = 1 + sum(dp + 1, dp + i);
		if(i == n) {
			break;
		}
	}

	for(int i = k + 1; i <= n; ++i) {
		dp[i] = sum(dp + i - k, dp + i);
	}

	int ans = (dp[n] - sum(di + n - d, di + n));
	if(ans < 0) {
		ans += 1000000007;
	}

	cout << ans << endl;
}