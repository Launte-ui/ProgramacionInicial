#include <stdio.h>

int main() {
    // Mensaje inicial solicitado
    printf("El codigo de este programa fue realizado por ChatGPT con el fin de entender formas mas eficientes de hacer el codigo\n\n");

    int a, b, c, temp;

    // Ingreso de los 3 números
    printf("Ingrese el primer número entero: ");
    scanf("%d", &a);
    printf("Ingrese el segundo número entero: ");
    scanf("%d", &b);
    printf("Ingrese el tercer número entero: ");
    scanf("%d", &c);

    // Ordenamiento simple con intercambios
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }

    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }

    // Resultado en orden creciente
    printf("\nNúmeros en orden creciente: %d, %d, %d\n", a, b, c);

    return 0;
}
