#include <iostream>
using namespace std;

int fibonacci(int posicion) {
    if (posicion == 0) {
        return 0;
    } else if (posicion == 1) {
        return 1;
    } else {
        return fibonacci(posicion - 1) + fibonacci(posicion - 2);
    }
}

int main() {
    int posicion;
    cout << "Ingresa la posicion hasta la cual deseas imprimir la serie de Fibonacci: ";
    cin >> posicion;
    cout << "Serie de Fibonacci: ";
    for (int i = 0; i < posicion; i++) {
        cout << fibonacci(i) << " ";
    }
    return 0;
}