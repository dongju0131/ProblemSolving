#include <stdio.h>
#include <math.h>

int main(void)
{
	int x1, y1, r1, x2, y2, r2, T;
	int result;

	freopen("input", "r", stdin);
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2)
				result = -1;
			else
				result = 0;
		}
		else {
			double distance = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
			distance = sqrt(distance);

			if (distance < r1 + r2) {
				int small_r = r1 < r2 ? r1 : r2;
				int big_r = r1 > r2 ? r1 : r2;

				if (small_r + distance > big_r)
					result = 2;
				else if (small_r * 2 == big_r)
					result = 1;
				else
					result = 0;
			}
			else if (distance == r1 + r2)
				result = 1;
			else
				result = 0;
		}

		printf("%d\n", result);
	}

	return 0;
}
