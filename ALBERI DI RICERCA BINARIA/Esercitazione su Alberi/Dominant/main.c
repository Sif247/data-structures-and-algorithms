#include "tree.h"

extern int CountDominant(const Node* t);

int main(void)
{
	ElemType e[] = { 12, 4, 21, 0, 2, 5, 18, 77, 8, 13};

	//				12
	//			   /  \
	//			  4    21
	//			 / \   / \
	//          0   2 13  5   
	//
	//

	 Node* t = TreeCreateRoot(e + 0,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 3, NULL, NULL),
			TreeCreateRoot(e + 4, NULL, NULL)),
		TreeCreateRoot(e + 2,
			TreeCreateRoot(e + 9, NULL, NULL),
			TreeCreateRoot(e + 5, NULL, NULL)));


	int ris = CountDominant(t);

	printf("il numero di nodi dominanti e' %d ", ris);
	TreeDelete(t);
					
}