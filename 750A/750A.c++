#include <iostream>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int numMinLeft = 240 - k;
	int numProblemsSolved = 0;

	for(int i = 1; i <= n && numMinLeft > 0; ++i) {
		numMinLeft -= 5 * i;
		if(numMinLeft < 0) {
			break;
		} else {
			++numProblemsSolved;
		}
	} 

	cout << numProblemsSolved << endl;
}