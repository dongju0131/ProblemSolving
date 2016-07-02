#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	int triangle[501][501];
	int d[501][501] = {0, };

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= i; j++)
			scanf("%d", &triangle[i][j]);

	d[1][1] = triangle[1][1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + triangle[i][j];

	int max = -1;
	for (int i = 1; i <= n; i++)
		max = d[n][i] > max ? d[n][i] : max;

	printf("%d\n", max);
	return 0;
}
