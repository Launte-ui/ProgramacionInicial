/*Confeccionar un programa que calcule e informe los valores de las potencias de 2 cuyo
resultado sean menores a 6000. (1 2 4 8 16 …).*/

#include <stdio.h>
#include <math.h>

int main()
{
    int pot = 0;
    double expo = 0;
    printf("Los valores de las potencias de 2 menores a 6000 son:\n");
    
    while (pow(2, expo) < 6000)
    {
        pot = pow(2, expo);
        printf("%d\n",pot);
        expo++;
    }
    printf("\nFin del programa");
    return 0;
}
