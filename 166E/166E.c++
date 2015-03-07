#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	if(n == 1) {
		printf("0\n");
		return 0;
	}

	long long prev = 0;
	long long answer = 3;

	long long temp;

 	for(int i = 3; i <= n; ++i) {
 		temp = answer;
 		answer = (prev * 3 + (answer << 1));
 		if(answer > 1000000007)
 			answer %= 1000000007;
 		prev = temp;
 	}
 	

 	cout << answer << endl;
}