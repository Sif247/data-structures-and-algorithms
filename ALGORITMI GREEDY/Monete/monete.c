#include <stdlib.h>

int* Monete(const int* tagli, size_t tagli_size, int budget)
{
	if (budget <= 0)
	{
		return NULL;
	}

	int *res = calloc(tagli_size, sizeof(int));

	for (int i = 0; i < tagli_size; i++)
	{
		res[i] = budget / tagli[i];
		budget = budget % tagli[i];
	}
	return res;
}
/*
int main(void)
{
	int tagli[] = {50, 20, 10, 5, 2, 1};
	int tagli_size = sizeof(tagli) / sizeof(tagli[0]);
	int* res = Monete(tagli, tagli_size, 126);
	free(res);
	return 0;
}
*/