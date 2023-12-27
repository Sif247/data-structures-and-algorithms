#include "elemtype.h"

#include <stdlib.h>
#include <string.h>

ElemType ElemCopy(const ElemType* e) {
    return *e;
}

void ElemSwap(ElemType* a, ElemType* b) {
    ElemType tmp = *a;
    *a = *b;
    *b = tmp;
}

int ElemCompare(const ElemType* a, const ElemType* b) {
    if (*a < *b) {
        return -1;
    }
    else if (*a > *b) {
        return 1;
    }
    return 0;
}

void ElemDelete(ElemType* e) {}