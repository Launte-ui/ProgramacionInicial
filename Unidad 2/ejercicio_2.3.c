//Se ingresan las notas de dos evaluaciones de un alumno. Determinar la nota promedio.

#include <stdio.h>

int main()
{
    float n1, n2, nFinal;
    printf("Bienvenido al programa\nPorfavor ingrese la nota del primer examen:\t");
    scanf("%f", & n1);
    printf("Ingrese la nota del segundo examen: \t");
    scanf("%f", & n2);
    nFinal = (n1 + n2)/2;
    printf("El la nota promedio del alumno es de %.1f", nFinal);
    printf("\nFin del programa");
    return 0;
}