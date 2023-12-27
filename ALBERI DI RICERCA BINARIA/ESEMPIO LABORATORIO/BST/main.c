#include "tree.h"

int main(void)
{
	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };


	//Rappresentiamo:
	//		15
	//	   /  \
	//	  10  21
	//   /  \
	//  3    12


	// radice
	Node* tot = TreeCreateRoot(&e[15],
		//sinistra
		TreeCreateRoot(&e[10],
			//sottoradice sinistra
			TreeCreateRoot(&e[3], NULL, NULL),
			//sottoradice destra
			TreeCreateRoot(&e[12], NULL, NULL)),
		//destra
		TreeCreateRoot(&e[21], NULL, NULL));

	return 0;
}