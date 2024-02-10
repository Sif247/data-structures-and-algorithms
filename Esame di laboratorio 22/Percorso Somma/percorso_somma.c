#include "tree.h"

void PercorsoRec(Node* t, const ElemType* target, int somma, bool* esito)
{
    if (t != NULL && !(*esito))
    {
        somma += t->value;
        if (somma == *target)
        {
            *esito = true;
            return;
        }
        PercorsoRec(t->left, target, somma, esito);
        PercorsoRec(t->right, target, somma, esito);
    }

}

bool PercorsoSomma(Node* t, const ElemType* target) 
{
    if (t == NULL) 
    {
        return false;
    }
    if (t->value >= *target)
    {
        return false;
    }

    int somma = 0;
    bool esito = false;
    PercorsoRec(t, target, somma, &esito);
    return esito;
}


/*
int main()
{
	Node* t = TreeCreateEmpty();
	bool ris = PercorsoSomma(t, 9);
	return 0;
}
*/