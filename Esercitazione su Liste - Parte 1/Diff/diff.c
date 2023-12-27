#include "list.h"

Item* Diff(const Item* i1, const Item* i2)
{

	//controllo
	Item* ris = ListCreateEmpty();
	if (i1 == NULL)
	{
		return ListCreateEmpty();
	}
	
	//sostituzioni variabili per non perdere le info
	Item* tmp1 = i1;
	Item* tmp2 = i2;

	//dichiarazioni
	int esito = 0;
	ElemType n = 0;
	tmp1 = i1;

	while (1)
	{
		//definizione del numero n da ricercare
		n = tmp1->value;
		//riavvolgimento della variabile tmp2 per confrontare nuovamente tutti gli elementi
		tmp2 = i2;
		//ciclo
		while (1)
		{
			//controllo di fine tmp2
			if (tmp2 == NULL)
			{
				break;
			}
			//controllo se elemento presente
			if (n == tmp2->value)
			{
				//se presente esito negativo
				esito = -1;
				break;
			}
			//avanzamento al prossimo numero da confrontare
			tmp2 = ListGetTail(tmp2);
		}

		//se esito rimane positivo alla fine del ciclo inserimento nel risultato finale 
		if (esito == 0)
		{
			ris = ListInsertBack(ris, &n);
		}
		//risettaggio esito
		esito = 0;
		//avanzamento al prossimo numero da confrontare
		tmp1 = ListGetTail(tmp1);
		//controllo fine tmp1
		if (tmp1 == NULL)
		{
			break;
		}
	}
	//ritorno
	return ris;
}