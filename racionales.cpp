#include <iostream>
using namespace std;

struct Racional
{
    int numerador;
    int denominador;
};

Racional ingresarRacional()
{
    Racional r;
    cout << "Ingrese el numerador: ";
    cin >> r.numerador;
    do
    {
        cout << "Ingrese el denominador (no puede ser cero): ";
        cin >> r.denominador;
    } while (r.denominador == 0);
    return r;
}

Racional sumarRacionales(Racional r1, Racional r2)
{
    Racional resultado;
    resultado.numerador = (r1.numerador * r2.denominador) + (r1.denominador * r2.numerador);
    resultado.denominador = r1.denominador * r2.denominador;
    return resultado;
}

Racional multiplicarRacionales(Racional r1, Racional r2)
{
    Racional resultado;
    resultado.numerador = r1.numerador * r2.numerador;
    resultado.denominador = r1.denominador * r2.denominador;
    return resultado;
}

int main()
{
    Racional r1 = ingresarRacional();
    Racional r2 = ingresarRacional();
    Racional suma = sumarRacionales(r1, r2);
    Racional multiplicacion = multiplicarRacionales(r1, r2);
    cout << "Suma: " << suma.numerador << "/" << suma.denominador << endl;
    cout << "Multiplicacion: " << multiplicacion.numerador << "/" << multiplicacion.denominador << endl;
    return 0;
}