#include <stdio.h>

int size = 1;
char b[1000001]; 

int main() {
	scanf("%s", b);

	int steps = 0;
	int numShift = 0;

	bool isOne = true;
	bool atLeast = false;

	while(b[size]) {
		if(b[size] - '0') {
			if(!isOne) {
				steps += numShift;
				numShift = 0;
			}
			isOne = true;
			atLeast = true;
		} else {
			++numShift;
			isOne = false;
		}
		++steps;
		++size;
	}

	if(steps && atLeast)
		steps += 2;

	printf("%d\n", steps);
}