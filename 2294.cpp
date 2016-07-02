#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 1000000
using namespace std;

int main(void)
{
	int n, k;
	int val[100];
	int d[10001];

	freopen("input_2294", "r", stdin);
	memset(d, INF, sizeof(d));
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &val[i]);

	d[0] = 0;
	for (int i = 0; i < n; i++) 
		for (int j = val[i]; j <= k; j++)
			d[j] = min(d[j], d[j - val[i]] + 1);

	printf("%d\n", d[k] >= INF ? -1 : d[k]);
	return 0;
}
