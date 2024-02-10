#include <stdlib.h>
#include "list.h"

const Item* CommonTail(const Item* i1, const Item* i2)
{
	if (i1 == NULL || i2 == NULL)
	{
		return NULL;
	}

	Item* tmp1 = i1;
	while (tmp1 != NULL)
	{
		Item* tmp2 = i2;
		while (tmp2 != NULL)
		{
			if (tmp1->next == tmp2->next)
			{
				if (tmp1->next == NULL)
				{
					return NULL;
				}
				return tmp1;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}

	return NULL;
}


/*
int main()
{
	ElemType e1[] = { 1,2,3,4,5,6 };
	ElemType e2[] = { 4,8,6,7 };
	ElemType com[] = { 10,11 };

	int dimcom = sizeof(com) / sizeof(com[0]);
	int dim_e1 = sizeof(e1) / sizeof(e1[0]);
	int dim_e2 = sizeof(e2) / sizeof(e2[0]);

	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();

	int c = 0;
	for (int j = 0; j < dim_e1 + dimcom; j++)
	{
		if (j < dim_e1)
		{
			i1 = ListInsertBack(i1, e1 + j);
		}
		else
		{
			i1 = ListInsertBack(i1, com + c);
			c++;
		}
	}

	int d = 0;
	for (int j = 0; j < dim_e2 + dimcom; j++)
	{
		if (j < dim_e2)
		{
			i2 = ListInsertBack(i2, e2 + j);
		}
		else
		{
			i2 = ListInsertBack(i2, com + d);
			d++;
		}
	}

	Item* ris = CommonTail(i1, i2);
	return 0;

}
*/
