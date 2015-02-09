#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n, p;
	scanf("%d %d", &n, &p);

	if(n == p) {
		puts("0");
		return 0;
	}

	int a, b, d;
	int sToD[n+1];
	int dToS[n+1];
	int dia[n+1];

	fill(sToD, sToD + n + 1, -1);
	fill(dToS, dToS + n + 1, -1);

	for(int i = 0; i < p; ++i) {
		scanf("%d %d %d", &a, &b, &d);
		sToD[a] = b;
		dToS[b] = a;
		dia[a] = d;
	}

	int sink, min, cur;
	int count = 0;
	int tank[p];
	int tap[p];
	int di[p];

	bool gotIn;

	for(int i = 1; i < n+1; ++i) {
		if(dToS[i] == -1) {
			cur = dia[i];
			min = 1000000;
			gotIn = false;
			sink = sToD[i];
			tank[count] = i;
			while(sink != -1) {
				if(!gotIn)
					gotIn = true;
				if(min > cur) {
					min = cur;
				}
				cur = dia[sink];
				tap[count] = sink;
				sink = sToD[sink];
			}

			if(!gotIn)
				continue;

			di[count] = min;
			++count;
		}
	}

	printf("%d\n", count);
	for(int i = 0; i < count; ++i) {
		printf("%d %d %d\n", tank[i], tap[i], di[i]);
	}
}