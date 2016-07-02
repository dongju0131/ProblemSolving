#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int pow(int n)
{
	for (int i = 1; ; i *= 2) {
		if (i > n)
			return i / 2;
	}
	return -1;
}

long long cal(long long *d, vector<int>& list, int n)
{
	if (list.empty())
		return 0;

	long long total = 0;
	for (int i = 0; i < list.size(); i++) {
		if (n < list[i])
			continue;
		total += d[n - list[i]];
	}
	return total;
}

int main(void)
{
	vector<int> list;
	long long d[1000001] = {1, 1, 0, };
	int n;

	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		d[i] += 1;
		for (int j = pow(i); j > 1; j /= 2) {
			d[i] = (d[i] + d[i - j] - cal(d, list, i - j)) % 1000000000;
			if (i != j)
				list.push_back(j);
		}
		list.clear();
	}
	printf("%lld\n", d[n]);

	return 0;
}
