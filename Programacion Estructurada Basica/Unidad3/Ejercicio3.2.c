// 3.2
// Ingresar dos Strings, uno con el nombre y el otro con el apellido de una persona.
// Utilizando las funciones de la biblioteca string.h generar un tercer string formado por:
// NOMBRE, APELLIDO (nombre coma espacio y apellido) y mostrarlo

#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
    srand(time(NULL));
    char nombre[21];
    char apellido[21];
    char nCompleto[41];

    printf("Ingrese su nombre: ");
    scanf("%s",nombre);
    getchar();
    
    printf("Ingrese su apellido: ");
    scanf("%s",apellido);
    getchar();
    
    strcpy(nCompleto,nombre);
    strcat(nCompleto, ", ");
    strcat(nCompleto, apellido);
    printf("\nSu nombre es: %s",nombre);
    printf("\nSu apellido es: %s",apellido);
    printf("\nSu nombre completo es: %s",nCompleto);

    return 0;
}