#include <stdio.h>
#include <numeric>

using namespace std;

unsigned long long d[2501][5005];
int str[5005];

int main(void)
{
	bool has_zero = false, has_sequence = false;
	char c;
	int idx = 0;
	unsigned long long total = 0;

	freopen("input_2011", "r", stdin);
	while ( (c = getchar()) != EOF) {
		str[++idx] = c - '0';
		if (idx == 1 && str[idx] == 0)
			goto exit;

		if (str[idx] == 0) {
			has_zero = true;
			if (has_sequence)
				goto exit;
			has_sequence = true;
		}
		else
			has_sequence = false;
	}

	if (!has_zero)
		total++;

	for (int i = 1; i <= idx / 2; i++) {
		for (int j = i * 2; j <= idx; j++) {
			int target = str[j - 1] * 10 + str[j] * 1;
			if (str[j] == 0 && target > 26) {
				total = 0;
				goto exit;
			}
			if (target < 1 || target > 26 || str[j - 1] == 0 || (str[j + 1] == 0 && j != idx))
				continue;

			if (i == 1) {
				d[i][j] = 1;
				total++;
			}
			else {
				d[i][j] = accumulate(&d[i - 1][0], &d[i - 1][j - 1], 0);
				total += d[i][j];
			}
			//total %= 1000000;
		}
	}

exit:
	printf("%llu\n", total);
	return 0;
}
