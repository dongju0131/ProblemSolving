#include <stdio.h>
#include <iostream>

int main(void)
{
	int N, M, K, sum;
	int map[301][301] = {0, };
	int row_sum[301][301] = {0, };
	int d[301][301] = {0, };

	//freopen("input_2167", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		sum = 0;
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
			sum += map[i][j];
			row_sum[i][j] = sum;
		}
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			d[i][j] = d[i - 1][j] + row_sum[i][j - 1] + map[i][j];

	scanf("%d", &K);

	while (K--) {
		int i, j, x, y;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		printf("%d\n", d[x][y] - d[i - 1][y] - d[x][j - 1] + d[i - 1][j -
				1]);
	}
	return 0;
}
