#include "tree.h"

const ElemType* BstTreeMin(const Node* n);
extern const ElemType* TreeMin(const Node* n);

int main(void)
{
	const ElemType e[] = { 5,4,21,7,8,9,10 };

	//                     5
	//		              / \
	//                   4   9
	//                  / \ / \
	//                 21  7 8 10
	//                 |        |
	//risultati->  (NON BST)  (BST) 



	Node* v = TreeCreateRoot(e + 0,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 2, NULL, NULL),
			TreeCreateRoot(e + 3, NULL, NULL)),
		TreeCreateRoot(e + 5,
			TreeCreateRoot(e + 4, NULL, NULL),
			TreeCreateRoot(e + 6, NULL, NULL)));

	const ElemType* MinBst = BstTreeMin(v);
	ElemWriteStdout(MinBst);
	printf("\n");

	const ElemType* Min = TreeMin(v);
	ElemWriteStdout(Min);

	TreeDelete(v);
	return 0;
}