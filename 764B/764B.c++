#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int a[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d ", a + i);	
	}

	bool flag = false;
	for(int i = 0; i < n; ++i) {
		if(flag) {
			printf("%d ", a[i]);
		} else {
			printf("%d ", a[n - i - 1]);
		}

		if(i == n - i - 2) {
			flag = !flag;
		}
		flag = !flag;
	}
	cout << endl;
}
