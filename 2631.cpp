#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int kid[201], d[202] = {1, 0, };

int main(void)
{
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", kid + i);

	for (int i = 1; i < N; i++) {
		int max = 1;
		for (int j = 0; j < i; j++) {
			if (kid[j] > kid[i])
				continue;
			max = max > d[j] + 1 ? max : d[j] + 1;
		}
		d[i] = max;
	}
	printf("%d\n", N - *max_element(d, d + N + 1));
	return 0;
}
