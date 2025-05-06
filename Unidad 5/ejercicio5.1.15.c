/* Confeccionar un programa que permita el ingreso de 6 ternas de valores enteros e informe:
a. De cada terna, informar el mayor valor y su orden en la terna.
b. De cada terna, informar cuantos valores son múltiplos de 7.
c. De las 6 ternas, informar el promedio de los menores valores de cada una.*/

#include <stdio.h>

int main()
{
    int  sumaMenores = 0;
    for (int i = 0; i <= 5; i++)
    {
        int n1, n2, n3, multiplos7 = 0, menor, mayor, mayorPos;
        printf("Ingerese Los distintos numeros de la terna numero %d.\nPrimer Numero: ", i+1);
        scanf("%d",& n1);
        printf("Segundo Numero: ");
        scanf("%d",& n2);
        printf("Tercer Numero: ");
        scanf("%d",& n3);

        mayor = n1;
        mayorPos = 1;
        if(n2>mayor)
        {
            mayor = n2;
            mayorPos = 2;
        }
        if(n3>mayor)
        {
            mayor = n3;
            mayorPos = 3;
        }

        if (n1 % 7 == 0) multiplos7++;
        if (n2 % 7 == 0) multiplos7++;
        if (n3 % 7 == 0) multiplos7++;

        menor = n1;
        if(n2 < menor) menor = n2;
        if(n3 < menor) menor = n3;
        sumaMenores+=menor;

        printf("En la terna %d el numero mayor fue el %d, en la %d° posicion y se encontraron %d multiplos de 7\n\n", i+1, mayor, mayorPos, multiplos7);
    }
    float menoresPromedio;
    menoresPromedio = sumaMenores / 6;
    printf("Promedio de los menores valores de cada terna: %.2f\n", menoresPromedio);
    printf("\nFin del programa");
    return 0;
}
