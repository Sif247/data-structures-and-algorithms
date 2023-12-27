unsigned long long Fattoriale(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else if(n < 0)
	{
		return 0;
	}
	else
	{
		return n * Fattoriale(n - 1);
	}

}
/*
int main()
{
	int num;
	unsigned long long risultato;

	num = 8;
	risultato = Fattoriale(num);

	num = 12;
	risultato = Fattoriale(num);

	num = 20;
	risultato = Fattoriale(num);

	num = 0;
	risultato = Fattoriale(num);

	num = 37;
	risultato = Fattoriale(num);

	return 0;
}
*/