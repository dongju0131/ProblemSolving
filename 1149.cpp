#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	int house[1000][3], d[1000][3];
#ifdef TEST
	freopen("input_1149", "r", stdin);
#endif
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);

	for (int i = 0; i < 3; i++)
		d[N - 1][i] = house[N - 1][i];

	for (int i = N - 2; i >= 0; i--) 
		for (int j = 0; j < 3; j++) 
			d[i][j] = min(d[i + 1][(j + 1) % 3], d[i + 1][(j + 2) % 3]) + house[i][j];

	int result = min(d[0][0], d[0][1]);
	result = min(result, d[0][2]);

	printf("%d\n", result);

	return 0;
}
