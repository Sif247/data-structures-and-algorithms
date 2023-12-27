static int MinimoRec(const int* v, int v_size, int i)
{
	//caso base
	if (v_size - 1 == i)
	{
		return v[i];
	}

	int min = MinimoRec(v, v_size, i + 1);
}

int Minimo(const int* v, int v_size)
{
	return MinimoRec(v, v_size, 0);
}
//
//int main()
//{
//	const int array[] = { 4, 5, 3, 8 };
//	int num = 4;
//
//	int ris = Minimo(array, num);
//
//	return 0;
//}
//