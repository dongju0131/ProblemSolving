#include <cstdio>
#include <cstring>
#include <iostream>

#define INF 1000000000
using namespace std;
bool graph[102][102];
int d[102][102];

int main(void)
{
	int N, M, u, v;

	freopen("input_1389", "r", stdin);
	scanf("%d %d", &N, &M);
	memset(graph, false, sizeof(graph));
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		graph[u][v] = true; graph[v][u] = true;
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++)
			d[i][j] = graph[i][j] ? 1 : INF;
		d[i][i] = 0;
	}

	for (int k = 1; k <= N; k++) 
		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= N; j++)
				d[i][j] = d[i][j] > d[i][k] + d[k][j] ? d[i][k] + d[k][j] : d[i][j];

	int min = INF, idx;
	for (int i = 1; i <= N; i++) {
		int local_sum = 0;
		
		for (int j = 1; j <= N; j++) 
			local_sum += d[i][j];
		
		if (local_sum < min) {
			idx = i;
			min = local_sum;
		}
	}
	printf("%d\n", idx);
	return 0;
}
