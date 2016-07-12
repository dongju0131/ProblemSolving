#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
int discovered[10001];
bool is_cut[10001];
vector<int> edge[100001];
int V, E, counter;

int dfs(int from, bool is_root)
{
	int child = 0, ret = 0, subtree = 10000000;
	discovered[from] = counter++;
	ret = discovered[from];

	for (int j = 0; j < edge[from].size(); j++) {
		int to = edge[from][j];

		if (discovered[to] == 0) {
			child++;
			subtree = dfs(to, false);

			if (!is_root && subtree >= discovered[from])
				is_cut[from] = true;

			ret = ret < subtree ? ret : subtree;
		}
		else {
			ret = ret < discovered[to] ? ret : discovered[to];
		}
	}

	if (is_root) is_cut[from] = (child >= 2 ? true : false);
	return ret;
}

void dfs_all(void)
{
	int cnt = 0;
	memset(is_cut, false, sizeof(is_cut));
	memset(discovered, 0, sizeof(discovered));

	for (int i = 1; i <= V; i++) {
		if (!discovered[i]) {
			counter = 1;
			dfs(i, true);
		}
	}

	for (int i = 1; i <= V; i++)
		if (is_cut[i])
			cnt++;
	printf("%d\n", cnt);
	for (int i = 1; i <= V; i++)
		if (is_cut[i])
			printf("%d ", i);
	printf("\n");
}

int main(void)
{
	int u, v;

	freopen("input_11266", "r", stdin);
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	dfs_all();
	return 0;
}
