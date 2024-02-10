#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void PasswordRec(const char* str, int n, int lvl, int* vcurr, int* nsol)
{
	if (lvl == n)
	{
		(*nsol)++;
		for (int i = 0; i < lvl; i++)
		{
			printf("%c", str[vcurr[i]]);
		}
		printf("\n");
		return;
	}

	for (int j = 0; str[j] != '\0'; j++)
	{
		vcurr[lvl] = j;
		PasswordRec(str, n, lvl + 1, vcurr, nsol);
		vcurr[lvl] = 0;
	}
}

int Password(const char* str, int n)
{
	if (str == NULL || n == 0 || n > 200)
	{
		return 0;
	}
	int* vcurr = calloc(n, sizeof(int));
	int nsol = 0;
	PasswordRec(str, n, 0, vcurr, &nsol);
	free(vcurr);
	return nsol;
}

/*

int main(void)
{
	int ris = Password("a1", 2);
	return 0;
}
*/