#include "tree.h"

extern Node *DeleteBstNode(Node *n, const ElemType *key);

int main(void)
{

	const ElemType e[] = { 5,4,21,7,8,9,10 };

	//                     5
	//		              / \
	//                   2   9
	//                  / \ / \
	//                 1  4 8 10
	//                / \




	Node *v = TreeCreateRoot(e + 0,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 2, NULL, NULL),
			TreeCreateRoot(e + 3, NULL, NULL)),
		TreeCreateRoot(e + 5, 
			TreeCreateRoot(e + 4, NULL, NULL),
			TreeCreateRoot(e + 6, NULL, NULL)));

	ElemType key = 9;
	v = DeleteBstNode(v, &key);
	TreeWriteStdoutPreOrder(v);

	TreeDelete(v);
	return 0;
}