/*Confeccionar un programa que ingrese un valor expresado en Kibibyte (KiB)
y lo informeexpresado en: TiB, GiB, MiB, con leyendas aclaratorias. 
(1MiB = 1024 KiB; 1GiB = 1024 MiB; 1TiB = 1024 GiB).*/

#include <stdio.h>

int main()
{
    float kib, mib, gib, tib;
    printf("Bienvenido al programa\nEste programa realiza un pasaje entre unidades de bytes.\nRecuerde que:\n1MebiByte = 1024 KibiByte\n1GibiByte = 1024 MebiByte\n1TebiByte = 1024 GibiByte\nPorfavor ingrese un valor de Kibibyte:\t");
    scanf("%f", &kib);
    mib = kib / 1024;
    gib = mib / 1024;
    tib = gib / 1024;
    printf("El valorde kibibyte ingresado equivale a:");
    printf("\n%.2f Mebibytes:", mib);
    printf("\n%.2f Gibibytes:", gib);
    printf("\n%.2f Teribytes:", tib);
    printf("\nPrograma finalizado");
    return 0;
}
