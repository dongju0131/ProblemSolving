#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main(void)
{
	int T, n;
	int sticker[3][100002] = {0, };
	int d[3][100002] = {0, };

	freopen("input_9465", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(d, 0, sizeof(d));
		memset(sticker, 0, sizeof(sticker));
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &sticker[i][j]);

		for (int j = 1; j <= n; j++)
			for (int i = 0; i < 3; i++)
				d[i][j] = max(d[(i + 1) % 3][j - 1], d[(i + 2) % 3][j - 1])
					+ sticker[i][j];

		printf("%d\n", max(max(d[0][n], d[1][n]), d[2][n]));
	}

	return 0;
}
