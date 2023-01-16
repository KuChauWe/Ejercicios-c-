#include <iostream>
using namespace std;

int main() {
    int posicion, n1 = 0, n2 = 1, n3;
    cout << "Ingresa la posicion hasta la cual deseas imprimir la serie de Fibonacci: ";
    cin >> posicion;
    cout << "Serie de Fibonacci: " << n1 << " " << n2 << " ";
    for (int i = 2; i < posicion; i++) {
        n3 = n1 + n2;
        cout << n3 << " ";
        n1 = n2;
        n2 = n3;
    }
    return 0;
}