#include "list.h"
#include <limits.h> 

const ElemType* MaxElement(const Item* i) {
	//controllo
	if (i == NULL)
	{
		return NULL;
	}
	// Inizializza con l'indirizzo del primo elemento
	const ElemType* maxAddress = &i->value;
	// Inizializza con il valore del primo elemento
	ElemType max = i->value; 
	//uscita quanto i è NULL
	while (i != NULL) 
	{
		if (i->value > max) 
		{
			//aggiorna il valore del massimo
			max = i->value; 
			// Aggiorna l'indirizzo del massimo
			maxAddress = &i->value; 
		}
		i = ListGetTail(i);
	}
	// Restituisce l'indirizzo del massimo
	return maxAddress; 
}
	

	
