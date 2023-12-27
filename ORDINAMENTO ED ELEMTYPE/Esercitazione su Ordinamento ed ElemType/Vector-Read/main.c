#include "vettore.h"

int main(void)
{
	char file1[] = "input_int_01.txt";
	Vector* ris1 = VectorRead(file1);
	printf("non ordinato il vettore e': ");
	for (int i = 0; i < ris1->size; i++) {
		ElemWriteStdout(&ris1->data[i]);
		printf(" ");
	}
	printf("\n\ordinato il vettore e': ");
	ris1 = VectorReadSorted("input_int_01.txt");
	for (int i = 0; i < ris1->size; i++) {
		ElemWriteStdout(&ris1->data[i]);
		printf(" ");
	}


	free(ris1->data);
	free(ris1);


	char file2[] = "input_int_02.txt";
	Vector* ris2 = VectorRead(file2);
	printf("\nnon ordinato il vettore e': ");
	for (int i = 0; i < ris2->size; i++) {
		ElemWriteStdout(&ris2->data[i]);
		printf(" ");
	}
	printf("\n\ordinato il vettore e': ");
	ris2 = VectorReadSorted("input_int_02.txt");
	for (int i = 0; i < ris2->size; i++) {
		ElemWriteStdout(&ris2->data[i]);
		printf(" ");
	}


	free(ris2->data);
	free(ris2);

	return 0;

}