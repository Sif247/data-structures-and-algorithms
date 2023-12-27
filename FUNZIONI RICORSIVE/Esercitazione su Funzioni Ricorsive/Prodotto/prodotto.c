int ProdottoIndice(int a, int b, int i, int tmp)
{
	if (i == b)
	{
		return a;
	}
	else
	{
		return ProdottoIndice(a + tmp, b, i + 1, tmp);
	}
}

int Prodotto(int a, int b)
{
	if (a == 0)
	{
		return 0;
	}
	else if(a < 0)
	{
		return -1;
	}

	if (b == 0)
	{
		return 0;
	}
	else if (b < 0)
	{
		return -1;
	}

	return ProdottoIndice(a, b, 1, a);
}
/*
int main(void)
{
	int ris;

	ris = Prodotto(4, 3);
	ris = Prodotto(5, 3);
	ris = Prodotto(4, 4);
	ris = Prodotto(6, 6);
	ris = Prodotto(7, 2);
	ris = Prodotto(9, 9);
	ris = Prodotto(1, 0);


	return 0;
}
*/