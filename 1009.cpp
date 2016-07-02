#include <stdio.h>

int main(void)
{
	int T, a, b;
	int arr[11] = {1, };

	freopen("input_1009", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &a, &b);
		int length = 1;

		while (1) {
			arr[length] = (arr[length - 1] * a) % 10;
			arr[length] = (arr[length] == 0 ? 10 : arr[length]);

			for (int i = 1; i < length; i++)
				if (arr[i] == arr[length])
					goto P;
			length++;
		}
P:
		length -= 1;
		printf("%d\n", arr[(b % length) ? b % length : length]);
	}

	return 0;
}
