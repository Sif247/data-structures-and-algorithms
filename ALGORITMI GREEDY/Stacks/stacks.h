#pragma once

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    unsigned* elements;
    size_t m;
} Stack;

extern unsigned MaxSumNStack(Stack* stacks, size_t n);