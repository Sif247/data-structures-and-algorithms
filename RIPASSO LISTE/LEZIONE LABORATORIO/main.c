#include "list.h"

int main(void)
{
	ElemType e[] = { 0, 1, 2, 3, 4 };
	//creazione lista
	Item* list = ListCreateEmpty(); // Item *list = NULL // ->equivalenti
		

	//inserimento
	list = ListInsertHead(&e[0], list);
	list = ListInsertHead(&e[1], list);
	list = ListInsertHead(&e[2], list);
	list = ListInsertHead(&e[3], list);
	list = ListInsertHead(&e[4], list);

	//variabile temporanea identica per poter analizzare la lista senza perdere riferimenti
	Item* tmp = list;
	ElemType* v;

	while (!ListIsEmpty(tmp))
	{
		//si inserisce dentro la variabile v il contenuto della testa di tmp
		v = ListGetHeadValue(tmp);
		//per scorrere si rimuove uno alla volta ogni elemento in testa di tmp
		tmp = ListGetTail(tmp);
	}

	return 0;
}