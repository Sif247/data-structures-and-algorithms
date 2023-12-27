#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int p;
    int a;
    int l;
} Cartone;

typedef struct {
    int a;
    int p;
    int c_size;
    int* c_ids;
} Torre;

extern void TorreCartoni(const Cartone* c, size_t n);

// TORRE_CARTONI_H_
