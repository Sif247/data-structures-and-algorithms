#include "tree.h"



void SostituisciSomma(Node* t)
{
	if (t == NULL || TreeIsLeaf(t))
	{
		return;
	}


	if (t->left->value != NULL && t->right->value != NULL)
	{
		t->value += t->left->value + t->right->value;
	}
	else if (t->left->value == NULL && t->right->value != NULL)
	{
		t->value += t->right->value;
	}
	else if (t->left->value != NULL && t->right->value == NULL)
	{
		t->value += t->left->value;
	}

	SostituisciSomma(t->left);
	SostituisciSomma(t->right);

	
}
/*
int main(void)
{
	Node* root = TreeCreateEmpty();
	SostituisciSomma(root)
	return 0;
}
*/