#include "list.h"

extern Item* Append(const Item* i1, const Item* i2);

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



    //elementi
    ElemType b[] = {
                { "Francesco", "Firenze", 12, "Modena", "MO", "41126" },
                { "Gianpaolo", "Peschiera", 54, "Modena", "MO", "41126" },
                { "Carlotta", "Roma", 23, "Firenze", "FI", "50100" },
                { "Carla", "Newton", 23, "Modena", "MO", "41126" },
                { "Mirabello", "Ciro Menotti", 10, "Milano", "MI", "20019" }
    };

    //creazione lista
    Item* ba = ListCreateEmpty();
    //inserimento
    for (size_t i = 0; i < sizeof(b) / sizeof(ElemType); ++i) {
        ba = ListInsertBack(ba, &b[i]);
    }
    //chiamata a funzione
    Item* ris =  Append(ba,ab);
    ListDelete(ab);
    ListDelete(ba);
    ListDelete(ris);

    return 0;
}
