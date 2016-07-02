#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int N, u, v;
	bool graph[100][100];
	bool visit[100][100] = {false, };
	queue<int> q;

	freopen("input_11403", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &graph[i][j]);

	for (int i = 0; i < N; i++) {
		q.push(i);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int j = 0; j < N; j++) {
				if (graph[cur][j] && !visit[i][j]) {
					visit[i][j] = true;
					q.push(j);
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
			printf("%d ", visit[i][j]);
		printf("\n");
	}

	return 0;
}
