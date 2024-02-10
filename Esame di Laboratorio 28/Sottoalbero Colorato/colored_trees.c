#include "tree.h"

const Node* BiggestColoredTree(const Node* t)
{
	if (t == NULL)
	{
		return NULL;
	}
}

int main(void)
{
	Node* root = TreeCreateEmpty();

	root = TreeCreateRoot("r",
		TreeCreateRoot("b",
			TreeCreateRoot("b", NULL, NULL),
			TreeCreateRoot("b", NULL,
				TreeCreateRoot("v", NULL, NULL))),
			TreeCreateRoot("v", NULL,
				TreeCreateRoot("v", NULL, NULL)));
		
	Node* ris = BiggestColoredTree(root);
}