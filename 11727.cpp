#include <stdio.h>

int main(void)
{
	unsigned long long d[1001] = {0, };
	int n;

	scanf("%d", &n);
	d[1] = 1; d[2] = 3;
	for (int i = 3; i <= n; i++)
		d[i] = (d[i - 1] % 10007) + ((2 * d[i - 2]) % 10007);

	printf("%llu\n", d[n] % 10007);
	return 0;
}
