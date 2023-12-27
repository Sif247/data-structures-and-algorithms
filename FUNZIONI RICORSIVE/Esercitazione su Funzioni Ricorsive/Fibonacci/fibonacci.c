int Fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n < 0)
	{
		return -1;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
	
}
/*
int main()
{
	int ris;
	ris = Fibonacci(5);
	ris = Fibonacci(8);
	ris = Fibonacci(7);
	ris = Fibonacci(-7);
	ris = Fibonacci(24);
	return 0;
}
*/