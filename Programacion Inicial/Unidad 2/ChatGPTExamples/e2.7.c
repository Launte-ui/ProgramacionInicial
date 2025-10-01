#include <stdio.h>

int main() {
    float precioTurista, precioPrimera;
    int cantidadTurista, cantidadPrimera;
    float totalTurista, totalPrimera, totalRecaudado;

    // Ingreso de datos
    printf("Ingrese el precio del pasaje en clase turista: ");
    scanf("%f", &precioTurista);

    printf("Ingrese la cantidad de pasajes vendidos en clase turista: ");
    scanf("%d", &cantidadTurista);

    printf("Ingrese la cantidad de pasajes vendidos en primera clase: ");
    scanf("%d", &cantidadPrimera);

    // Cálculo del precio en primera clase (30% más caro)
    precioPrimera = precioTurista * 1.30;

    // Cálculo de totales
    totalTurista = precioTurista * cantidadTurista;
    totalPrimera = precioPrimera * cantidadPrimera;
    totalRecaudado = totalTurista + totalPrimera;

    // Resultados
    printf("\nRecaudación total del vuelo:\n");
    printf("Clase turista: %.2f (vendidos: %d)\n", totalTurista, cantidadTurista);
    printf("Primera clase: %.2f (vendidos: %d)\n", totalPrimera, cantidadPrimera);
    printf("Total recaudado: %.2f\n", totalRecaudado);

    return 0;
}
