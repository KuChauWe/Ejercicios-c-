#include <iostream>
using namespace std;

int main()
{
    printf("\n"
           "Fibonacci (no recursivo) 😾\n"
           "\n");
    int posicion, anterior1 = 0, anterior2 = 1, nuevo;
    cout << "Ingresa la posicion hasta la cual deseas imprimir la serie de Fibonacci: ";
    cin >> posicion;
    cout << "Serie de Fibonacci: " << anterior1 << " " << anterior2 << " ";
    for (int i = 2; i < posicion; i++)
    {
        nuevo = anterior1 + anterior2;
        cout << nuevo << " ";
        anterior1 = anterior2;
        anterior2 = nuevo;
    }
    return 0;
}