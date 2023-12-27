#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "elemtype.h"
#include <stdlib.h>
#include <limits.h>

typedef struct {
    size_t capacity;
    size_t size;
    ElemType* data;
} Vector;

Vector* VectorRead(const char* filename);
Vector* VectorReadSorted(const char* filename);