// 5.7
// Dada la siguiente estructura:
// typedef struct
// {
// int codigo;
// char descripcion[31];
// float precio;
// }sProductos
// a.
// Crear una variable del tipo sProductos
// b.
// Ingresar por teclado los campos
// c.
// Crear un puntero a dicha estructura
// d.
// Mostrar los datos ingresados mediante el puntero utilizando las dos nomenclaturas posibles
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
int codigo;
char descripcion[31];
float precio;
}sProductos;

int main(){
    sProductos prod;
    sProductos* pProd;
    pProd = &prod;

    printf("Ingrese codigo: ");
    scanf("%d",(int*)pProd);

    printf("Ingrese descripcion: ");
    scanf("%s",(char*)pProd + sizeof(int));

    
    printf("Ingrese precio: ");
    scanf("%f", &pProd->precio);

    printf("Codigo: %d\nDescripcion: %s\nPrecio: %f",pProd->codigo, pProd->descripcion, pProd->precio);
    printf("Codigo: %d\nDescripcion: %s\nPrecio: %f",(*pProd).codigo, (*pProd).descripcion, (*pProd).precio);

    return 0;
}
