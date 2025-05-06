// Confeccionar un programa para calcular el valor de la siguiente suma: 100 + 95 + 90 + ... + 50



#include <stdio.h>

int main()
{
    printf("El siguiente programa muestra el resultado de la siguiente suma: 100 + 95 + 90 + ... + 50");
    int suma = 0;
    for (int i = 100; i > 50; i -= 5)
        suma += i;
    printf("\nEl resultado es %d", suma);
    printf("\nFin del programa.");
    
    return 0;
}
