#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ReverseStringRec(const char* str, int dim, int countA, int countB, char* ris)
{
	if (countA == dim + 1)
	{
		return;
	}
	ris[countA] = str[countB];
	ReverseStringRec(str, dim, countA + 1, countB - 1, ris);
}

char* ReverseString(const char* str)
{
	if (str == NULL)
	{
		return NULL;
	}
	size_t dim = strlen(str) - 1;
	char* ris = calloc(dim + 2, sizeof(char));
	ReverseStringRec(str, dim, 0, dim, ris);

	return ris;
}

/*
int main()
{
	char str[] = "stringa da invertire";
	char *ris = ReverseString(str);

	for (int i = 0; ris[i] != 0; i++)
	{
		printf("%c", ris[i]);
	}

	return 0;
}
*/