#include <stdio.h>

#define TEN 1000000000

int main(void)
{
	unsigned long long d[100][10] = {{0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, };
	int n;

	for (int i = 1; i < 100; i++) {
		d[i][0] = d[i - 1][1] % TEN; 
		d[i][9] = d[i - 1][8] % TEN;
		for (int j = 1; j < 9; j++)
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % TEN;
	}

	scanf("%d", &n);
	unsigned long long result = 0;
	for (int i = 0; i < 10; i++)
		result += (d[n - 1][i] % TEN);
	printf("%llu\n", result % TEN);

	return 0;
}

