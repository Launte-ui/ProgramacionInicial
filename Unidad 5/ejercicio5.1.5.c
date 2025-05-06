// Ingresar un número entero positivo N y luego ingresar N números naturales. Determinar e
// informar:
// • La sumatoria de los valores múltiplos de 3.
// • La cantidad de valores múltiplos de 5.
// • La sumatoria de los valores que se ingresan en orden par.

#include <stdio.h>

int main()
{
    int sumaM3 = 0, cont = 0, sumaPar = 0, n;
    printf("Ingrese un numero entero positivo:\t");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if(i % 3 == 0)
        
        {
            sumaM3 += i;
        }
        if(i % 5 == 0)
        {
            cont++;
        }
        if(i % 2 == 0)
        {
            sumaPar += i;
        }
    }
    printf("La sumatria de valores multiplos de tres en los primeros %d numeros naturales es: %d", n, sumaM3);
    printf("\nLa cantidad de numeros multiplos de cinco en los primeros %d numeros naturales es: %d", n, cont);
    printf("\nLa sumatria de valores pares en los primeros %d numeros naturales es: %d", n, sumaPar);
    printf("\nFin del programa.");
    
    return 0;
}

