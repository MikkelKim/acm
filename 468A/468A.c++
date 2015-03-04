#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

string s4 = "4 * 3 = 12\n12 * 2 = 24\n24 * 1 = 24";
string s5 = "5 * 3 = 15\n2 * 4 = 8\n15 + 8 = 23\n23 + 1 = 24";

int main() {
	int n;
	scanf("%d", &n);

	if(n < 4) {
		printf("NO\n");
		return 0;
	} 

	int num;
	printf("YES\n");
	if(n & 0x00000001) {
		num = (n - 5) / 2;
		for(int i = 0; i < num; ++i) {
			printf("%d - %d = 1\n", n, n - 1);
			n -= 2;
		}
		printf("%s\n", s5.c_str());
	} else {
		num = (n - 4) / 2;
		for(int i = 0; i < num; ++i) {
			printf("%d - %d = 1\n", n, n - 1);
			n -= 2;
		}
		printf("%s\n", s4.c_str());
	}

	for(int i = 0; i < num; ++i) {
		printf("24 * 1 = 24\n");
	}

}