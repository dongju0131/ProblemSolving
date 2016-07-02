#include <stdio.h>
#include <string.h>

int main(void)
{
	int d[10001] = {1, 0, };
	int coin[21] = {0, };
	int T, n, m;

	freopen("input_9084", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++)
			scanf("%d", &coin[i]);

		scanf("%d", &m);

		for (int i = 1; i <= n; i++)
			for (int j = coin[i]; j <= m; j++)
				d[j] = d[j] + d[j - coin[i]];

		printf("%d\n", d[m]);

		memset(d, 0, sizeof(int) * 10000);
		d[0] = 1;
	}

	return 0;
}
