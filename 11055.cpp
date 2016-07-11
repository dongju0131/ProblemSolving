#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
int seq[1001], d[1001];
int main(void)
{
	int N;

	freopen("input_11055", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", seq + i);

	for (int i = 0; i < N; i++) {
		int max = seq[i];
		for (int j = 0; j < i; j++) {
			if (seq[j] >= seq[i])
				continue;
			max = max > d[j] + seq[i] ? max : d[j] + seq[i];
		}
		d[i] = max;
	}

	printf("%d\n", *max_element(d, d + N + 1));
	return 0;
}
