#include "list.h"

Item* IntersectNoRep(const Item* i1, const Item* i2)
{
	//controllo
	if (i1 == NULL || i2 == NULL)
	{
		return ListCreateEmpty();
	}
	//variabili
	Item* tmp1 = i1;
	Item* tmp2 = i2;
	Item* ris = ListCreateEmpty();
	Item* tmp_ris = ris;
	ElemType n = 0;
	int esito;
	//scorrimento tmp1
	while (1)
	{
		n = tmp1->value;
		tmp2 = i2;
		esito = 1;
		//scorrimento tmp2
		while (1)
		{
			if (tmp2 == NULL)
			{
				break;
			}
			if (n == tmp2->value)
			{
				tmp_ris = ris;
				//scorrimento tmp_ris
				while (1)
				{
					if (tmp_ris == NULL)
					{
						break;
					}
					if (n == tmp_ris->value)
					{
						esito = 0;
						break;
					}
					tmp_ris = ListGetTail(tmp_ris);
				}

				if (esito != 0)
				{
					ris = ListInsertBack(ris, &n);
				}
			}
			tmp2 = ListGetTail(tmp2);
		}
		tmp1 = ListGetTail(tmp1);
		if (tmp1 == NULL)
		{
			break;
		}
	}
	return ris;
}



Item* DiffNoRep(const Item* i1, const Item* i2)
{
	//controllo
	if (i1 == NULL)
	{
		return ListCreateEmpty();
	}

	//variabili
	Item* tmp1 = i1;
	Item* tmp2 = i2;
	Item* ris = ListCreateEmpty();
	Item* tmp_ris = ris;
	ElemType n = 0;
	int esito;
	//scorrimento tmp1
	while (1)
	{
		esito = 1;
		n = tmp1->value;
		tmp2 = i2;
		while (1)
		{
			if (tmp2 == NULL)
			{
				break;
			}
			else if (n == tmp2->value)
			{
				esito = 0;
			}
			tmp2 = ListGetTail(tmp2);
		}

		
		if (esito == 1)
		{
			tmp_ris = ris;
			while (1)
			{
				if (tmp_ris == NULL)
				{
					break;
				}
				else if (tmp_ris->value == n)
				{
					esito = 0;
					break;
				}
				tmp_ris = ListGetTail(tmp_ris);
			}

			if (esito == 1)
			{
				ris = ListInsertBack(ris, &n);
			}
		}
		tmp1 = ListGetTail(tmp1);
		if (tmp1 == NULL)
		{
			break;
		}
		
	}

	
	return ris;
}