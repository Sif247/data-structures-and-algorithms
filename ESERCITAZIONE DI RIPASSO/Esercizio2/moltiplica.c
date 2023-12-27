#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: \"mul <a> < b>\"");
		return 1;
	}
	char *n1 = argv[1];
	char *n2 = argv[2];
	int numero1 = atoi(n1);
	int numero2 = atoi(n2);
	int ris = numero1 * numero2;

	fprintf(stdout, "%d", ris);
	return 0;
}