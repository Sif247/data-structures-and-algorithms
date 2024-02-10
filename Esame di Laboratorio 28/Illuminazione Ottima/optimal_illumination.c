#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void OptimalIlluminationRec(int M, int R, const int* light, size_t light_size, int i, bool* vcurr, bool* vbest, int pos, int*posbest)
{
	//caso base
	if (i == light_size)
	{
		int partenza = 0;
		bool esito  = true;
		for (int j = 0; j < i && partenza < M; ++j)
		{
			if (vcurr[j])
			{
				if (light[j] - R <= partenza)
				{
					partenza = light[j] + R;
				}
				else
				{
					esito = false;
					break;
				}
			}
		}
		if (esito && pos <= *posbest && partenza >= M)
		{
			*posbest = pos;
			memcpy(vbest, vcurr, sizeof(bool) * light_size);
		}

		return;
	}

	vcurr[i] = false;
	OptimalIlluminationRec(M, R, light, light_size, i + 1, vcurr, vbest, pos, posbest);
	vcurr[i] = true;
	OptimalIlluminationRec(M, R, light, light_size, i + 1, vcurr, vbest, pos + 1, posbest);
	vcurr[i] = false;
	
}


bool* OptimalIllumination(int M, int R, const int* light, size_t light_size)
{
	bool* vcurr = calloc(light_size, sizeof(bool));
	bool* vbest = calloc(light_size, sizeof(bool));
	int pos = light_size;
	OptimalIlluminationRec(M, R, light,light_size, 0, vcurr, vbest,0, &pos);
	bool esito = true;
	for (int i = 0; i < light_size; ++i)
	{
		if (vbest[i] == 0)
		{
			esito = false;
		}
		else
		{
			break;
		}
	}
	if (!esito)
	{
		free(vbest);
		free(vcurr);
		return NULL;

	}



	free(vcurr);
	return vbest;
}
/*
int main()
{
	int M, R;
	size_t light_size;
	bool* ris;
	///////////////////////////////////////
	M = 10;
	R = 3;
	const int* light1[] = {2, 7, 9};
	light_size = 3;
	ris = OptimalIllumination(M, R, light1, light_size);
	printf("{ ");
	for (int i = 0; i < light_size; i++)
	{
		printf("%d, ", ris[i]);
	}
	printf(" }");
	///////////////////////////////////////
	M = 10;
	R = 2;
	const int* light2[] = { 2, 7, 9 };
	light_size = 3;
	ris = OptimalIllumination(M, R, light2, light_size);
	printf("{ ");
	for (int i = 0; i < light_size; i++)
	{
		printf("%d, ", ris[i]);
	}
	printf(" }");
	///////////////////////////////////////
	M = 10;
	R = 2;
	const int* light3[] = { 2, 3, 7, 9 };
	light_size = 4;
	ris = OptimalIllumination(M, R, light3, light_size);
	printf("{ ");
	for (int i = 0; i < light_size; i++)
	{
		printf("%d, ", ris[i]);
	}
	printf(" }");
	return 0;
}
*/
