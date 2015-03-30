#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int solve(unordered_map<int, unordered_map<int, unordered_set<int>>> map, int i) {
	int size, t;
	int ret = 0;

	while(true) {
		if(i == 4) {
			i = 1;
		}

		while(true) {
			auto b = map[i].begin();
			auto e = map[i].end();
			vector<int> removed;
			t = ret;

			while(b != e) {
				if(b->second.size() == 0) {
					removed.push_back(b->first);
					++ret;
				}

				++b;
			}

			for(int k = 0; k < removed.size(); ++k) {
				map[i].erase(removed[k]);
			}

			if(ret == t) {
				break;
			}

			for(int k = 1; k < 4; ++k) {
				auto x = map[k].begin();
				auto y = map[k].end();

				while(x != y) {
					for(int j = 0; j < removed.size(); ++j) {
						x->second.erase(removed[j]);
					}
					++x;
				}
			}
		}

		size = map[1].size() + map[2].size() + map[3].size();
		if(size == 0) {
			break;
		}

		++ret;
		++i;
	}

	return ret;
}

int main() {
	int n;
	scanf("%d", &n);

	int where[n + 1];
	for(int i = 1; i <= n; ++i) {
		scanf("%d ", where + i);
	}

	int num, depend;
	unordered_map<int, unordered_map<int, unordered_set<int>>> map;
	for(int i = 1; i <= n; ++i) {
		scanf("%d ", &num);
		(map[where[i]])[i] = {};
		for(int j = 0; j < num; ++j) {
			scanf("%d ", &depend);
			(map[where[i]])[i].insert(depend);
		}
	}

	printf("%d\n", min(solve(map, 1), min(solve(map, 2), solve(map, 3))));
}