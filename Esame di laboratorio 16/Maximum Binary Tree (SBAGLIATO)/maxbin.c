#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void CreaDestra(Node* t, ElemType* v, int count, int indice)
{
    if (t == NULL || count == indice)
    {
        return;
    }

    Node* rightSubtree = TreeCreateRoot(&v[count], NULL, NULL);
    t->right = rightSubtree;

    CreaDestra(rightSubtree, v, count - 1, indice);
}

void CreaSinistra(Node* t, ElemType* v, int count, int indice)
{
    if (t == NULL || count == indice)
    {
        return;
    }

    Node* leftSubtree = TreeCreateRoot(&v[count], NULL, NULL);
    t->left = leftSubtree;

    CreaSinistra(leftSubtree, v, count + 1, indice);
}

Node* CreateMaxBinTree(const ElemType* v, size_t v_size)
{
    if (v == NULL || v_size == 0)
    {
        return NULL;
    }

    ElemType max = 0;
    int indice = 0;
    for (int i = 0; i < v_size; i++)
    {
        if (i == 0 || ElemCompare(&v[i], &max) > 0)
        {
            max = v[i];
            indice = i;
        }
    }

    Node* t = TreeCreateRoot(&max, NULL, NULL);

    CreaSinistra(t, v, 0, indice);
    CreaDestra(t, v, v_size - 1, indice);

    return t;
}
/*
int main()
{
	ElemType v[] = { 3,2,1,6,0,5 };
	size_t v_size = sizeof(v) / sizeof(v[0]);

	Node* ris = CreateMaxBinTree(v, v_size);

	return 0;

}

*/