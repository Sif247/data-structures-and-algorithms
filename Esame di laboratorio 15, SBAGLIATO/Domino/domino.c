#include "domino.h"

void DominoRec(const Tessera* t, size_t t_size, size_t* ret_size, int lvl, Placing* vcurr, Placing* vbest)
{
	if (lvl == t_size)
	{
		
	}


}

Placing* Domino(const Tessera* t, size_t t_size, size_t* ret_size)
{
	Placing* vcurr = calloc(t_size, sizeof(Placing));
	Placing* vbest = calloc(t_size, sizeof(Placing));
	DominoRec(t, t_size, ret_size, 0, vcurr, &vbest);
	free(vcurr);
	free(vbest);
}


int main()
{
	Tessera t[] = { {.val1 = 5, .val2 = 3}, {.val1 = 5, .val2 = 6}, {.val1 = 5, .val2 = 4}, {.val1 = 6, .val2 = 2} };
	size_t dim = 4;
	size_t returnSize = 0;

	Placing* ris = Domino(t, dim, &returnSize);
	return 0;


}