#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void CombinaMoneteRec(int b, const int* m, size_t m_size, int lvl, int* vcurr, int* nsol)
{
    if (b == 0)
    {
        (*nsol)++;
        for (size_t i = 0; i < m_size; i++)
        {
            printf("%d ", vcurr[i]);
        }
        printf("\n");
        return;
    }

    if (lvl == m_size || b < 0)
    {
        return;
    }

    for (int i = 0; i <= b / m[lvl]; i++)
    {
        vcurr[lvl] = i;
        CombinaMoneteRec(b - i * m[lvl], m, m_size, lvl + 1, vcurr, nsol);
        vcurr[lvl] = 0;
    }
}

int CombinaMonete(int b, const int* m, size_t m_size)
{
	int* vcurr = calloc(m_size, sizeof(int));
	int nsol = 0;
	CombinaMoneteRec(b, m, m_size, 0, vcurr, &nsol);
	free(vcurr);
	return nsol;
}
/*
int main()
{
	int b = 4;
	int m[] = {1, 2, 50, 10, 5, 20};
	int size = sizeof(m) / sizeof(m[0]);
	int ris =  CombinaMonete(b,m,size);

	return 0;
}
*/