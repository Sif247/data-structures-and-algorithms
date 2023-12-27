#include "tree.h"

extern bool TreeIsMirror(const Node* t);

int main(void)
{
	ElemType* e[] = { 0, 1, 1, 4, 2, 2, 4 };

	//            0
	//			 / \
	//          1   1
	//         / \ / \
	//        4  2 2  4
	//          

	Node* n = TreeCreateRoot(e + 0,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 3, NULL, NULL),
			TreeCreateRoot(e + 4, NULL, NULL)),
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 3, NULL, NULL),
			TreeCreateRoot(e + 4, NULL, NULL)));

	bool ris = TreeIsMirror(n);
	TreeDelete(n);
	
}