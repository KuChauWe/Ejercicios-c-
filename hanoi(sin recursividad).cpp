#include <stdio.h>

#define numMax 10 // Define el máximo de discos
#define inicio 0  // Inicio de la matriz (0)
#define final 2   //

int solucion(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] != final)
        {
            return 0;
        }
    }

    return 1;
}

void intercambio(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

int imp(int x)
{
    return ((x % 2) == 1);
}

int main(void)
{
    printf("\n"
           "Torre de Hanoi (no recursivo) 😾\n"
           "\n");
    int cantDiscos;
    do
    {
        printf("Número de discos (1 a %d): ", numMax);
        scanf("%d", &cantDiscos);
    } while ((cantDiscos < 1) || (cantDiscos > numMax)); // Recordemos que numMax es el máximo de discos

    int varilla[cantDiscos];
    for (int i = 0; i < cantDiscos; ++i)
    {
        varilla[i] = inicio;
    }
    int discoPeque = (imp(cantDiscos)) ? -1 : 1;
    int tabVarillasAlt[3][2] = {{1, 2}, {0, 2}, {0, 1}}; // Editar esto

    printf("\n"
           "Solución:\n"
           "\n");

    int contMovimientos = 0;
    do
    {
        ++contMovimientos;

        int disco, origen, destino;
        if (imp(contMovimientos))
        {
            // movimiento del disco más pequeño
            disco = 0;
            origen = varilla[disco];
            destino = origen + discoPeque;
            if (destino < inicio)
            {
                destino = final;
            }
            if (destino > final)
            {
                destino = inicio;
            }
        }
        else
        {
            // mover disco alternativo
            // determinar cual disco está en la punta de cada varilla
            // establecer un valor predeterminado (varilla vacía) tq sea mayor que el disco más grande
            int discoSup[3] = {cantDiscos, cantDiscos, cantDiscos};
            // poner cada disco en su varilla respectiva
            // los discos pequeños sobrescriben discos más grandes
            for (int i = cantDiscos - 1; i > -1; --i)
            {
                discoSup[varilla[i]] = i;
            }
            // seleccionar las 2 varillas que no tienen al disco más pequeño en el movimiento
            origen = tabVarillasAlt[varilla[0]][0];
            destino = tabVarillasAlt[varilla[0]][1];
            // comprobar cuál de los 2 posibles movimientos de varilla a varilla es valido
            if (discoSup[origen] > discoSup[destino])
            {
                intercambio(&origen, &destino);
            }
            disco = discoSup[origen];
        }
        varilla[disco] = destino;

        printf("%4d: Disco%2d desde %c hasta %c\n", contMovimientos, disco + 1, origen + 'A', destino + 'A');
    } while (!solucion(varilla, cantDiscos));

    return 0;
}