#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
vector<int> result;
vector<int> edge_list[32001];
bool visited[32001];
int N, M;

void dfs(int i)
{
	visited[i] = true;

	for (int j = 0; j < edge_list[i].size(); j++) {
		int u = edge_list[i][j];
		if (!visited[u])
			dfs(u);
	}

	result.push_back(i);
}

void dfs_all(void)
{
	memset(visited, false, sizeof(visited));

	for (int i = 1; i <= N; i++)
		if (!visited[i])
			dfs(i);
}
int main(void)
{
	int u, v;

	freopen("input_2252", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v); 
		edge_list[u].push_back(v);
	}

	dfs_all();
	while (!result.empty()) {
		int u = result.back(); result.pop_back();
		printf("%d ", u);
	}
	printf("\n");

	return 0;
}
