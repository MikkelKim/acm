#include <stdio.h>
#include <iostream>

using namespace std;

const char black[] = "BBBBBBBB";

int main() {
	char b[8][8];
	int count = 0;

	for(int i = 0; i < 8; ++i) {
		for(int j = 0; j < 8; ++j)
			b[i][j] = getchar();
		getchar();
	}

	int j;
	for(int i = 0; i < 8; ++i) {
		if(equal(b[i], b[i] + 8, black))
			++count;

		j = 0;
		for(; j < 8; ++j) {
			if(b[j][i] != black[i])
				break;
		}
		if(j == 8)
			++count;
	}

	if(count < 15)
		printf("%d\n", count);
	else
		printf("8\n");
}