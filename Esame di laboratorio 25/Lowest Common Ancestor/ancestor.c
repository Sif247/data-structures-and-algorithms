#include "tree.h"

bool TreeContainsNode(const Node* tree, const Node* node)
{
	if (tree == NULL)
	{
		return false;
	}
	if (tree == node)
	{
		return true;
	}
	return TreeContainsNode(TreeLeft(tree), node) || TreeContainsNode(TreeRight(tree), node);
}

const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2)
{
	if (t == NULL || n1 == NULL || n2 == NULL)
	{
		return NULL;
	}

	if (TreeContainsNode(t->left, n1) && TreeContainsNode(t->left, n2)) 
	{
		return LowestCommonAncestor(t->left, n1, n2);
	}
	if (TreeContainsNode(t->right, n1) && TreeContainsNode(t->right, n2))
	{
		return LowestCommonAncestor(t->right, n1, n2);
	}

	return t;

}

/*
int main()
{
	ElemType e[] = "abcdefgh";

	Node* root = TreeCreateRoot(e,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 3, NULL, NULL),
			TreeCreateRoot(e + 4, NULL, NULL)),
		TreeCreateRoot(e + 2,
			TreeCreateRoot(e + 5, NULL,
				TreeCreateRoot(e + 7, NULL, NULL)),
			TreeCreateRoot(e + 6, NULL, NULL)));

	Node* ris = LowestCommonAncestor(root, root->left->left, root->left->left);

	return 0;

}
*/