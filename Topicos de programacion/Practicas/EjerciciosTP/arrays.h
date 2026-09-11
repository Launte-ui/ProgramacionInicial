#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

#define INVALIDPOS(pos,size) ( \
    ((pos) >= (size)) || \
    ((pos) < (0)) \
)
#define ARRAYOVERFLOW(ce,size) ((ce)>=(size))
#define INVALIDINSERTNGPOS(pos,ce) ((pos)>(ce))
#define INVALIDEXISTINGPOS(pos,ce) ((pos)>=(ce))

#include <stdbool.h>

typedef struct{
    int ce;
    int size;
    int* dir;
}Array;

// Primitivas

bool SetArray(Array* array, int size);
void EliminarArray(Array* array);
bool InsertarNumEnPos(Array* array, int num, int pos);
void IniciarArrEnCero(Array* array);
void OrdenAscendenteArr(Array* array);
bool InsertarNumEnOrdenA(Array* array, int num);
bool EliminarNumEnPos(Array* array, int pos);
bool EliminarTodoNum(Array* array, int num);

// No Primitivas

void CrearArray(Array* array);
void CrearArrayPredeterminado(Array* array);
void MostrarArray(Array* array);
void SaltoDeLinea();
void MeteXAca(Array* array);
void MeteXAcaOrdenadito(Array* array);
void SacameloDeAca(Array* array);
void SacameATodosDeAca(Array* array);

#endif // ARRAYS_H_INCLUDED