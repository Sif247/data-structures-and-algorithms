#include <stdlib.h>
#include <stdio.h>

void ToUpper(char* str)
{
	if (str == NULL)
	{
		return;
	}
	for (int i = 0; *(str + i) != 0; i++)
	{
		if (*(str + i) >= 'a' && *(str + i) <= 'z')
		{
			*(str + i) = *(str + i) - ('a' - 'A');
		}
	}
	printf("%s", str);

	return;
}
/*
int main()
{
	char str[] = "Non Mollare Mai";
	ToUpper(str);
	return 0; 
}
*/