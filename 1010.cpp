#include <stdio.h>

int main(void)
{
	int T, N, M;
	unsigned long long result;

	freopen("input_1010", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);

		result = 1;
		if (M != N) {
			int diff = M - N < N ? M - N : N;
			int remain = 1;

			N = (diff != N ? M - N : N);
			
			for (int i = 0; i < diff; i++) {
				result *= M--;
				if (N != 0)
					result % N == 0 ? result /= N-- : remain *= N--;
			}
			result /= remain;
		}
		printf("%llu\n", result);
	}

	return 0;
}
