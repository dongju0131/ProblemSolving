#include <stdio.h>

int main(void)
{
	unsigned long long d[16] = {0, };
	int N;

	d[0] = 1; d[1] = 3;
	for (int i = 2; i < 16; i++)
		d[i] = 3 * d[i - 1] + (2 * d[i - 2] + (d[i - 1] - 3 * d[i - 2]));

	scanf("%d", &N);
	printf("%llu\n", N % 2 != 0 ? 0 : d[N / 2]);
	return 0;
}
