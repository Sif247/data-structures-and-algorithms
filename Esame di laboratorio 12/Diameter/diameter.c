#include "tree.h"
#include <stdlib.h>

void HeightRec(const Node* n, int lvl, int* tot) 
{
	if (TreeIsEmpty(n)) 
	{
		return;
	}

	HeightRec(TreeLeft(n), lvl + 1, tot);
	HeightRec(TreeRight(n), lvl + 1, tot);

	if (lvl > *tot)
	{
		*tot = lvl;
	}
}


int Diameter(const Node* t)
{
	if (TreeIsEmpty(t))
	{
		return 0;
	}
	
	int left = 0;
	int right = 0;
	HeightRec(TreeLeft(t),1, &left);
	HeightRec(TreeRight(t),1, &right);
	
	int leftDiameter = Diameter(TreeLeft(t));
	int rightDiameter = Diameter(TreeRight(t));

	int tot = ElemCompare(&leftDiameter, &rightDiameter);
	int somma = (left + right + 1);
	tot = ElemCompare(&tot, &somma);

	return tot;
}



int main()
{
	Node* t = TreeCreateEmpty();
	ElemType e[] = { 5,8,7,9,3,7 };

	//				8
	//			  /   \
	//           4      5
	//          / \      \
	//         7   8       8
	//              \  
	//               6
	//                \ 
	//	               8

	t = TreeCreateRoot(e,
			TreeCreateRoot(e + 1,
				TreeCreateRoot(e, NULL, NULL),
				TreeCreateRoot(e, NULL,
					TreeCreateRoot(e, NULL,
						TreeCreateRoot(e, NULL, NULL)))),
			TreeCreateRoot(e + 4, NULL,
				TreeCreateRoot(e + 5, NULL, NULL)));

	int ris = Diameter(t);
	return 0;

}

