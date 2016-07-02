#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	int grape[10001] = {0, };
	int d[10002] = {0, };

	freopen("input_2156", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &grape[i]);

	d[1] = grape[1]; d[2] = grape[1] + grape[2];
	for (int i = 3; i <= n; i++) {
		int max_value = d[i - 2];
		for (int k = 3; k <= i; k++)
			max_value = max(max_value, d[i - k] + grape[i - 1]);
		d[i] = max_value + grape[i];
	}

	printf("%d\n", *max_element(d, d + n + 1));
	return 0;
}
