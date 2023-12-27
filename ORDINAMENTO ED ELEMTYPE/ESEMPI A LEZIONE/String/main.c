#include "elemtype.h"

#include <stdlib.h>
#include <string.h>

ElemType ElemCopy(const ElemType* e) {
    ElemType copy = { .size = e->size,
                    .c = malloc(e->size)
    };
    memcpy(copy.c, e->c, e->size);

    return copy;
}

void ElemSwap(ElemType* a, ElemType* b) {
    ElemType tmp = *a;
    *a = *b;
    *b = tmp;
}

// < 0 (ad esempio -1) se a è minore di b
// 0  se a uguale a b
// > 0 (ad esempio 1) se a è maggiore di b
int ElemCompare(const ElemType* a, const ElemType* b) {
    for (size_t i = 0; i < a->size && i < b->size; ++i) {
        if (a->c[i] < b->c[i]) {
            return -1;
        }
        else if (a->c[i] > b->c[i]) {
            return 1;
        }
    }
    if (a->size < b->size) {
        return -1;
    }
    else if (a->size > b->size) {
        return 1;
    }

    return 0;
}

void ElemDelete(ElemType* e) {
    free(e->c);
}