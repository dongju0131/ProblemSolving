#include <stdio.h>
#include <math.h>

#define BILLION 1000000000

int d[20][1000001] = {0, };

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
		d[0][i] = 1;

	end = power(n);
	for (int i = 1; i <= end; i++) {
		diff = pow(2, i);
		for (int j = 0; j < diff; j++)
			d[i][j] = d[i - 1][j] % BILLION;
		for (int j = diff; j <= n; j++)
			d[i][j] = (d[i - 1][j] % BILLION + d[i][j - diff] % BILLION) % BILLION;
	}
	printf("%d\n", d[end][n] % BILLION);

	return 0;
}
