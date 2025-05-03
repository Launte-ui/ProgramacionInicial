/*En un depósito de una pinturería existen tarros de pintura. Se sabe que el 50% son tarros de
1 litro, el 30% tarros de 4 litros. y el resto tarros de 20 litros. Ingresando como primer dato la
cantidad de litros de pintura que hay en existencia, determinar la cantidad de tarros de cada
capacidad en litros que hay en stock.*/

#include <stdio.h>

int main()
{
    float pintura, tarros1l, tarros4l, tarros20l;
    printf("Bienvenido al programa\nPorfavor ingrese la cantidad de litros de pintura en existencia:\t");
    scanf("%f", & pintura);
    tarros1l = pintura * 0.5;
    tarros4l = (pintura * 0.3) / 4;
    tarros20l = (pintura * 0.2) / 20;
    printf("Se calcularon la cantidad de tarros de pintura.");
    printf("\nTarros de un litro: %.2f", tarros1l);
    printf("\nTraros de cuatro litros: %.2f", tarros4l);
    printf("\nTarros de veinte litros: %.2f", tarros20l);
    printf("\nFin del programa");
    return 0;
}