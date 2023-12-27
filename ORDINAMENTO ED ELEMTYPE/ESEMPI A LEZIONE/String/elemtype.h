#pragma once

#include <stdint.h>

typedef struct {
    size_t size;
    char* c;
} String;

typedef String ElemType;

ElemType ElemCopy(const ElemType* e);
void ElemSwap(ElemType* a, ElemType* b);
int ElemCompare(const ElemType* a, const ElemType* b);
void ElemDelete(ElemType* e);
