//Se ingresan 3 números enteros distintos. Determinar el mayor.

#include <stdio.h>

int main()
{
    int n1, n2, n3;

    printf("Ejercicio 4.1\nIngrese 3 numeros enteros para identificar el mayor\nIngrese el primer numero:\t");
    scanf("%d", & n1);
    printf("Ingrese el segundo numero:\t");
    scanf("%d", & n2);
    printf("Ingrese el tercer numero:\t");
    scanf("%d", & n3);
    if(n1 > n2 && n1 > n3)
        printf("\nEl numero mas grande es %d", n1);
    else
        if(n2 > n1 && n2 > n3)
            printf("\nEl numero mas grande es %d", n2);
        else
            printf("\nEl numero mas grande es %d", n3);
    printf("\nFin del programa");
    return 0;
}
