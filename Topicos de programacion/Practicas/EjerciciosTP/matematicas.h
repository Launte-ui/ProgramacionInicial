#ifndef MATEMATICAS_H_INCLUDED
#define MATEMATICAS_H_INCLUDED

#include <stdbool.h>

// Primitivas
bool factorialSet(double* n, int arg);
void factorialGet(const double* f);

// No primitivas
void calcularFactorial(double* n);
void mostrarFactorial(double* n);

#endif // MATEMATICAS_H_INCLUDED