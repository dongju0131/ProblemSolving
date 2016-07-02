#include <stdio.h>
#define billion 1000000000
int main(void)
{
	unsigned long long d1 = 0, d2 = 1, d3 = 2;
	int n;

	scanf("%d", &n);
	for (int i = 4; i <= n; i++) {
		d1 = d2; d2 = d3;
		d3 = (i - 1) * (d1 + d2) % billion;
	}
	if (n >= 3)
		printf("%llu\n", d3);
	else if (n == 1)
		printf("%llu\n", d1);
	else
		printf("%llu\n", d2);
	return 0;
}
