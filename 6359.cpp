#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(void)
{
	bool d[101];
	int T, N;

	scanf("%d", &T);
	while (T--) {
		memset(d, false, sizeof(d));
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) { 
			for (int j = i; j <= N; j += i)
				d[j] = (d[j] == true ? false : true);
		}

		int cnt = 0;
		for (int i = 1; i <= N; i++)
			if (d[i])
				cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
