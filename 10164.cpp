#include <cstdio>

using namespace std;

int main(void)
{
	int d[16][16] = {0, };
	int N, M, K;

	d[1][1] = 1;
	for (int i = 1; i < 16; i++)
		for (int j = 1; j < 16; j++)
			d[i][j] += d[i - 1][j] + d[i][j - 1];

	scanf("%d %d %d", &N, &M, &K);
	int y = K % M == 0 ? K / M : K / M + 1;
	int x = K % M == 0 ? M : K % M;
	printf("%d\n", K == 0 ? d[N][M] : d[y][x] * d[N - y + 1][M - x + 1]);
	return 0;
}
