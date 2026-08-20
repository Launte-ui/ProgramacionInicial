#include <stdio.h>
#include "matematicas.h"

// Primitivas
bool factorialSet(double* n, int arg)
{
    if(arg < 0)
    {
        return false;
    }

    double fact = 1;
    for(int i = 1; i <= arg; i++)
    {
        fact *= i;
    }
    *n = fact;
    
    return true;
}

// No primitivas
void calcularFactorial(double* n)
{
    printf("Ingrese argumento para calcular su factorial:");
    int arg;
    scanf("%d",&arg);
    if(!factorialSet(n, arg))
    {
        //En caso de error se devuelve -1 como valor inválido.
        //No existe factorial de un numero que sea negativo.
        printf("Error - Argumento de factorial negativo.\n");
        *n = -1;
    }
}

void mostrarFactorial(const double* n)
{
    printf("%.0f",*n);
}
