#include <stdio.h>
#include <string.h>

int main(void)
{
	unsigned long long d[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int n;

	scanf("%d", &n);
	for (int i = 2; i <= n; i++){
		for (int j = 0; j < 10; j++) {
			unsigned long long result = 0;
			for (int k = j; k < 10; k++)
				result += d[k];
			d[j] = result % 10007;
		}
	}

	unsigned long long sum = 0;
	for (int i = 0; i < 10; i++)
		sum += d[i] % 10007;

	printf("%llu\n", sum % 10007);
	return 0;
}
	
