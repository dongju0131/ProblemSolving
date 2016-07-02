#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int seq[1001] = {0, };
	int d[1001] = {0, };
	int n;

	//freopen("input_11053_2", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &seq[i]);

	for (int i = 1; i <= n; i++) {
		int max_val = 0;

		for (int j = i - 1; j >= 1; j--) 
			if (seq[j] < seq[i] && d[j] > max_val)
				max_val = d[j];
		d[i] = max_val + 1;
	}

	printf("%d\n", *max_element(d, d + 1001));
	return 0;
}
