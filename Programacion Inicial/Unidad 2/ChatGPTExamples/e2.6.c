#include <stdio.h>

int main() {
    double kib, mib, gib, tib;

    // Solicita al usuario el ingreso de un valor en KiB
    printf("Ingrese el valor en Kibibytes (KiB): ");
    scanf("%lf", &kib);

    // Conversión de unidades
    mib = kib / 1024.0;
    gib = mib / 1024.0;
    tib = gib / 1024.0;

    // Impresión de resultados con leyendas
    printf("\nConversión de unidades:\n");
    printf("%.2f KiB equivalen a:\n", kib);
    printf("%.6f MiB (1 MiB = 1024 KiB)\n", mib);
    printf("%.6f GiB (1 GiB = 1024 MiB)\n", gib);
    printf("%.6f TiB (1 TiB = 1024 GiB)\n", tib);

    return 0;
}
