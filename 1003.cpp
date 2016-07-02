#include <stdio.h>

int main(void)
{
	int T, n;
	int fib[2][41];

	fib[0][0] = 1; fib[0][1] = 0;
	fib[1][0] = 0; fib[1][1] = 1;

	for (int i = 2; i < 41; i++) {
		fib[0][i] = fib[0][i - 1] + fib[0][i - 2];
		fib[1][i] = fib[1][i - 1] + fib[1][i - 2];
	}

	freopen("input_1003", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("%d %d\n", fib[0][n], fib[1][n]);
	}

	return 0;
}
