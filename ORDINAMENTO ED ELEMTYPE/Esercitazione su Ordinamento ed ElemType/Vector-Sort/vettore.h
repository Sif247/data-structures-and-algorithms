#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "elemtype.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    size_t capacity;
    size_t size;
    ElemType* data;
} Vector;

extern void VectorSort(Vector* v);
