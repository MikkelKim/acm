#include <stack>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool dfs(unordered_map<int, vector<int>>& map, int a, int b) {
	unordered_set<int> visit;
	stack<int> s;
	s.push(a);
	int cur;

	while(!s.empty()) {
		cur = s.top();
		s.pop();
		visit.insert(cur);

		for(int i = 0; i < map[cur].size(); ++i) {
			if(map[cur][i] == b) {
				return true;
			}

			if(visit.find(map[cur][i]) == visit.end()) {
				s.push(map[cur][i]);
			}
		}
	}

	return false;
}

int main() {
	int n;
	scanf("%d", &n);

	int i1[n];
	int i2[n];
	int a, x, y;
	int index = 0;
	unordered_map<int, vector<int>> map;

	while(n > 0) {
		scanf("%d %d %d", &a, &x, &y);

		if(a == 1) {
			++index;
			i1[index] = x;
			i2[index] = y;

			for(int i = 1; i < index; ++i) {
				if((i1[i] > x && i1[i] < y) || (i2[i] > x && i2[i] < y)) {
					map[i].push_back(index);
				}

				if((x > i1[i] && x < i2[i]) || (y > i1[i] && y < i2[i])) {
					map[index].push_back(i);
				}
			}
		} else {
			if(dfs(map, x, y)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}

		--n;
	}
}