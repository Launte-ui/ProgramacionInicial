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

    //Salida de error por tolerancia negativa
    if(tol <= 0)
    {
        return false;
    }

    while(valorAbsolutoGet(term) >= tol)
    {
        exp += term;
        //Salidas de error para exponentes
        if(!potenciaSet(&pot, entero, i))
        {
            return false;
        }
        //Salidas de error para factoriales
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

bool fibonacciValidate(int entero)
{
    int anterior = 0, actual = 1, aux;
    while(actual < entero)
    {
        aux = actual;
        actual += anterior;
        anterior = aux;
    }

    if(entero != actual)
    {
        return false;
    }
    
    return true;
}

bool senoTolSet(double* pSeno, int entero, float tol)
{
    int signoTerm = 1, termVal = 1;
    float term=entero;
    double pot, fact, seno = 0;

    if(tol <= 0)
    {
        return false;
    }

    if(!potenciaSet(&pot, entero, termVal))
    {
        return false;
    }
    if(!factorialSet(&fact, termVal))
    {
        return false;
    }
    term = signoTerm * (pot/fact);
    while(valorAbsolutoGet(term) > tol)
    {
        seno += term;

        termVal += 2;
        signoTerm *= -1;

        if(!potenciaSet(&pot, entero, termVal))
        {
            return false;
        }
        if(!factorialSet(&fact, termVal))
        {
            return false;
        }
        term = signoTerm * (pot/fact);
    }

    *pSeno = seno;
    return true;
}

int numeroNaturalPerfectoClasificate(int entero)
{
    int denom = 1, divSuma = 0;

    if(entero <= 0)
    {
        return 0;
    }

    while(denom < entero)
    {
        if(entero%denom == 0)
        {
            divSuma += denom;
        }
        denom++;
    }

    if(divSuma == entero)
    {
        return 1;
    }
    else
    {
        if(divSuma < entero)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
}

int primoValidate(int num)
{
    if(num <= 0)
    {
        return 0;
    }

    int cantDivisores = 0;
    int denom = 1;

    while(denom <= num && cantDivisores <= 2)
    {
        if(num%denom == 0)
        {
            cantDivisores++;
        }
        denom++;
    }

    if(cantDivisores == 2)
    {
        return 1;
    }
    else
    {
        return 2;
    }
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

void aproximarExponencial(double* pExp)
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

void validarFibonacci()
{
    int entero;
    printf("Ingrese un numero entero para verificar que forme parte de la sucesion de Fibonacci: ");
    scanf("%d",&entero);
    if(fibonacciValidate(entero))
    {
        printf("%d forma parte dela sucesion de Fibonacci.",entero);
    }
    else
    {
        printf("%d NO forma parte dela sucesion de Fibonacci.",entero);
    }
}

void mostrarDouble(const double* pDouble)
{
    printf("%f",*pDouble);
}

void aproximarSeno(double* pSeno)
{
    int ent;
    float tol;
    printf("Ingrese entero del seno:");
    scanf("%d",&ent);
    printf("Ingrese tolerancia de la aproximacion:");
    scanf("%f",&tol);
    while(!senoTolSet(pSeno, ent, tol))
    {
        printf("Error inesperado - Revise los valores ingresados.\n");
        printf("Ingrese entero del seno:");
        scanf("%d",&ent);
        printf("Ingrese tolerancia de la aproximacion:");
        scanf("%f",&tol);
    }

}

void clasificarPerfeccionNatural()
{
    int resp, ent;
    char clas[4][15] = {"","Perfecto", "Deficiente", "Abundante"};
    printf("Ingrese numero natural para clasificar: ");
    scanf("%d",&ent);
    resp = numeroNaturalPerfectoClasificate(ent);
    while(!resp)
    {
        printf("Error - Se a ingresado un numero no natural.\n");
        printf("Ingrese numero natural para clasificar: ");
        scanf("%d",&ent);
        resp = numeroNaturalPerfectoClasificate(ent);
    }

    printf("El numero es %s",clas[resp]);
}

void validarPrimo()
{
    int resp, ent;
    char clas[3][9] = {"","Primo", "No primo"};
    printf("Ingrese numero natural para verificar si es primo: ");
    scanf("%d",&ent);
    resp = primoValidate(ent);
    while(!resp)
    {
        printf("Error - Se a ingresado un numero no natural.\n");
        printf("Ingrese numero natural para verificar si es primo: ");
        scanf("%d",&ent);
        resp = primoValidate(ent);
    }

    printf("El numero es %s",clas[resp]);
}
