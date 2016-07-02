#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int box[1001] = {0, };
	int d[1002] = {0, };
	int n;

	freopen("input_1965", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", box + i);

	d[1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = i - 1; j >= 0; j--)
			if (box[j] < box[i] && d[j] + 1 > d[i])
				d[i] = d[j] + 1;

	printf("%d\n", *max_element(&d[1], &d[1001]));
	return 0;
}
