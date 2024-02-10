#include "tree.h"
#include <stdlib.h>


Node* TreeInsert(Node * root, ElemType value)
{
	if (root == NULL)
	{
		// Albero vuoto, crea un nuovo nodo
		return TreeCreateRoot(&value, NULL, NULL);
	}

	// Inserimento ricorsivo
	if (ElemCompare(&value, TreeGetRootValue(root)) < 0)
	{
		// Inserisci a sinistra se il valore è minore
		root->left = TreeInsert(TreeLeft(root), value);
	}
	else
	{
		// Inserisci a destra se il valore è maggiore o uguale
		root->right = TreeInsert(TreeRight(root), value);
	}

	return root;
}

void Tree2BstRec(const Node* n, Node** bst)
{
	if (TreeIsEmpty(n))
	{
		return;
	}

	Tree2BstRec(TreeLeft(n), bst);

	// Aggiungi il valore corrente all'albero BST
	*bst = TreeInsert(*bst, *TreeGetRootValue(n));

	Tree2BstRec(TreeRight(n), bst);
}


Node* Tree2Bst(const Node* t)
{
	if (TreeIsEmpty(t))
	{
		return NULL;
	}

	Node* ris = TreeCreateEmpty();
	Tree2BstRec(t, &ris);



	return ris;

}


/*
int main()
{
	Node* t = TreeCreateEmpty();

	ElemType e[] = {6, 2, 3, 8, 5, 9, 3};
	t = TreeCreateRoot(e,
			TreeCreateRoot(e + 1,
				TreeCreateRoot(e + 2, NULL, NULL),
				TreeCreateRoot(e + 3, NULL,
					TreeCreateRoot(e + 4, NULL, NULL))),
			TreeCreateRoot(e + 5, NULL,
				TreeCreateRoot(e + 6, NULL, NULL)));

	Node* ris = Tree2Bst(t);

}
*/