//Confeccionar un programa que ingrese una medida en ‘pies’ y la exhiba convertida a yardas,
//pulgadas, cms. y mts. 
#include <stdio.h>

int main()
{
    float pies, yardas, pulgadas, cms, mts;
    printf("Bienvenido al programa\nPorfavor ingrese la distancia medida en pies:\t");
    scanf("%f", & pies);
    yardas = pies/3;
    pulgadas = pies * 12;
    cms = pulgadas * 2.54;
    printf("Las medidas se calcularon correctamente.\nA continuacion se muestra la misma medida en las distintas unidades");
    printf("\nYardas: %.2f", yardas);
    printf("\nPulgadas: %.2f", pulgadas);
    printf("\nCentimetros: %.2f", cms);
    printf("\nMetros: %.2f", cms / 100);
    printf("\nFin del programa");
    return 0;
}