#include "list.h"

//funzione per la lunghezza
size_t Lenght(const Item* i)
{
	Item *Indicatore = i;
	size_t count = 0;
	while (Indicatore != ListCreateEmpty())
	{
		count++;
		Indicatore = Indicatore->next;
	}
	return count;
}

//funzione principale
Item* Sort(Item* i)
{
	//controllo
	if (i == NULL)
	{
		return NULL;
	}

	//chiamo la funzione per sapere la lunghezza
	size_t dim = Lenght(i);

	//testa fittizia per da usare durante il primo Swap
	Item Head = {.next = i};

	
	//BUBBLE SORT
	bool Modifiche = false;
	while (!Modifiche)
	{
		//controllo di modifica
		Modifiche = true;
		//puntatori precedente, corrente
		Item* prev = &Head;
		Item* curr = prev->next;

		for (size_t j = 0; (j < dim) && (curr->next != NULL); ++j)
		{
			//puntatori successivo e successivo del successivo
			Item* Next = curr->next;
			Item* NextNext = Next->next;
			if (ElemCompare(&curr->value, &Next->value) > 0)
			{
				//spostamento di precedente, corrente in avanti di uno e aggiornamneto
				prev->next = Next;
				Next->next = curr;
				curr->next = NextNext;
				//aggiornamento valori
				prev = Next;
				Modifiche = false;
			}
			else
			{
				prev = curr;
				curr = Next;
			}
		}
		dim--;
	}

	return Head.next;
}