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
		
		double distance = pow((double)(x2 - x1), 2.0) + pow((double)(y2 - y1),
				2.0);
		distance = sqrt(distance);

		int small_r = r1 < r2 ? r1 : r2;
		int big_r = r1 > r2 ? r1 : r2;

		if (distance <= (double)big_r) {
			if (x1 == x2 && y1 == y2 && r1 == r2)
				result = -1;
			else if (distance + (double)small_r < (double)big_r)
				result = 0;
			else if (distance + (double)small_r == (double)big_r)
				result = 1;
			else
				result = 2;
		}
		else {
			if (distance == small_r + big_r)
				result = 1;
			else if (distance < small_r + big_r)
				result = 2;
			else
				result = 0;
		}

		printf("%d\n", result);
	}

	return 0;
}
