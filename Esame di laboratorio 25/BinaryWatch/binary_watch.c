#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

void ValidTimesRec(uint8_t n, bool* vcurr, int lvl, int* h, int* m)
{
	if (lvl == 11)
	{
		int c = 0;
		int min = 0;
		int hour = 0;

		for (int i = 0; i < 11; i++)
		{
			if (vcurr[i])
			{
				c++;
				if (i >= 0 && i <= 5)
				{
					if (i == 0)
					{
						min += 1;
					}
					else if (i == 1)
					{
						min += 2;
					}
					else if (i == 2)
					{
						min += 4;
					}
					else if (i == 3)
					{
						min += 8;
					}
					else if (i == 4)
					{
						min += 16;
					}
					else if (i == 5)
					{
						min += 32;
					}
				}
				else
				{
					if (i == 6)
					{
						hour += 1;
					}
					else if (i == 7)
					{
						hour += 2;
					}
					else if (i == 8)
					{
						hour += 4;
					}
					else if (i == 9)
					{
						hour += 8;
					}
					else if (i == 10)
					{
						hour += 16;
					}
				}
			}
			if (c == n)
			{
				break;
			}
		}

		if (min < 60 && hour < 24 && c == n)
		{
			if (min == *m && hour == *h)
			{
				return;
			}
			else
			{
				*m = min;
				*h = hour;
			}


			if (min < 10 && hour < 10)
			{
				printf("0%d:0%d, ", hour, min);
			}
			else if (min < 10)
			{
				printf("%d:0%d, ", hour, min);
			}
			else if (hour < 10)
			{
				printf("0%d:%d, ", hour, min);
			}
			else
			{
				printf("%d:%d, ", hour, min);
			}
		}
		return;
	}


	vcurr[lvl] = false;
	ValidTimesRec(n, vcurr, lvl + 1, h, m);
	vcurr[lvl] = true;
	ValidTimesRec(n, vcurr, lvl + 1, h, m);
	vcurr[lvl] = false;


}

void ValidTimes(uint8_t n)
{
	if (n < 0 || n > 11)
	{
		return;
	}

	bool* vcurr = calloc(11, sizeof(bool));
	int cmp_min = -1;
	int cmp_hour = -1;
	ValidTimesRec(n, vcurr, 0, &cmp_hour, &cmp_min);
	free(vcurr);
	return;
}
/*
int main()
{
	unsigned led = 1;
	ValidTimes(led);

	return 0;
}
*/
