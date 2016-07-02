#include <stdio.h>
#include <string.h>
#include <math.h>

#define BIL 1000000000

int d[1000001] = {0, };

int power(int n)
{
	int i = 1, cnt = 0;
	while (i <= n) {
		i *= 2;
		cnt++;
	}
	return cnt - 1;
}

int main(void)
{
	int n, diff, end;

	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		d[i] = 1;

	end = power(n);
	for (int i = 1; i <= end; i++) {
		diff = pow(2, i);
		for (int j = diff; j <= n; j++)
			d[j] = (d[j] % BIL + d[j - diff] % BIL) % BIL;
	}
	printf("%d\n", d[n] % BIL);

	return 0;
}
