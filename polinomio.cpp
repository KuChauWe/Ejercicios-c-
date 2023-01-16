#include <iostream>
using namespace std;

int main()
{
    int grado;
    cout << "Ingresa el grado del polinomio: ";
    cin >> grado;

    int *coeficientes = new int[grado + 1];
    cout << "Ingresa los coeficientes del polinomio: ";
    for (int i = 0; i <= grado; i++)
    {
        cin >> coeficientes[i];
    }

    cout << "La forma general del polinomio ingresado es: ";
    for (int i = grado; i >= 0; i--)
    {
        if (coeficientes[i] == 0)
            continue; // Skip if coefficient is 0
        if (i == grado)
        {
            cout << coeficientes[i] << "x^" << i;
        }
        else if (i == 1)
        {
            if (coeficientes[i] > 0)
            {
                cout << " + " << coeficientes[i] << "x";
            }
            else
            {
                cout << " - " << abs(coeficientes[i]) << "x";
            }
        }
        else if (i == 0)
        {
            if (coeficientes[i] > 0)
            {
                cout << " + " << coeficientes[i];
            }
            else
            {
                cout << " - " << abs(coeficientes[i]);
            }
        }
        else
        {
            if (coeficientes[i] > 0)
            {
                cout << " + " << coeficientes[i] << "x^" << i;
            }
            else
            {
                cout << " - " << abs(coeficientes[i]) << "x^" << i;
            }
        }
    }

    delete[] coeficientes;
    return 0;
}