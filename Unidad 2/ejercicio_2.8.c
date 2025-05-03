/* Una pizzería vende empanadas por unidad o por docena. Como primer paso, se pide al usuario
que ingrese el precio por docena y el precio por unidad del día. Si se compran empanadas que
no se agrupen en docenas, las adicionales se cobran por unidad. Indicar el precio total a
abonar, ingresando la cantidad de empanadas vendidas.*/
#include <stdio.h>

int main()
{
    float precioU, precioD, precioT;
    int empanadasPedidas, empanadasU, empanadasD;
    printf("Ingrese el precio de la unidad de empanadas\n");
    scanf("%f", &precioU);
    printf("Ingrese el precio de la docena de empanadas\n");
    scanf("%f", &precioD);
    printf("Ingrese la cantidad de empanadas a vender\n");
    scanf("%d", &empanadasPedidas);
    empanadasU = empanadasPedidas % 12;
    empanadasD = empanadasPedidas / 12;
    precioT = precioU * empanadasU + precioD * empanadasD;
    printf("El precio final de su venta es de %.2f",precioT);
    return 0;
}
