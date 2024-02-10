#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void IsPalindromoRec(const char* str, int* start, int* end, bool* ris, int* comp)
{
	if (*start == *comp || *ris == false)
	{
		return;
	}
	if (str[*start] != str[*end])
	{
		*ris = false;
	}
	*start += 1;
	*end -= 1;
	IsPalindromoRec(str, start, end, ris, comp);
}

bool IsPalindromo(const char* str)
{
	if (str == NULL)
	{
		return false;
	}
	if (strcmp(str, "") == 0)
	{
		return true;
	}

	int start = 0;
	int end = strlen(str) - 1;
	int confronto = 0;
	if (strlen(str) % 2 == 0)
	{
		confronto = strlen(str);
	}
	else
	{
		confronto = end;
	}
	bool ris = true;

	IsPalindromoRec(str, &start, &end, &ris, &confronto);
	return ris;
}


/*
int main()
{
	
	char str1[] = "ossesso";
	char str2[] = "osso";
	char str3[] = "papone";
	char str4[] = "anna";

	bool ris = false;

	ris = IsPalindromo(str1);
	printf("\n");
	ris = IsPalindromo(str2);
	printf("\n");
	ris = IsPalindromo(str3);
	printf("\n");
	ris = IsPalindromo(str4);


	return 0;
}
*/