//Se ingresan 3 números enteros distintos. Determinar el mayor
#include <stdio.h>

int main()
{
    float n1, n2, n3;

    printf("Ejercicio 4.4\nIngrese 3 numeros para identificar el mayor\nIngrese el primer numero:\t");
    scanf("%f", & n1);
    printf("\nIngrese el segundo numero:\t");
    scanf("%f", & n2);
    printf("\nIngrese el tercer numero:\t");
    scanf("%f", & n3);
    if(n1 > n2 && n1 > n3)
        printf("\nEl numero mas grande es %.2f", n1);
    else
        if(n2 > n1 && n2 > n3)
            printf("\nEl numero mas grande es %.2f", n2);
        else
            printf("\nEl numero mas grande es %.2f", n3);
    return 0;
}
