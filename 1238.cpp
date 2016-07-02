#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int d[1001][1001];
int N, M, X, u, v, weight;

int main(void)
{
	freopen("input_1238", "r", stdin);
	scanf("%d %d %d", &N, &M, &X);
	memset(d, 0x3f, sizeof(d));
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &u, &v, &weight);
		d[u][v] = weight;
	}

	for (int k = 1; k <= N; k++) 
		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= N; j++) 
				if (d[i][j] > d[i][k] + d[k][j]) 
					d[i][j] = d[i][k] + d[k][j];

	int max = 0;
	for (int i = 1; i <= N; i++) {
		int tmp = 0;
		if (i != X) tmp = d[i][X] + d[X][i];
		if (tmp > max) max = tmp;
	}

	printf("%d\n", max);
	return 0;
}
