#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void)
{
	int map[1001][1001] = {0, };
	int d[1001][1001] = {0, };
	int n, m;

	freopen("input_11048", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			d[i][j] = max(max(d[i - 1][j], d[i - 1][j - 1]), d[i][j - 1]) +
				map[i][j];

	printf("%d\n", d[n][m]);
	return 0;
}
