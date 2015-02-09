#include <queue>
#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	char l[n];
	char r[n];

	getchar(); // get \n
	for(int i = 0; i < n; ++i) {
		l[i] = getchar();
	}

	getchar(); // get \n
	for(int i = 0; i < n; ++i) {
		r[i] = getchar();
	}

	queue<int> index;
	queue<int> flood;
	queue<bool> left;

	bool l_visit[n];
	bool r_visit[n];

	fill(l_visit, l_visit + n, false);
	fill(r_visit, r_visit + n, false);

	index.push(0);
	flood.push(0);
	left.push(true);

	int cur_index, cur_flood;
	bool cur_left;

	while(!index.empty()) {
		cur_index = index.front();
		index.pop();
		cur_flood = flood.front();
		flood.pop();
		cur_left = left.front();
		left.pop();

		if(cur_index < 0)
			continue;

		if(cur_index < n) {
			if(cur_left) {
				if(l_visit[cur_index]) {
					continue;
				} else {
					l_visit[cur_index] = true;
				}
				if(l[cur_index] == 'X')
					continue;
			} else {
				if(r_visit[cur_index]) {
					continue;
				} else {
					r_visit[cur_index] = true;
				}
				if(r[cur_index] == 'X')
					continue;
			}
		}

		if(cur_index < cur_flood)
			continue;

		if(cur_index >= n) {
			puts("YES");
			return 0;
		}

		index.push(cur_index+1);
		index.push(cur_index-1);
		index.push(cur_index+k);

		flood.push(cur_flood+1);
		flood.push(cur_flood+1);
		flood.push(cur_flood+1);

		left.push(cur_left);
		left.push(cur_left);
		left.push(!cur_left);
	}

	puts("NO");
}