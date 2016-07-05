#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
class node {
public :
	node() {}
	node(int _y, int _x, int _d, bool _broken) : y(_y), x(_x), d(_d), broken(_broken) {}
	int y; int x; int d; bool broken;
};
bool map[1001][1001];
bool visit[1001][1001][2];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main(void)
{
	queue<node> q;
	int N, M, val, result = 0;
	bool find = false;

	freopen("input_2206", "r", stdin);
	scanf("%d %d", &N, &M);
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &val);
			map[i][j] = val ? true : false;
		}
	}

	q.push(node(1, 1, 1, false));
	while (!q.empty()) {
		node n = q.front(); q.pop();

		if (n.y < 1 || n.y > N || n.x < 1 || n.x > M || visit[n.y][n.x][n.broken])
			continue;

		//cout << " cur y : " << n.y << ", x : " << n.x << endl;
		if (n.y == N && n.x == M) {
			find = true; result = n.d;
			break;
		}

		visit[n.y][n.x][n.broken] = true;
		for (int i = 0; i < 4; i++) {
			int new_y = n.y + dy[i];
			int new_x = n.x + dx[i];

			if (new_y < 1 || new_y > N || new_x < 1 || new_x > M)
				continue;

			if (map[new_y][new_x] && n.broken)
				continue;
			else if (map[new_y][new_x]) 
				q.push(node(new_y, new_x, n.d + 1, true));
			else
				q.push(node(new_y, new_x, n.d + 1, n.broken));
		}
	}

	printf("%d\n", find ? result : -1);
	return 0;
}
