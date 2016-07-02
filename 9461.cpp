#include <stdio.h>

int main(void)
{
	int n, target;
	unsigned long long padovan[101] = {0, };

	padovan[1] = 1; padovan[2] = 1;
	for (int i = 3; i <= 100; i++)
		padovan[i] = padovan[i - 2] + padovan[i - 3];

	//freopen("input_9461", "r", stdin);
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &target);
		printf("%llu\n", padovan[target]);
	}

	return 0;
}
