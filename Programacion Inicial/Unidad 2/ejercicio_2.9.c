/* Una farmacia vende algunos artículos sin descuento y a otros con descuento del 20%.
Confeccionar un programa que recibiendo el precio original y un código que indica si es o no
con descuento, informe el precio final (0 no aplica el descuento y 1 aplica el descuento).*/
#include <stdio.h>

int main()
{
    float precioOriginal, precioFinal;
    int op;
    printf("Ingrese el precio original del producto a vender\n");
    scanf("%f", &precioOriginal);
    printf("¿Aplica el descuento en el prducto?(1 para si, 0 para no)\n");
    scanf("%d", &op);
    precioFinal = precioOriginal + (precioOriginal*0.2*op);
    printf("El precio final de su venta es de $%.2f",precioFinal);
    printf("\nFin del programa");
    return 0;
}
