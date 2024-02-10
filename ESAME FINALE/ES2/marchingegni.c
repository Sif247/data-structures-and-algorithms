#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void SpringArrangementsRec(const char* record, int len, int lvl, char* vcurr, int* nsol)
{
	if (lvl == len)
	{
		(*nsol)++;
		for (int i = 0; i < lvl; i++)
		{
			printf("%c", vcurr[i]);
		}
		printf("\n");
		return;
	}

	if (record[lvl] == '?')
	{
		vcurr[lvl] = '#';
		SpringArrangementsRec(record, len, lvl + 1, vcurr, nsol);
		vcurr[lvl] = '.';
		SpringArrangementsRec(record, len, lvl + 1, vcurr, nsol);
		//rollback
		vcurr[lvl] = 0;
	}
	else
	{
		vcurr[lvl] = record[lvl];
		SpringArrangementsRec(record, len, lvl + 1, vcurr, nsol);
	}
}

int SpringArrangements(const char* record)
{
	int len = strlen(record);
	char* vcurr = calloc(len, sizeof(char) + 1);
	int nsol = 0;
	SpringArrangementsRec(record, len, 0, vcurr, &nsol);


	free(vcurr);
	return nsol;
}


/*
int main()
{
	char record[] = "???.###";
	int ris = SpringArrangements(record);

	return 0;
}

*/