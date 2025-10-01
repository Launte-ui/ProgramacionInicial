// Dados tres números determinar e informar con un mensaje si el primer número ingresado es
// menor que los otros dos.

#include <stdio.h>

int main()
{
    int n1, n2, n3;

    printf("Ejercicio 4.2\nIngrese 3 numeros enteros para identificar si el primero es el mayor\nIngrese el primer numero:\t");
    scanf("%d", & n1);
    printf("Ingrese el segundo numero:\t");
    scanf("%d", & n2);
    printf("Ingrese el tercer numero:\t");
    scanf("%d", & n3);
    if(n1 > n2 && n1 > n3)
        printf("\nEl primer numero (%d) es mayor que los otros dos (%d y %d)", n1,n2,n3);
    else
        printf("\nEl primer numero (%d) no es mayor que los otros dos (%d y %d)", n1,n2,n3);

    printf("\nFin del programa");
    return 0;
}
