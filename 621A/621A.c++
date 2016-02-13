#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n;
	int number;
	int smallestOdd = 1000000001;

	long long s = 0;

	scanf("%d", &n);

	for(int i = 0; i < n; ++i) {
		scanf("%d", &number);

		if(number > 0) {
			s += number;
			if(number % 2 != 0) {
				if(number <  smallestOdd) {
					smallestOdd = number;
				}
			}
		}
	}

	if(s % 2 != 0) {
		if(smallestOdd == 1000000001) {
			s = 0;
		} else {
			s -= smallestOdd;
		}
	}
	
	cout << s << endl;
	return 0;
}