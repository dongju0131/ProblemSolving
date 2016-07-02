#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	int arr[100001] = {0, };
	long long d[100001] = {0, };
	
	freopen("input_1912", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	d[0] = -1000000000; d[1] = arr[1];
	for (int i = 2; i <= n; i++) 
		d[i] = (d[i - 1] + arr[i] > arr[i] ? d[i - 1] + arr[i] : arr[i]);

	printf("%lld\n", *max_element(d, d + n + 1));
	return 0;
}

