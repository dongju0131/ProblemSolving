#include <stdio.h>
#define nine 9901

int main(void)
{
	unsigned long long d[100001][3] = {0, };
	int n;

	scanf("%d", &n);
	d[1][0] = d[1][1] = d[1][2] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0)
				d[i][j] += (d[i - 1][0] % nine) + (d[i - 1][1] % nine) + (d[i - 1][2] % nine);
			else
				d[i][j] += (d[i - 1][0] % nine) + (d[i - 1][j % 2 + 1] % nine);
		}
	}

	unsigned long long result = 0;
	for (int i = 0; i < 3; i++)
		result = (result + d[n][i]) % nine;

	printf("%llu\n", result);
	return 0;
}	
