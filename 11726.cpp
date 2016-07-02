#include <stdio.h>

int main(void)
{
	unsigned long long d[1001];
	int n;

	scanf("%d", &n);
	d[0] = 1; d[1] = 1;
	for (int i = 2; i <= n; i++)
		d[i] = (d[i - 1] % 10007) + (d[i - 2] % 10007);

	printf("%llu\n", d[n] % 10007);
	return 0;
}
