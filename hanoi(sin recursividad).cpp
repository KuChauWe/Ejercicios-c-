#include <stdio.h>

#define MAXNUM 10 // Define el máximo de discos
#define START 0   // Inicio de la matriz (0)
#define FINISH 2  //

int isSolved(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] != FINISH)
        {
            return 0;
        }
    }

    return 1;
}

void swap(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

int isOdd(int x)
{
    return ((x % 2) == 1);
}

int main(void)
{
    printf("\n"
           "Torre de Hanoi （；´д｀）ゞ\n"
           "\n");
    int numberOfDisks;
    do
    {
        printf("Número de discos (1 a %d): ", MAXNUM);
        scanf("%d", &numberOfDisks);
    } while ((numberOfDisks < 1) || (numberOfDisks > MAXNUM)); // Recordemos que MAXNUM es ell máximo de discos

    int rod[numberOfDisks];
    for (int i = 0; i < numberOfDisks; ++i)
    {
        rod[i] = START;
    }
    int smallestDir = (isOdd(numberOfDisks)) ? -1 : 1;
    int alternateRodTable[3][2] = {{1, 2}, {0, 2}, {0, 1}};

    printf("\n"
           "Solución:\n"
           "\n");

    int moveCount = 0;
    do
    {
        ++moveCount;

        int disk, rodFrom, rodTo;
        if (isOdd(moveCount))
        {
            // movimiento del disco más pequeño
            disk = 0;
            rodFrom = rod[disk];
            rodTo = rodFrom + smallestDir;
            if (rodTo < START)
            {
                rodTo = FINISH;
            }
            if (rodTo > FINISH)
            {
                rodTo = START;
            }
        }
        else
        {
            // mover disco alternativo
            // determinar cual disco está en la punta de cada varilla
            // establecer un valor predeterminado (varilla vacía) tq sea mayor que el disco más grande
            int topDisk[3] = {numberOfDisks, numberOfDisks, numberOfDisks};
            // poner cada disco en su varilla respectiva
            // los discos pequeños sobrescriben discos más grandes
            for (int i = numberOfDisks - 1; i > -1; --i)
            {
                topDisk[rod[i]] = i;
            }
            // seleccionar las 2 varillas que no tienen al disco más pequeño en el movimiento
            rodFrom = alternateRodTable[rod[0]][0];
            rodTo = alternateRodTable[rod[0]][1];
            // comprobar cuál de los 2 posibles movimientos de varilla a varilla es valido
            if (topDisk[rodFrom] > topDisk[rodTo])
            {
                swap(&rodFrom, &rodTo);
            }
            disk = topDisk[rodFrom];
        }
        rod[disk] = rodTo;

        printf("%4d: Disco %2d Varilla %c => %c\n", moveCount, disk + 1, rodFrom + 'A', rodTo + 'A');
    } while (!isSolved(rod, numberOfDisks));

    return 0;
}