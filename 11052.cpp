#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int fish[1001] = {0, };
	int d[1001] = {0, };
	int n;

	freopen("input_11052", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &fish[i]);

	d[1] = fish[1];
	for (int i = 2; i <= n; i++) {
		int max_cur = fish[i];

		for (int j = 1; j <= i / 2; j++) {
			int max_tmp = d[j] + d[i - j];
			max_cur = max(max_cur, max_tmp);
		}
		d[i] = max_cur;
	}

	printf("%d\n", d[n]);
	return 0;
}
