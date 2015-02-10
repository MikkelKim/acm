#include <stack>
#include <queue>
#include <stdio.h>
#include <iostream>

using namespace std;

long long* _d;

class compareDist {
public:
    bool operator()(int a, int b) {
       	if(_d[a] > _d[b])
       		return true;
       	return false;
    }
};

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	bool visit[n+1];
	fill(visit, visit + n + 1, false);

	long long dist[n+1]; // might overflow?
	fill(dist, dist + n + 1, 1000000000000);

	int path[n+1]; 

	_d = dist;

	int counter[n+1];
	int graph[n+1][15];
	int weight[n+1][15];
	fill(counter, counter + n + 1, 0);

	int a, b, w;

	for(int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &w);

		graph[a][counter[a]] = b;
		graph[b][counter[b]] = a;
		weight[a][counter[a]] = w;
		weight[b][counter[b]] = w;

		++counter[a];
		++counter[b];
	}

	priority_queue<int, deque<int>, compareDist> q;
	path[1] = -1;
	dist[1] = 0;
	q.push(1);

	int cur, temp;

	stack<int> sp;

	while(!q.empty()) {
		cur = q.top();
		q.pop();

		if(cur == n) {
			sp.push(n);
			while(path[cur] != -1) {
				sp.push(path[cur]);
				cur = path[cur];
			}
			while(!sp.empty()) {
				printf("%d ", sp.top());
				sp.pop();
			}
			printf("\n");
			return 0;
		}
		if(!visit[cur]) {
			for(int i = 0; i < counter[cur]; ++i) {
				temp = graph[cur][i];
				if(visit[temp])
					continue;

				if(dist[temp] > dist[cur] + weight[cur][i]) {
					dist[temp] = dist[cur] + weight[cur][i];
					path[temp] = cur;
					q.push(temp);
				}
			}

			visit[cur] = true;
		}
	}

	puts("-1");
}