/*calcolare la somma dei primi N numeri positivi*/

int sommaFinoA(int num)
{
	if (num == 1)
	{
		return 1;
	}
	return sommaFinoA(num - 1) + num;
}

int main()
{
	int n = 5, ris;
	ris = sommaFinoA(n);
	return 0;
}