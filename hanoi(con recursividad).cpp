#include <iostream>
using namespace std;

void hanoi(int n, char origen, char destino, char auxiliar)
{
    if (n == 0)
        return;
    if (n == 1)
    {
        cout << "Mover disco 1 desde " << origen << " hasta " << destino << endl;
        return;
    }
    hanoi(n - 1, origen, auxiliar, destino);
    cout << "Mover disco " << n << " desde " << origen << " hasta " << destino << endl;
    hanoi(n - 1, auxiliar, destino, origen);
}

int main()
{
    printf("\n"
           "Torre de Hanoi (recursivo) 😾\n"
           "\n");
    int n;
    cout << "Ingrese el numero de discos: ";
    cin >> n;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}