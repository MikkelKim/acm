#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	bool on[m + 1];
	for(int i = 0; i <= m; ++i) {
		on[i] = false;
	}

	int x, y;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);

		for(int j = 0; j < x; ++j) {
			scanf("%d", &y);

			if(!on[y]) {
				--m;
				on[y] = true;

				if(m == 0) {
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}

	cout << "NO" << endl;
	return 0;
}