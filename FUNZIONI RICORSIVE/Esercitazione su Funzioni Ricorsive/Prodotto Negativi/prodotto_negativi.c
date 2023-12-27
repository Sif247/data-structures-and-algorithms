#include <stdio.h>

int ProdottoNegativi(int a, int b) {
    // Caso base: se uno dei numeri è zero, il prodotto è zero
    if (a == 0 || b == 0) {
        return 0;
    }

    // Caso base: se b è positivo, ritorna a + ProdottoNegativi(a, b-1)
    if (b > 0) {
        return a + ProdottoNegativi(a, b - 1);
    }
    // Caso base: se b è negativo, ritorna -a + ProdottoNegativi(a, b+1)
    else {
        return -a + ProdottoNegativi(a, b + 1);
    }
}
/*
int main() {
    int risultato = ProdottoNegativi(-4, 3);
    printf("Il prodotto di -4 e 3 è: %d\n", risultato);

    return 0;
}
*/
