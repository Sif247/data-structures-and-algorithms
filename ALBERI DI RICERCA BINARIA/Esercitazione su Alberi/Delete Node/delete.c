#include "tree.h"


Node* DeleteBstNode(Node* n, const ElemType* key)
{
	//controllo
	if (n == NULL)
	{
		return NULL;
	}
	//esito confronto
	int confr = ElemCompare(TreeGetRootValue(n), key);
	
	// key piu grande allora scegliamo il nodo destro
	if (confr > 0)
	{
		n = DeleteBstNode(n->right, key);
	}
	//key piu piccola allora scegliamo il nodo sinistro
	else if (confr < 0)
	{
		n = DeleteBstNode(n->left, key);
	}
	//key trovata allora dividiamo i 3 casi 
	else if (confr == 0)
	{
		//caso foglia (piu facile)
		if (TreeIsLeaf(n))
		{
			//eliminazione diretta
			TreeDelete(n);
			n = NULL;
		}
		//caso solo un figlio
		else if (n->left == NULL) 
		{
			Node* tmp = n;
			n = n->right;
			TreeDelete(tmp);
		}
		else if (n->right == NULL)
		{
			Node* tmp = n;
			n = n->left;
			TreeDelete(tmp);
		}
		//caso due figli (più difficile)
		else {
			
			Node* min = n->right;
			while (min->left != NULL) {
				min = min->left;
			}

			n->value = ElemCopy(&(min->value));
			n->right = DeleteBstNode(n->right, &(min->value));
			TreeDelete(min);
		}
	}
	return n;
}