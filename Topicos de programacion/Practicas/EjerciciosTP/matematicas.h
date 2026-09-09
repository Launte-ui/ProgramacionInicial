#ifndef MATEMATICAS_H_INCLUDED
#define MATEMATICAS_H_INCLUDED

#include <stdbool.h>

// Primitivas
bool factorialSet(double* pFactorial, int arg);
bool combinatorioSet(double* pComb, int m, int n);
bool potenciaSet(double* pPot, int base, int exp);
bool exponencialSet(double* pExp, int entero, float tol);
bool fibonacciValidate(int entero);
bool senoTolSet(double* pSeno, int entero, float tol);
int numeroNaturalPerfectoClasificate(int num);
int primoValidate(int num);

// No primitivas
void calcularFactorial(double* pFcatorial);
void calcularCombinatorio(double* pCombin);
void calcularPotencia(double* pPot);
void aproximarExponencial(double* pExp);
void validarFibonacci();
void mostrarDouble(const double* pDouble);
void aproximarSeno(double* pSeno);
void clasificarPerfeccionNatural();
void validarPrimo();

#endif // MATEMATICAS_H_INCLUDED