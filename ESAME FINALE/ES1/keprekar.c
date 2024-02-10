#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//funzioni fornite
int CompareChars(const void* a, const void* b) {
	int int_a = *(const char*)a;
	int int_b = *(const char*)b;
	return (int_a > int_b) - (int_a < int_b);
}
void GetNumbers(const char* digits, int* high, int* low) {
	char* digits_copy = malloc(4);
	memcpy(digits_copy, digits, 4);
	qsort(digits_copy, 4, sizeof(char), CompareChars); // Sort the digits
	char rev_digits[4] = { digits_copy[3], digits_copy[2], digits_copy[1], digits_copy[0] }; // Copy reversed
	char* endptr;
	*high = strtol(rev_digits, &endptr, 10);
	*low = strtol(digits_copy, &endptr, 10);
	free(digits_copy);
}
//fine funzioni fornite



int Lenght(int n, bool* cifre)
{
	int ris = 0;
	int prec = 0;
	while (n != 0)
	{
		if (n != prec)
		{
			*cifre = true;
		}
		ris++;
		prec = n;
		n /= 10;
	}
	return ris;
}

//funzione che dovrebbe trasformare un intero in una stringa da 4 caratteri
//non funziona----> risolto alla fine
char* TrasformaStringa(int n)
{
	char* ris = calloc(4, sizeof(char) + 1);
	int val = 0;
	val = n % 10;
	ris[3] =  val + '0';
	n /= 10;
	val = n % 10;
	ris[2] = val + '0';
	n /= 10;
	val = n % 10;
	ris[1] = val + '0';
	n /= 10;
	val = n % 10;
	ris[0] = val + '0';
	n /= 10;

	return ris;
}


int Keprekar(int n, int* ris, int lvl)
{
	if (*ris == 6174 || lvl > 10)
	{
		return *ris;
	}

	n = *ris;

	//non funziona
	char* ordina = TrasformaStringa(n);
	printf("%d ", *ris);

	int crescente = 0;
	int decrescente = 0;
	GetNumbers(ordina, &crescente, &decrescente);
	*ris = crescente - decrescente;
	Keprekar(n, ris, lvl + 1);
}



int main(int argc, char** argv)
{
	if (argc != 2)
	{
		return 1; //codice errore
	}

	int n = atoi(argv[1]);//salvataggio num di partenza

	if (n < 0)
	{
		return 1;
	}

	bool cifre = false;
	// calcolo lunghezza e controglio uguaglianza cifre
	int dim = Lenght(n, &cifre);
	int lvl = 0;
	if (dim > 4 || !cifre || dim < 4)
	{
		printf("Invalid number");
		return 0;
	}

	//funzione di keprekar
	int ris = n;
	ris = Keprekar(n, &ris, lvl);
	printf("%d", ris);

	//ritorna
	return 0;


}