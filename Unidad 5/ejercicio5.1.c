// Mostrar por pantalla los números pares comprendidos entre 100 y 500.


#include <stdio.h>

int main()
{
    printf("El siguiente programa muestra los numeros pares comprendidos entre 100 y 500");
    for (int i = 100; i <= 500; i++)
    {
        if(i % 2 == 0)
            printf("\n%d es un numero par", i);
    }
    printf("\nFin del programa.");
    return 0;
}
