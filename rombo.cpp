#include <iostream>

using namespace std;

void romboA(char inicio, char final);
void romboB(char inicio, char final);
void inLetras();

int main()
{
	printf("\n"
		   "Rombo 😾\n"
		   "\n");
	inLetras();

	return 0;
}

void inLetras()
{
	char inicio, final;
	int x, y;

	do
	{
		cout << "Ingresa la letra de inicio del rombo (Mayúsculas): ";
		cin >> inicio;
		cout << "Ingresa la letra intermedia del rombo (Mayúsculas): ";
		cin >> final;
		x = inicio;
		y = final;
	} while ((x > y) || (x < 65) || (y > 90));

	romboA(inicio, final);
	romboB(inicio, final);
}

void romboA(char inicio, char final)
{
	char aux;
	int a = inicio, b = final;
	int i, j, k, p = 0, q = (b - a), r = 1;

	for (i = a; i <= b; i++)
	{
		aux = a + p;

		for (k = q; k >= 0; k--)
		{
			cout << " ";
		}
		if (p == 0)
		{
			cout << aux;
		}
		else
		{
			for (j = 1; j <= r; j++)
			{
				cout << aux;
			}
		}
		q -= 1;
		p += 1;
		r += 2;
		cout << endl;
	}
}

void romboB(char inicio, char final)
{
	char aux;
	int a = inicio, b = final - 1;
	int i, j, k, p = (b - a), q = 0, r;

	for (i = b; i >= a; i--)
	{
		aux = a + p;

		for (k = 0; k <= q + 1; k++)
		{
			cout << " ";
		}
		if (p == 0)
		{
			cout << aux;
		}
		else
		{
			for (j = 5; j <= r; j++)
			{
				cout << aux;
			}
		}
		q += 1;
		p -= 1;
		r -= 2;
		cout << endl;
	}
}