#ifndef MATEMATICAS_H_INCLUDED
#define MATEMATICAS_H_INCLUDED

#include <stdbool.h>

// Primitivas
bool factorialSet(double* pFactorial, int arg);
bool combinatorioSet(double* pComb, int m, int n);
bool potenciaSet(double* pPot, int base, int exp);
bool exponencialSet(double* pExp, int entero, float tol);

// No primitivas
void calcularFactorial(double* pFcatorial);
void calcularCombinatorio(double* pCombin);
void calcularPotencia(double* pPot);
void calcularExponencial(double* pExp);
void mostrarDouble(const double* pDouble);

#endif // MATEMATICAS_H_INCLUDED