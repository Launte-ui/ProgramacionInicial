//Confeccionar un programa que pueda ingresar 2 números enteros y calcule e informe con
//mensajes aclaratorios la suma, el producto, el cociente y el resto. 

#include <stdio.h>

int main()
{
    float n1, n2, sum, res, div, mul;
    printf("Bienvenido al programa\nPor favor ingrese el primer numero:\t");
    scanf("%f",& n1);
    printf("\nPor favor ingrese el segundo numero numero:\t");
    scanf("%f",& n2);
    sum = n1 + n2;
    res = n1 - n2;
    mul = n1 * n2;
    div = n1 / n2;
    printf("Los datos se cargaron correctamente.\nA continuacion se muestran los resultados de las distintas operaciones entre estos");
    printf("\nSuma: %.2f", sum);
    printf("\nResta: %.2f", res);
    printf("\nProducto: %.2f", mul);
    printf("\nCociente: %.2f", div);
    printf("\nFin del programa");
    return 0;
}
