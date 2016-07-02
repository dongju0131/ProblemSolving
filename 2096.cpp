#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
// 1: max, 2: min
int main(void)
{
	int d[4][4] = {0, };
	int n;

	freopen("input_2096", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &d[0][0], &d[0][1], &d[0][2]);
		if (i == 0) {
			for (int j = 0; j < 3; j++) {
				d[1][j] = d[0][j];
				d[2][j] = d[0][j];
			}
			continue;
		}

		d[3][0] = max(d[1][0], d[1][1]) + d[0][0];
		d[3][1] = max(max(d[1][0], d[1][1]), d[1][2]) + d[0][1];
		d[3][2] = max(d[1][1], d[1][2]) + d[0][2];
		d[1][0] = d[3][0]; d[1][1] = d[3][1]; d[1][2] = d[3][2];

		d[3][0] = min(d[2][0], d[2][1]) + d[0][0];
		d[3][1] = min(min(d[2][0], d[2][1]), d[2][2]) + d[0][1];
		d[3][2] = min(d[2][1], d[2][2]) + d[0][2];
		d[2][0] = d[3][0]; d[2][1] = d[3][1]; d[2][2] = d[3][2];
	}

	printf("%d %d\n", *max_element(&d[1][0], &d[1][3]),
			*min_element(&d[2][0], &d[2][3]));
	return 0;
}
