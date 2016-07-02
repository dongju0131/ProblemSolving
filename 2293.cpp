#include <stdio.h>
#include <string.h>

int main(void)
{
	int n, k;
	int value[100] = {0, };
	int acc[10001] = {0, };
	int d[10001] = {0, };

	//freopen("input_2293", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &value[i]);

	for (int i = 0; i < n; i++) {
		memset(d, 0, sizeof(d));
		int t = value[i];
		
		for (int j = t; j <= k; j++) {
			int cal = j;
			d[j] += (cal % t == 0 ? 1 : 0);

			while (cal - t > 0) {
				d[j] += acc[cal - t];
				cal -= t;
			}
		}
		for (int j = 0; j <= k; j++)
			acc[j] += d[j];
	}
	
	printf("%d\n", acc[k]);
	return 0;
}
