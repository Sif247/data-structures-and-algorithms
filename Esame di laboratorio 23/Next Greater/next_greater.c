#include "next_greater.h"
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

size_t Lenght(Item* i)
{
	size_t ris = 0;
	while (i != NULL)
	{
		ris++;
		i = i->next;
	}
	return ris;
}

ElemType* NextGreater(const Item* list, size_t* answer_size)
{
	if (list == NULL)
	{
		*answer_size = 0;
		return NULL;
	}

	*answer_size = Lenght(list);
	ElemType *ris = calloc(*answer_size, sizeof(ElemType));

	int count = 0;
	int var = 0;
	Item* tmp = list;

	while (count < *answer_size - 1)
	{
		tmp = list;
		for (int i = 0; i < count; i++)
		{
			tmp = tmp->next;
		}
		var = tmp->value;
		bool esito = false;
		while (tmp != NULL)
		{
			if (var < tmp->value)
			{
				ris[count] = tmp->value;
				count++;
				esito = true;
				break;
			}
			tmp = tmp->next;
		}
		if (!esito)
		{
			ris[count] = INT_MIN;
			count++;
		}
	}
	ris[*answer_size - 1] = INT_MIN;

	return ris;
}
/*
int main(void)
{
	ElemType e[] = { 2, 3, 1, 4, 7, 2 };

	Item* i = ListCreateEmpty();

	for (int j = 0; j < sizeof(e) / sizeof(e[0]); ++j)
	{
		i = ListInsertBack(i, e + j);
	}
	size_t dim = sizeof(e) / sizeof(e[0]);
	ElemType* ris = NextGreater(i,&dim);
	return 0;
}
*/