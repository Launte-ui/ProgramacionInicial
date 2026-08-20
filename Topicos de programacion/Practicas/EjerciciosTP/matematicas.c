#include <stdio.h>
#include "matematicas.h"

// Primitivas
bool factorialSet(double* n, int arg)
{
    if(arg < 0)
    {
        return false;
    }
    else
    {
        if(arg == 0)
        {
            *n = 1;
        }
        else
        {
            double fact = 1;
            for(int i = 1; i <= arg; i++)
            {
                fact *= i;
            }
            *n = fact;
        }
        return true;
    }
}
void factorialGet(const double* f);

// No primitivas
void calcularFactorial(double* n){
    printf("Ingrese argumento para calcular su factorial:");
    int arg;
    scanf("%d",&arg);
    factorialSet(n, arg);
}
void mostrarFactorial(double* n)
{
    printf("%f",*n);
}
