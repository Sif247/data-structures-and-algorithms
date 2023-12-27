/*fai il fattoriale in modalità tail*/
			

//MODALITA "NON TAIL"
/*
int fatt(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return fatt(n - 1) * n;
	}
}			|
			|     TRASFORMAZIONE
			|		   TAIL
			|
		   \ /  
*/

//MODALITA TAIL
int fatt(int n, int ris)
{
	if (n == 1)
	{
		return ris;
	}
	else
	{
		return fatt(n - 1,ris * n);
	}
}

/*
		 |
		 |     TRASFORMAZIONE
		 |       ITERATIVA
		 |
		\ /
		


//MODALITA ITERATIVA

int fatt(int n)
{
	int risFinale = 1;
	for (int i = 1; i <= n; i++)
	{
		risFinale *= i;
	}
	return risFinale;
}	

*/

int main()
{
	int ris;
	int appoggio = 1;
	ris = fatt(4, appoggio);
	ris = fatt(8, appoggio);
	ris = fatt(10,appoggio);
	ris = fatt(3, appoggio);
	ris = fatt(5, appoggio);

	return 0;
}