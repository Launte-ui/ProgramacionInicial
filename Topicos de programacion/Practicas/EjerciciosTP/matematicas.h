#ifndef MATEMATICAS_H_INCLUDED
#define MATEMATICAS_H_INCLUDED

#include <stdbool.h>

// Primitivas
bool factorialSet(double* n, int arg);
bool combinatorioSet(double* c, int m, int n);

// No primitivas
void calcularFactorial(double* n);
void mostrarFactorial(const double* n);
void calcularCombinatorio(double* c);
void mostrarCombinatorio(const double* c);

#endif // MATEMATICAS_H_INCLUDED