#include <stdio.h>
#include "../Fecha/Fecha.h"

void ingresarEnteroPositivo(int* entero);


int main()
{
    Fecha fecha;

    ingresarFecha(&fecha);

    mostrarFecha(&fecha);
    putchar('\n');

    int dias;

    ingresarEnteroPositivo(&dias);

    Fecha fSuma = fechaSumarDias(&fecha, dias);

    printf("La suma es: ");
    mostrarFecha(&fSuma);
    putchar('\n');

    return 0;
}


void ingresarEnteroPositivo(int* entero)
{
    puts("Ingrese un entero positivo:");
    scanf("%d", entero);

    while(*entero < 1)
    {
        puts("El entero no es positivo. Ingréselo de nuevo:");
        scanf("%d", entero);
    }
}
