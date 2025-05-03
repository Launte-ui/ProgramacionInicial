

#include <stdio.h>

int main()
{
    int horasTrabajadas;
    float pagaPorHora, sueldo;
    printf("Bienvenido al programa\nPorfavor ingrese la cantidad de horas que trabajo (en numeros enteros):\t");
    scanf("%d", & horasTrabajadas);
    printf("\nIngrese cuanto se debe pagar por hora: \t");
    scanf("%f", & pagaPorHora);
    sueldo = horasTrabajadas * pagaPorHora;
    printf("\nEl sueldo del empleado es de $%.2f al dia", sueldo);
    printf("\nFin del programa");
    return 0;
}