#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class edge {
public :
	edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
	int u;
	int v;
};
int discovered[100001];
vector<int> edges[100001];
vector<edge> result;
int V, E, counter = 1;
priority_queue<edge> pq;

bool operator< (edge a, edge b) {
	if (a.u == b.u) return a.v > b.v;
	else return a.u > b.u;
}

int dfs(int parent, int u)
{
	discovered[u] = counter++;
	int ret = discovered[u];
	int subtree = 1000000000;
	
	for (int j = 0; j < edges[u].size(); j++) {
		int v = edges[u][j];
		
		if (parent == v)
			continue;

		if (discovered[v] == 0) {
			subtree = dfs(u, v);
			
			if (subtree > discovered[u]) 
				result.push_back(edge(u, v));

			ret = ret < subtree ? ret : subtree;
		}
		else {
			ret = ret < discovered[v] ? ret : discovered[v];
		}
	}
	return ret;
}

void dfs_all(void)
{
	memset(discovered, 0, sizeof(discovered));

	dfs(0, 1);

	for (int i = 0; i < result.size(); i++) {
		int tmp;
		if (result[i].u > result[i].v) {
			tmp = result[i].u;
			result[i].u = result[i].v;
			result[i].v = tmp;
		}
	}

	for (int i = 0; i < result.size(); i++) 
		pq.push(result[i]);

	printf("%lu\n", pq.size());
	while (!pq.empty()) {
		edge e = pq.top(); pq.pop();
		printf("%d %d\n", e.u, e.v);
	}
}
int main(void)
{
	int u, v;

	freopen("input_11400", "r", stdin);
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs_all();

	return 0;
}
