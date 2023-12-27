#include "tree.h"

Node* BstInsert(const ElemType* e, Node* n)
{
	//controllo
	if (TreeIsEmpty(n))
	{
		return TreeCreateRoot(e, NULL, NULL);
	}

	//variabile temporanea
	Node* tmp = n;
	bool left = false;

	while (!TreeIsEmpty(tmp))
	{
		if (ElemCompare(e, TreeGetRootValue(tmp)) <= 0)
		{
			left = true;
			if (tmp->left == NULL)
			{
				break;
			}
			tmp = tmp->left;
		}
		else
		{
			left = false;
			if (tmp->right == NULL)
			{
				break;
			}
			tmp = tmp->right;
		}
	}

	if (left)
	{
		tmp->left = TreeCreateRoot(e, NULL, NULL);
	}
	else
	{
		tmp->right = TreeCreateRoot(e, NULL, NULL);
	}
	return n;

}
			






Node* BstInsertRec(const ElemType* e, Node* n)
{
	if (TreeIsEmpty(n))
	{
		return TreeCreateRoot(e, NULL, NULL);
	}
	
	if (ElemCompare(e, TreeGetRootValue(n)) <= 0)
	{
		n->left = BstInsertRec(e, TreeLeft(n));
	}
	else
	{
		n->right = BstInsertRec(e, TreeRight(n));
	}

	return n;
}