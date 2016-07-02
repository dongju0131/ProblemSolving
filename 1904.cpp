#include <stdio.h>

int main(void)
{
	unsigned long long d1, d2, d3;
	int n;

	scanf("%d", &n);
	d1 = 1; d2 = 2;
	for (int i = 3; i <= n; i++) {
		d3 = d1 % 15746 + d2 % 15746;
		d1 = d2; d2 = d3;
	}

	if (n == 1) printf("%llu\n", d1);
	else if (n == 2) printf("%llu\n", d2);
	else printf("%llu\n", d3 % 15746);
	return 0;
}
