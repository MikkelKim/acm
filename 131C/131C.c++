#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n, m, t;
	scanf("%d %d %d", &n, &m, &t);

	long long btable[n + 1][n + 1];
	long long gtable[m + 1][m + 1];

	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= n; ++j) {
			btable[i][j] = 0;
		}
	}

	for(int i = 0; i <= m; ++i) {
		for(int j = 0; j <= m; ++j) {
			gtable[i][j] = 0;
		}
	}

	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= i; ++j) {
			if(j == 0) {
				btable[i][j] = 1;
			} else {
				btable[i][j] = (btable[i - 1][j - 1] + btable[i - 1][j]);
			}
		}
	}

	for(int i = 0; i <= m; ++i) {
		for(int j = 0; j <= i; ++j) {
			if(j == 0) {
				gtable[i][j] = 1;
			} else {
				gtable[i][j] = (gtable[i - 1][j - 1] + gtable[i - 1][j]);
			}
		}
	}

	long long ret = 0;
	for(int i = 4; i <=	n; ++i) {
		if(t - i > 0 && t - i <= m) {
			ret += btable[n][i] * gtable[m][t - i];
		} 
	}
	cout << ret << endl;
}