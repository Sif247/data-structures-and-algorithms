#include "torrecartoni.h"

static void TorreCartoniRec(const Cartone* c, size_t n, Torre* vcurr, Torre* vbest, int i, bool* usati) 
{
 
     if (vcurr->a > vbest->a)
     {
         vbest->a = vcurr->a;
         vbest->c_size = vcurr->c_size;
         vbest->p = vcurr->p;
         for (int k = 0; k < vcurr->c_size; ++k) {
             vbest->c_ids[k] = vcurr->c_ids[k];
         }
     }
 
 
     if (i == n)
     {
         return;
     }

    //ciclo di assegnamento
    for (int j = 0; j < n; j++)
    {
        if (!usati[j] && c[j].l >= vcurr->p)
        {
            vcurr->a += c[j].a;
            vcurr->p += c[j].p;
            vcurr->c_ids[vcurr->c_size] = j;
            vcurr->c_size++;

            usati[j] = true;
            TorreCartoniRec(c, n , vcurr, vbest, i + 1, usati);

            vcurr->a -= c[j].a;
            vcurr->p -= c[j].p;
            vcurr->c_size--;
            usati[j] = false;
        }
    }
    
}

void TorreCartoni(const Cartone* c, size_t n) 
{
    Torre vcurr = {.a = 0, .p = 0, .c_size = 0, .c_ids = calloc(n, sizeof(int))};
    Torre vbest = {.a = 0, .p = 0, .c_size = 0, .c_ids = calloc(n, sizeof(int))};
    bool* usati = calloc(n, sizeof(bool));
    TorreCartoniRec(c, n, &vcurr, &vbest, 0, usati);
    for (int b = 0; b < vbest.c_size; b++)
    {
        printf("%d\n", vbest.c_ids[b]);
    }
    printf("l'altezza e' %d: ", vbest.a);
    free(vcurr.c_ids);
    free(vbest.c_ids);
    free(usati);
}
/*
int main() {
    Cartone a[] = { {.p = 25, .a = 20, .l = 50}, {.p = 10, .a = 10, .l = 8}, {.p = 9, .a = 3, .l = 5},
                    {.p = 5, .a = 20, .l = 200}, {.p = 10, .a = 10, .l = 202}, {.p = 24, .a = 3, .l = 55} };
    size_t b = sizeof(a) / sizeof(a[0]);
    TorreCartoni(a, b);

    Cartone c[] = { {.p = 10, .a = 20, .l = 40 }, {.p = 10, .a = 10, .l = 8 }, {.p = 9, .a = 3, .l = 5 } };
    size_t n = sizeof(c) / sizeof(c[0]);
    TorreCartoni(c, n);

    return 0;
}
*/