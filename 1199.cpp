#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
vector<int> order;
int graph[1001][1001];
bool visited[1001];
int N;

void more_sub(int i)
{
	visited[i] = true;

	for (int j = 1; j <= N; j++)
		if (graph[i][j] && !visited[j])
			more_sub(j);
}

bool more_than_two()
{
	int cnt = 0;
	memset(visited, false, sizeof(visited));

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			more_sub(i);
			cnt++;
		}

		if (cnt > 1)
			return true;
	}
	return false;
}

void dfs_all(int from)
{
	for (int to = 1; to <= N; to++) {
		while (graph[from][to] > 0) {
			graph[from][to]--;
			graph[to][from]--;
			dfs_all(to);
		}
	}
	order.push_back(from);
}
int main(void)
{
	int cnt;

	freopen("input_1199", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		cnt = 0;
		for (int j = 1; j <= N; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j]) 
				cnt += graph[i][j];
		}
		if (cnt % 2 != 0) {
			printf("-1\n");
			return 0;
		}
	}

	if (more_than_two()) {
		printf("-1\n");
	}
	else {
		dfs_all(1);
		for (int i = order.size() - 1; i >= 0; i--)
			printf("%d ", order[i]);
		printf("\n");
	}

	return 0;
}
