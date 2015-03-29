#include <vector>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int a, b;
	unordered_map<int, unordered_set<int>> map;
	for(int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		map[a].insert(b);
		map[b].insert(a);
	}

	size_t temp;
	int removed = 0;
	while(true) {
		vector<int> reprimand;

		auto x = map.begin();
		auto y = map.end();
		temp = map.size();

		while(x != y) {
			if((x->second).size() == 1) {
				reprimand.push_back(x->first);
			}

			++x;
		}

		for(int i = 0; i < reprimand.size(); ++i) {
			map.erase(reprimand[i]);
		}

		if(temp == map.size()) {
			break;
		}

		++removed;

		x = map.begin();
		y = map.end();

		while(x != y) {
			for(int i = 0; i < reprimand.size(); ++i) {
				(x->second).erase(reprimand[i]);
			}

			++x;
		}
	}

	printf("%d\n", removed);
}