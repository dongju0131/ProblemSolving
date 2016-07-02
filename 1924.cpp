#include <stdio.h>

int main(void) 
{
	char day_type[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int x, y, day = 0;

	scanf("%d %d", &x, &y);
	for (int i = 0; i < x; i++)
		day += month[i];
	day += y - 1;
	printf("%s\n", day_type[day % 7]);

	return 0;
}
