#include "tree.h"

bool TreeIsMirrorRec(Node* left, Node* right)
{
	//se uno dei due è vuoto anche l'altro deve esserlo per garantire la simmetria
	if (TreeIsEmpty(left) || TreeIsEmpty(right))
	{
		if (TreeIsEmpty(left) && TreeIsEmpty(right))
		{
			return true;
		}
		return false;
	}

	if (TreeIsLeaf(left) || TreeIsLeaf(right))
	{
		//se entrambi sono foglie e hanno lo stesso valore allora è vero
		if (TreeIsLeaf(left) && TreeIsLeaf(right)
			&& ElemCompare(&left->value, &right->value) == 0)
		{
			return true;
		}
		return false;
	}
	// se entrambe non sono foglie allora si visitano i sotto alberi
	else if (!TreeIsLeaf(left) && !TreeIsLeaf(right))
	{
		// se i nodi hanno lo stesso valore allora si può procedere
		if(ElemCompare(&left->value, &right->value) == 0)
		{
			//si fa il confronto tra nodo destro e sinistro del primo con quello del secondo
			return (TreeIsMirrorRec(left->right, right->left) && TreeIsMirrorRec(left->left, right->right));
		}
		return false;
	}

}

bool TreeIsMirror(const Node* t)
{
	//controllo
	if (TreeIsEmpty(t))
	{
		return true;
	}
	
	bool ris = TreeIsMirrorRec(t->left, t->right);
	return ris;
}