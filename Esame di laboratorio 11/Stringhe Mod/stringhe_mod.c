#include <stdlib.h>
#include <stdio.h>

void BacktrackStrModRec(int n, int k, int lvl, char* vcurr)
{
	char alfabeto[26][2] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
	if (lvl == k)
	{
		printf("{");
		for (int i = 0; i < lvl; i++)
		{
			printf("%c", vcurr[i]);
		}
		printf("}, ");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		vcurr[lvl] = alfabeto[i][0];
		BacktrackStrModRec(n, k, lvl + 1, vcurr);
		vcurr[lvl] = 0;
	}
}

void BacktrackStrMod(int n, int k)
{
	if (n <= 0 || n > 26 || k <= 0)
	{
		return;
	}
	
	char* vcurr = calloc(k, sizeof(char));
	BacktrackStrModRec(n, k, 0, vcurr);
	free(vcurr);
	return;

}
/*
int main()
{
	BacktrackStrMod(2, 3);
}
*/