#include "list.h"

extern Item* Delete(Item* i, const char* name);

int main()
{
    //elementi
    ElemType e[] = {
                { "Michele", "Firenze", 12, "Modena", "MO", "41126" },
                { "Federico", "Peschiera", 54, "Modena", "MO", "41126" },
                { "Massimiliano", "Roma", 23, "Firenze", "FI", "50100" },
                { "Massimiliano", "Newton", 23, "Modena", "MO", "41126" },
                { "Stefano", "Ciro Menotti", 10, "Milano", "MI", "20019" }
    };

    //creazione lista
    Item* ab = ListCreateEmpty();
    //inserimento
    for (size_t i = 0; i < sizeof(e) / sizeof(ElemType); ++i) {
        ab = ListInsertBack(ab, &e[i]);
    }
    //chiamata a funzione
    ab = Delete(ab, e[1].name);
    ListDelete(ab);

    return 0;
}