#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, " Il numero di parametri non e' corretto. Sintassi del programma: \"occorrenze <s> < c>\"");
		return 1;
	}
	char* parola = argv[1];
	int tmp = 0;
	for (int i = 0; parola[i] != 0; i++)
	{
		if (argv[2][0] == parola[i])
		{
			tmp++;
		}
	}
	printf("%d", tmp);

	return 0;
}