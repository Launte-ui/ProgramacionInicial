#include <stdio.h>

int main()
{
    printf("Programacion Inicial, Unidad 2, Ejercicio 2.2\n");
    int horasTrabajadas;
    float suledoPorHora;
    printf("Bienvenido al programa\nPorfavor ingrese el cuantas hora trabajo (Numero enetro):\t");
    scanf("%d", &horasTrabajadas);
    printf("Ingerese el valor de una hora de trabajo:\t");
    scanf("%f", &suledoPorHora);
    printf("El sueldo a cobrar es de $%f", suledoPorHora * horasTrabajadas);
    return 0;
}
