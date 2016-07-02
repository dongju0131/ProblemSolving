#include <stdio.h>

int M, N;
int map[501][501];
int d[501][501];

int dp(int y, int x)
{
	if (y == M && x == N)
		return 1;
	
	if (d[y][x] != 0)
		return d[y][x];

	int result = 0;
	int cur = map[y][x];
	result += cur > map[y + 1][x] ? dp(y + 1, x) : 0;
	result += cur > map[y][x + 1] ? dp(y, x + 1) : 0;
	result += cur > map[y - 1][x] ? dp(y - 1, x) : 0;
	result += cur > map[y][x - 1] ? dp(y, x - 1) : 0;
	d[y][x] = result;
	
	return result;
}

int main(void)
{
	freopen("input_1520", "r", stdin);
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);

	printf("%d\n", dp(1, 1));
	return 0;
}
