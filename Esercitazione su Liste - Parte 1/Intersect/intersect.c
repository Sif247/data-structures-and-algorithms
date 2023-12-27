#include "list.h"

Item* Intersect(const Item* i1, const Item* i2)
{
	if (i1 == NULL || i2 == NULL)
	{
		return ListCreateEmpty();
	}

	Item* ris = ListCreateEmpty();

	Item* tmpI1 = ListCreateEmpty();
	Item* tmpI2 = ListCreateEmpty();
	ElemType n = 0;
	
	tmpI1 = i1;
	while (1)
	{
		//controlli dei valori
		n = tmpI1->value;
		tmpI2 = i2;
		while (1)
		{
			if (n == tmpI2->value)
			{
				ris = ListInsertBack(ris, &n);
				break;
			}
			tmpI2 = ListGetTail(tmpI2);
			if (tmpI2 == NULL)
			{
				break;
			}
		}
		tmpI1 = ListGetTail(tmpI1);
		if (tmpI1 == NULL)
		{
			break;
		}
	}

	return ris;
}