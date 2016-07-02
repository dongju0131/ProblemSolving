#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int d[330][100001] = {0, };
int main(void)
{
	int n, p, min_val = 100000;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		d[1][i] = i;

	for (int i = 1; i <= n + 1; i++) {
		if (i * i > n) {
			p = i - 1;
			break;
		}
	}

	for (int i = 2; i <= p; i++) 
		for (int j = 1; j <= n; j++)
			d[i][j] = j - i * i >= 0 ? min(d[i - 1][j], d[i][j - i * i] + 1) : d[i - 1][j];

	for (int i = 1; i <= p; i++)
		if (d[i][n] < min_val)
			min_val = d[i][n];

	printf("%d\n", min_val);
	return 0;
}
