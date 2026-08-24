#include <stdio.h>
#include "matematicas.h"

double valorAbsolutoGet(double);

// Primitivas
bool factorialSet(double* pFactorial, int arg)
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
    *pFactorial = fact;
    
    return true;
}

bool combinatorioSet(double* pComb, int m, int n)
{
    if(n < 0)
    {
        return false;
    }

    if(m<n)
    {
        return false;
    }

    double mFact, nFact, difFact;
    factorialSet(&mFact, m);
    factorialSet(&nFact, n);
    factorialSet(&difFact, m-n);

    *pComb = mFact/(nFact*difFact);
    return true;
}

bool potenciaSet(double* pPot, int base, int exp)
{
    if(exp == 0)
    {
        *pPot = 1;
        return true;
    }

    double pot;
    if(exp > 0)
    {
        pot = base;
        for(int i = 1; i < exp; i++)
        {
            pot *= base;
        }
    }
    else
    {
        if(base == 0)
        {
            return false;
        }
        else
        {
            pot = 1.0/base;
            for(int i = -1; i > exp; i--)
            {
                pot /= base;
            }
        }
    }
    *pPot = pot;
    return true;
}

bool exponencialSet(double* pExp, int entero, float tol)
{
    double exp = 0, fact, pot, term = 1;
    int i = 1;

    if(tol <= 0)
    {
        return false;
    }

    while(valorAbsolutoGet(term) >= tol)
    {
        exp += term;
        if(!potenciaSet(&pot, entero, i))
        {
            return false;
        }
        if(!factorialSet(&fact, i))
        {
            return false;
        }
        i++;
        term = pot/fact;
    }
    *pExp = exp;
    return true;
}

double valorAbsolutoGet(double val)
{
    if(val < 0)
    {
        return -val;
    }

    return val;
}

// No primitivas
void calcularFactorial(double* pFcatorial)
{
    printf("Ingrese argumento para calcular su factorial: ");
    int arg;
    scanf("%d",&arg);
    while(!factorialSet(pFcatorial, arg))
    {
        printf("Error - Argumento de factorial invalido.\n");
        scanf("%d",&arg);
    }
}

void calcularCombinatorio(double* pCombin)
{
    int m, n;
    printf("Ingrese argumento m: ");
    scanf("%d",&m);
    printf("Ingrese argumento n: ");
    scanf("%d",&n);
    while(!combinatorioSet(pCombin,m,n))
    {
        printf("Error - Se han ingresado valores invalidos.\n");
        printf("Ingrese argumento m: ");
        scanf("%d",&m);
        printf("Ingrese argumento n: ");
        scanf("%d",&n);
    }
}

void calcularPotencia(double* pPot)
{
    int base, exp;
    printf("Ingrese base de la potencia:");
    scanf("%d",&base);
    printf("Ingrese exponente de la potencia:");
    scanf("%d",&exp);
    while(!potenciaSet(pPot, base, exp))
    {
        printf("Error - potencia con valores invalidos.\nIngrese base de la potencia:");
        scanf("%d",&base);
        printf("Ingrese exponente de la potencia:");
        scanf("%d",&exp);
    }
}

void calcularExponencial(double* pExp)
{
    int ent;
    float tol;
    printf("Ingrese entero de la serie:");
    scanf("%d",&ent);
    printf("Ingrese tolerancia de la serie:");
    scanf("%f",&tol);
    while(!exponencialSet(pExp, ent, tol))
    {
        printf("Ingrese entero de la serie:");
        scanf("%d",&ent);
        printf("Ingrese tolerancia de la serie:");
        scanf("%f",&tol);
    }
}

void mostrarDouble(const double* pDouble)
{
    printf("%f",*pDouble);
}
