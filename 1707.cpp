#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> node;
vector<int> edge_list[20001];
int visit[20001];

bool dfs(node n)
{
	visit[n.first] = n.second;
	int adjacency_color = (n.second != 1 ? 1 : 2);

	for (int i = 0; i < edge_list[n.first].size(); i++) {
		int e = edge_list[n.first][i];
		
		if (visit[e] == visit[n.first])
			return false;
		else if (visit[e] == 0 && !dfs(node(e, adjacency_color)))
			return false;
	}
	return true;
}

int main(void)
{
	int T, e1, e2, V, E;

	freopen("input_1707", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &V, &E);
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < 20001; i++)
			edge_list[i].clear();

		for (int i = 0; i < E; i++) {
			scanf("%d %d", &e1, &e2);
			edge_list[e1].push_back(e2);
			edge_list[e2].push_back(e1);
		}
		
		bool is_find = true;
		for (int i = 1; i <= V; i++) {
			if (visit[i] == 0 && !dfs(node(i, 1))) {
				is_find = false;
				break;
			}
		}
		printf("%s\n", is_find ? "YES" : "NO");
	}

	return 0;
}
