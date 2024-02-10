#include <stdlib.h>

void InsertionSort(int* v, size_t v_size)
{
	if (v == NULL || v_size < 1)
	{
		return;
	}

	for (int i = 1; i < v_size; i++)
	{
		int key = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > key) 
		{
			v[j + 1] = v[j];
			j--;
		}

		
		v[j + 1] = key;

	}
	
}
/*
int main()
{
	int e[] = { 5,3,7,9,8,1 };
	
	size_t dim = sizeof(e) / sizeof(e[0]);

	InsertionSort(e, dim);
	return 0;

}
*/