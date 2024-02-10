#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void ParoleT9Rec(const char* str, size_t dim, int lvl, char* vcurr, int* nsol)
{
	char tastiera[10][4] = { "" ,"", "ABC", "DEF" , "GHI" , "JKL" ,"MNO" ,"PQRS" ,"TUV" ,"WXYZ"};

	if (str[lvl] == '\0')
	{
		vcurr[lvl] = '\0';
		for (int i = 0; i < lvl; i++)
		{
			printf("%c", vcurr[i]);
		}
		printf("\n");
		(*nsol)++;
		return;
	}

	int numero = str[lvl] - '0';
	
	for (int i = 0; tastiera[numero][i] != '\0'; i++)
	{
		vcurr[lvl] = tastiera[numero][i];
		ParoleT9Rec(str, dim, lvl + 1, vcurr, nsol);
		vcurr[lvl] = 0;
	}


}

int ParoleT9(const char* str)
{
	if (str == NULL || str[0] == '\0') 
	{
		return 0;
	}
	size_t dim = strlen(str);
	char* vcurr = calloc(dim, sizeof(char) + 1);
	int nsol = 0;
	ParoleT9Rec(str, dim, 0, vcurr, &nsol);
	free(vcurr);
	return nsol;
}


/*
int main()
{

	int ris = ParoleT9("54");

	return 0;
}
*/