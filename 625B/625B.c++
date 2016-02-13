#include <stdio.h>

char g[1000001]; 
char p[31];

int main() {
	scanf("%s", g);
	scanf("%s", p);

	int numReplaces = 0;

	int i = 0;
	while(g[i]) {
		int j = 0;
		if(g[i] == p[j]) {
			int k = i;
			do {
				++k;
				++j;
			} while(g[k] && p[j] && g[k] == p[j]);

			if(!p[j]) {
				++numReplaces;
				i = k;
				continue;
			}
		}
		++i;
	}

	printf("%d\n", numReplaces);
	return 0;
}