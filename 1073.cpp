#include <stdio.h>

int main(void)
{
	int map[10] = {0, };
	int n, p, q;
	unsigned long long total = 1, tmp = 0;

	freopen("input_1073", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%1d%1d", &p, &q);
		map[p]++; map[q]++;
	}

	for (int i = 0; i < 10; i++) {
		if (map[i] % 2 != 0) {
			printf("0\n");
			return 0;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (map[i] == 0 || map[i] == 2)
			continue;
		
		tmp = 1;
		for (int j = map[i]; j > 2; j -= 2)
			tmp *= j - 2;
		tmp += 1;

		total *= tmp;
	}

	printf("%llu\n", total);
	return 0;
}
