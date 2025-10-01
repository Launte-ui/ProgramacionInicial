/*Confeccionar un programa que pueda determinar de 3 números enteros que se ingresan si
alguno de ellos es igual a la suma de los otros dos.*/

#include <stdio.h>

int main()
{
    int n1, n2, n3;

    printf("Ejercicio 4.3.\nIngrese 3 numeros enteros para identificar si el primero es el mayor.\nIngrese el primer numero:\t");
    scanf("%d", & n1);
    printf("Ingrese el segundo numero:\t");
    scanf("%d", & n2);
    printf("Ingrese el tercer numero:\t");
    scanf("%d", & n3);
    if(n1 == n2 + n3)
        printf("\nEl primer numero (%d) es igual que la suma de los otros dos (%d y %d).", n1,n2,n3);
    else
    {
        if(n2 == n1 + n3)
            printf("\nEl segundo numero (%d) es igual que la suma de los otros dos (%d y %d).", n2,n1,n3);
        else
        {
            if(n3 == n1 + n2)
                printf("\nEl tercer numero (%d) es igual que la suma de los otros dos (%d y %d).", n3,n1,n2);
            else
                printf("\nNingun numero es igual a la suma de los otros dos.");
        }
    }
    printf("\nFin del programa");
    return 0;
}
