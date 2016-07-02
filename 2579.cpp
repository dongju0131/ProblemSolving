#include <stdio.h>

int main(void)
{
	int n;
	int stair[301];
	int d[301] = {0, };

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &stair[i]);

	d[1] = stair[1]; d[2] = stair[1] + stair[2];
	for (int i = 3; i <= n; i++)
		d[i] = (d[i - 2] > d[i - 3] + stair[i - 1] ? d[i - 2] : d[i - 3] +
				stair[i -1]) + stair[i];

	printf("%d\n", d[n]);

	return 0;
}
