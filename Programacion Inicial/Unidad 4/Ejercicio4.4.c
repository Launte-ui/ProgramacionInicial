/*Se ingresan 3 números enteros. Informarlos en orden creciente*/

#include <stdio.h>

int main()
{
    int n1, n2, n3;

    printf("Ejercicio 4.4\nIngrese 3 numeros enteros para identificar el mayor\nIngrese el primer numero:\t");
    scanf("%d", & n1);
    printf("Ingrese el segundo numero:\t");
    scanf("%d", & n2);
    printf("Ingrese el tercer numero:\t");
    scanf("%d", & n3);
    if(n1 < n2 && n1 < n3)
    {
        printf("\nEl numero menor es %d", n1);
        if(n2 < n3)
            printf(", seguido de %d y %d",n2, n3);
        else
            printf(", seguido de %d",n3,n2);
    }
    else
    {
        if(n2 < n1 && n2 < n3)
        {
            printf("\nEl numero menor es %d", n2);
            if(n1 < n3)
                printf(", seguido de %d y %d",n1, n3);
            else
                printf(", seguido de %d y %d",n3,n1);
        }
        else
            if(n3 < n1 && n3 < n2)
            {
                printf("\nEl numero menor es %d", n3);
                if(n1 < n2)
                    printf(", seguido de %d y %d",n1, n2);
                else
                    printf(", seguido de %d y %d",n2,n1);
            }
            else
                printf("\nLos numeros son iguales");
    }
    printf("\nFin del programa");
    return 0;
}
