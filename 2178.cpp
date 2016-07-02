#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;
typedef struct _position {
	char x; char y; short cnt;
} position;

int main(void)
{
	int N, M, result;
	bool maze[102][102] = {false, };
	bool visited[102][102] = {false, };
	char x[4] = {-1, 1, 0, 0};
	char y[4] = {0, 0, -1, 1};
	queue<position> q;

	freopen("input_2178", "r", stdin);
	scanf("%d %d\n", &N, &M);
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++)
			scanf("%1d", &maze[i][j]);

	position first_p = {1, 1, 1};
	q.push(first_p);
	visited[1][1] = true;
	while (!q.empty()) {
		position p = q.front();
		q.pop();

		char r = p.y;
		char c = p.x;
		short cnt = p.cnt;
		maze[r][c] = false;

		if (r == N && c == M) {
			result = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			if (maze[r + y[i]][c + x[i]] && !visited[r + y[i]][c + x[i]]) {
				p.y = r + y[i]; p.x = c + x[i]; p.cnt = cnt + 1;
				visited[r + y[i]][c + x[i]] = true;
				q.push(p);
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
