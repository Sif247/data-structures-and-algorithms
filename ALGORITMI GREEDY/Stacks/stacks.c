#include "stacks.h">

unsigned obiettivo(Stack* stacks, size_t n)
{
    unsigned sommabest = UINT_MAX;
    for (int i = 0; i < n; ++i)
    {
        unsigned somma = 0;
        for (int j = 0; j < stacks[i].m; ++j)
        {
            somma += stacks[i].elements[j];
        }
        if (somma < sommabest)
        {
            sommabest = somma;
        }
    }

    return sommabest;
}

void accorciamento(Stack* stacks, size_t n, unsigned sommabest)
{
    for (int i = 0; i < n; ++i)
    {
        unsigned somma = 0;
        for (int j = 0; j < stacks[i].m; ++j)
        {
            somma += stacks[i].elements[j];
        }
        if (somma > sommabest)
        {
            stacks[i].elements[stacks[i].m - 1] = 0;
            stacks[i].m--;
        }
    }
}

bool controllo(Stack* stacks, size_t n, unsigned sommabest)
{
    bool* corretti = calloc(n, sizeof(bool));

    for (int i = 0; i < n; ++i)
    {
        unsigned somma = 0;
        for (int j = 0; j < stacks[i].m; ++j)
        {
            somma += stacks[i].elements[j];
        }
        if (somma == sommabest)
        {
            corretti[i] = true;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (corretti[i] == false)
        {
            return false;
        }
    }

    return true;

}


unsigned MaxSumNStack(Stack* stacks, size_t n)
{
    bool esito = false;
    unsigned sommabest;
    do {
        sommabest = obiettivo(stacks, n);
        accorciamento(stacks, n, sommabest);
        esito = controllo(stacks, n, sommabest);
    } while (esito == false);

    /*mi da errore di memoria, forse è perchè non ho liberato stacks, ancora non l'ho provato
    for (int i = 0; i < n; i++)
    {
        free(stacks[i].elements);
    }
    */
    return sommabest;

}


int main()
{
    unsigned elements1[] = { 1, 1, 1, 2, 3 };
    unsigned elements2[] = { 2, 3};
    unsigned elements3[] = { 1, 4, 5, 2 };

    Stack stack1 = { .elements = elements1, .m = 5 };
    Stack stack2 = { .elements = elements2, .m = 2 };
    Stack stack3 = { .elements = elements3, .m = 4 };

    // Raggruppamento degli stack in un array
    Stack stacks[] = { stack1, stack2, stack3 };
    size_t n = sizeof(stacks) / sizeof(stacks[0]);

    // Calcolo della soluzione massima
    unsigned result = MaxSumNStack(stacks, n);

    printf("La soluzione massima trovata è: %u\n", result);

    return 0;
}
