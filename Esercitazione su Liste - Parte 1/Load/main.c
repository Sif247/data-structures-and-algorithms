#define _CRT_SECURE_NO_WARNINGS

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	//prova 1
	const char NameFile1[] = "data_00.txt";
	Item* ris1 = ListLoad(NameFile1);
	ListWriteStdout(ris1);
	ListDelete(ris1);

	//prova 2
	const char NameFile2[] = "data_01.txt";
	Item* ris2 = ListLoad(NameFile2);
	ListWriteStdout(ris2);
	ListDelete(ris2);

	//prova 3
	const char NameFile3[] = "data_02.txt";
	Item* ris3 = ListLoad(NameFile3);
	ListWriteStdout(ris3);
	ListDelete(ris3);


	return 0;
}