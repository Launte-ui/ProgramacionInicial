/*Una empresa de aviación vende pasajes en clase turista y en primera clase, cuyo costo es un
30% más caro que clase turista. Se pide al usuario ingresar el importe de cada pasaje de clase
turista, la cantidad de pasajes vendidos de clase turista y la cantidad vendida de primera clase.
informar la recaudación total del vuelo.*/

#include <stdio.h>

int main()
{
    float importe, turistas, pClase, total;
    printf("Bienvenido al programa\nEste programa calcula el importe total en la venta de pasajes."
    "\nPorfavor ingrese el importe a pagar para un pasaje en clase turista:\t");
    scanf("%f", &importe);
    printf("Ingrese la cantidad de pasajes de clase turistas vendidos:\t");
    scanf("%f", &turistas);
    printf("Ingrese la cantidad de pasajes de primera clase vendidos:\t");
    scanf("%f", &pClase);
    total += importe * turistas;
    total += (importe + importe * 0.3) * pClase;
    printf("El importe total percibido es de: $%.2f", total);
    printf("\nPrograma finalizado");
    return 0;
}
