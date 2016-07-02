#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef struct _edge {
	int to_x;
	int to_y;
	int weight;
} edge;
typedef struct _node {
	int to_x;
	int to_y;
	int distance;
} node;

bool operator < (node a, node b) {
	return a.distance > b.distance;
}

int graph[130][130];
vector<edge> edge_list[130][130];
bool visit[130][130];

int main(void)
{
	int N, T = 0;

	freopen("input_4485", "r", stdin);
	while (1) {
		scanf("%d", &N);
		if (!N)
			break;

		priority_queue<node> pq;
		memset(visit, false, sizeof(visit));
		memset(graph, 0, sizeof(graph));
		for (int i = 0; i < 130; i++) {
			graph[0][i] = -1; graph[i][0] = -1;
			graph[N + 1][i] = -1; graph[i][N + 1] = -1;
		}

		for (int i = 0; i < 130; i++)
			for (int j = 0; j < 130; j++)
				edge_list[i][j].clear();

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				scanf("%d", &graph[i][j]);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				edge e;
				if (graph[i - 1][j] != -1) { e.to_y = i - 1; e.to_x = j;
					e.weight = graph[i - 1][j]; edge_list[i][j].push_back(e); }
				if (graph[i][j + 1] != -1) { e.to_y = i; e.to_x = j + 1;
					e.weight = graph[i][j + 1]; edge_list[i][j].push_back(e); }
				if (graph[i + 1][j] != -1) { e.to_y = i + 1; e.to_x = j;
					e.weight = graph[i + 1][j]; edge_list[i][j].push_back(e); }
				if (graph[i][j - 1] != -1) { e.to_y = i; e.to_x = j - 1;
					e.weight = graph[i][j - 1]; edge_list[i][j].push_back(e); }
			}
		}

		node n; n.to_x = 1; n.to_y = 1; n.distance = graph[1][1];
		pq.push(n);
		while (!pq.empty()) {
			n = pq.top(); pq.pop();
			
			if (n.to_y == N && n.to_x == N)
				break;

			if (visit[n.to_y][n.to_x])
				continue;

			visit[n.to_y][n.to_x] = true;
			for (int i = 0; i < edge_list[n.to_y][n.to_x].size(); i++) {
				edge e = edge_list[n.to_y][n.to_x][i];
				node n2; n2.to_y = e.to_y; n2.to_x = e.to_x; 
				n2.distance = n.distance + e.weight;
				pq.push(n2);
			}
		}
		printf("Problem %d: %d\n", ++T, n.distance);
	}
	return 0;
}
