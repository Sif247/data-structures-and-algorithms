#include "list.h"
#include <stdlib.h>

//SBAGLIATOOO!!!    DA RIVEDERE

Item* BucketSort(Item* l)
{
	int min = 0;
	int max = 0;
	int lenght = 0;
	GetMinMaxSize(l, &min, &max, &lenght);

	Item** bucket = calloc(lenght, sizeof(Item*));
	for (int i = 0; i < lenght; i++)
	{
		bucket[i] = ListCreateEmpty();
	}
	Item* tmp = l;
	while (tmp != NULL)
	{
		int pos = ((lenght - 1) * (tmp->value - min)) / (max - min);
		bucket[pos] = ListInsertHead(tmp->value, bucket[pos]);
		tmp = tmp->next;
	}

	Item* res = ListCreateEmpty();
	for (int i = 0; i < lenght; i++) 
	{
		Item* sorted = BucketSort(bucket[i]);
		res = ConcatList(res, sorted);
	}
	Item* tmp = l;
	Item* tmp_res = res;
	ElemType c;
	while (!ListIsEmpty(tmp_res))
	{
		c = ElemCopy(&tmp_res->value);
		tmp->value = c;
		tmp_res = ListGetTail(tmp_res);
		tmp = ListGetTail(tmp);
	}
	ListDelete(res);
	free(bucket);
	return l;
}


/*
int main()
{
	ElemType e[] = { 7, 2, 5, 4 };

	Item* i = ListCreateEmpty();
	for (int j = 0; j < sizeof(e) / sizeof(e[0]); j++)
	{
		i = ListInsertBack(i, e + j);
	}

	Item* ris = BucketSort(i);
	return 0;
}
*/