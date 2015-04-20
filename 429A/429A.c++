#include <queue>
#include <vector>
#include <utility>
#include <stdio.h>
#include <iostream>
#include <unordered_map>

using namespace std;

void bfs(unordered_map<int, vector<int>>& tree, char* init, char* goal, int node, int flip, vector<int>& ans) {
	if(flip == 0 && init[node] == goal[node]) {
		return;
	}

	if(flip % 2 == 1) {
		if(init[node] == '0') {
			init[node] = '1';
		} else {
			init[node] = '0';
		}
	}

	if(init[node] != goal[node]) {
		++flip;
		ans.push_back(node);

		if(init[node] == '0') {
			init[node] = '1';
		} else {
			init[node] = '0';
		}
	}

	auto b = tree[node].begin();
	auto e = tree[node].end();

	while(b != e) {
		auto x = tree[*b].begin();
		auto y = tree[*b].end();

		while(x != y) {
			bfs(tree, init, goal, *x, flip, ans);
			++x;
		}

		++b;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	unordered_map<int, vector<int>> tree = {{1, vector<int>()}};

	int u, v;
	for(int i = 1; i < n; ++i) {
		scanf("%d %d", &u, &v);
		if(tree.find(u) != tree.end()) {
			tree[u].push_back(v);
			tree.insert(make_pair(v, vector<int>()));
		} else {
			tree[v].push_back(u);
			tree.insert(make_pair(u, vector<int>()));
		}
	}

	char init[n + 1];
	char goal[n + 1];

	scanf("%c", init);
	for(int i = 1; i <= n; ++i) {
		scanf("%c ", init + i);
	}

	for(int i = 1; i <= n; ++i) {
		scanf("%c ", goal + i);
	}

	vector<int> ans;
	queue<int> q;
	q.push(1);
	int temp;

	while(!q.empty()) {
		temp = q.front();
		q.pop();

		bfs(tree, init, goal, temp, 0, ans);
		auto x = tree[temp].begin();
		auto y = tree[temp].end();

		while(x != y) {
			q.push(*x);
			++x;
		}
	}

	auto x = tree[1].begin();
	auto y = tree[1].end();

	cout << ans.size() << endl;
	auto b = ans.begin();
	auto e = ans.end();

	while(b != e) {
		printf("%d\n", *b);
		++b;
	}
}
