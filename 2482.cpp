#include <cstdio>
#include <iostream>
#include <numeric>
#define DIV 1000000003
using namespace std;

unsigned long long d[1001][1001];

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	for (int i = 1; i <= N; i++)
		d[1][i] = 1;

	for (int i = 2; i <= K; i++) {
		for (int j = i * 2 - 1; j <= N; j++) {
			if (j != N)
				d[i][j] = accumulate(&d[i - 1][0], &d[i - 1][j - 2 + 1], (unsigned long long) 0) % DIV;
			else
				d[i][j] = accumulate(&d[i - 1][0], &d[i - 1][j - 2], (unsigned long long) 0) % DIV;
		}
	}

	printf("%llu\n", accumulate(&d[K][0], &d[K][N + 1], (unsigned long long) 0) % DIV);
	return 0;
}
