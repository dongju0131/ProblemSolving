#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
int N, M;
int seq[501];
bool graph[501][501];
bool visited[501];
vector<int> order;

void dfs(int i)
{
	visited[i] = true;

	for (int j = 1; j <= N; j++)
		if (graph[i][j] && !visited[j])
			dfs(j);
	order.push_back(i);
}

void dfs_all(void)
{
	order.clear();
	memset(visited, false, sizeof(visited));

	for (int i = 1; i <= N; i++)
		if (!visited[i])
			dfs(i);
}

bool verify_cycle(void)
{
	for (int i = order.size() - 2; i >= 0; i--)
		for (int j = order.size() - 1; j > i; j--)
			if (graph[order[i]][order[j]])
				return false;

	for (int i = order.size() - 1; i >= 0; i--)
		printf("%d ", order[i]);
	printf("\n");
	return true;
}

int main(void)
{
	int T, u, v;

	freopen("input_3665", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		memset(graph, false, sizeof(graph));
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", seq + i);

		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++)
				graph[seq[i]][seq[j]] = true;
		
		scanf("%d", &M);
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &u, &v);
			if (graph[u][v]) { graph[u][v] = false; graph[v][u] = true; }
			else { graph[u][v] = true; graph[v][u] = false; }
		}
		
		dfs_all();
		if (!verify_cycle())
			cout << "IMPOSSIBLE" << endl;

	}

	return 0;
}
