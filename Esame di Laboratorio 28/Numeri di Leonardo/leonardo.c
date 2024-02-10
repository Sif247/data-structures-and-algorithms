#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h> 

static int Leonardo(int n, int* ris)
{
    ris[0] = 1;
    ris[1] = 1;
   if (ris[n] == 0)
   {
       ris[n] = Leonardo(n - 1, ris) + Leonardo(n - 2, ris) + 1;
   }
   return ris[n];
   
}

int main(int argc, char* argv[])
{
    // controllo
    if (argc != 2)
    {
        return 1; // Codice di errore 1
    }

    // numero da elaborare
    char *tmp = NULL;
    int n = strtoll(argv[1], tmp , 10);
    if (tmp != NULL)
    {
        return 1;
    }


    // controllo
    if (n < 0)
    {
        return 1; // Codice di errore 1
    }
    else
    {
        int* ris = calloc(n + 1, sizeof(int));
        Leonardo(n, ris);
        
        for (int i = 0; i <= n; i++)
        {
            printf("%d\t", ris[i]);
        }
        return 0; // Codice corretto 1
    }
}