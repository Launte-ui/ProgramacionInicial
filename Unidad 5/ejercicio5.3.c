// Se ingresan 50 números enteros. Determinar el promedio de los números pares

#include <stdio.h>

int main()
{
    printf("El siguiente programa muestra el promedio de numeros pares entre 50 numeros enteros");
    int suma = 0, cont = 0, promedio;
    for (int i = 0; i <= 50; i++)
    {
        if(i % 2 == 0)
        {
            suma += i;
            cont++;
        }
    }
    promedio = suma / cont;
    printf("\nEl promedio de numeros pares es %d", promedio);
    printf("\nFin del programa.");
    
    return 0;
}
