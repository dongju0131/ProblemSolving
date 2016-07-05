#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> edge;
typedef pair<int, int> node;
vector<edge> edge_list[10001];
bool visit[10001];

int bfs_sub(int n)
{
	int max = 0;
	
	visit[n] = true;
	for (int i = 0; i < edge_list[n].size(); i++) {
		edge e = edge_list[n][i];
		if (visit[e.first])
			continue;
		
		int cur = bfs_sub(e.first) + e.second;
		max = cur > max ? cur : max;
	}

	return max;
}

int bfs(int n)
{
	priority_queue<int> pq;

	visit[n] = true;
	for (int i = 0; i < edge_list[n].size(); i++) {
		edge e = edge_list[n][i];
		pq.push(bfs_sub(e.first) + e.second);
	}

	int size = pq.size();
	int first = pq.top(); pq.pop();
	if (size == 1) return first;
	else return first + pq.top();
}

int main(void)
{
	int N, u, v, w;
	int max = 0;

	freopen("input_1967", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		scanf("%d %d %d", &u, &v, &w);
		edge_list[u].push_back(edge(v, w));
		edge_list[v].push_back(edge(u, w));
	}

	for (int i = 1; i <= N; i++) {
		memset(visit, false, sizeof(visit));
		int cur = bfs(i);
		max = cur > max ? cur : max;
	}

	printf("%d\n", max);
	return 0;
}
