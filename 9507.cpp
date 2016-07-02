#include <stdio.h>

int main(void)
{
	unsigned long long d[68];
	int T, N;

	d[0] = 1; d[1] = 1; d[2] = 2; d[3] = 4;
	for (int i = 4; i <= 67; i++)
		d[i] = d[i - 1] + d[i - 2] + d[i - 3] + d[i - 4];

	freopen("input_9507", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%llu\n", d[N]);
	}
	return 0;
}


