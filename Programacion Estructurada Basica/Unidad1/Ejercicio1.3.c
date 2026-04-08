//1.3
// En un curso de la maestría en informática los estudiantes deben exponer en forma grupal sus investigaciones de un tema dado.
//  El curso está formado por 5 grupos. Se pide realizar un programa para sortear el orden de exposición de dichos grupos.
//  Cada vez que se ejecute el programa deberá mostrar un orden de exposición distinto para cada uno de los 5 grupos.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANT_GRUPOS 5

void IniciarGrupos(int [], int);
int NumAleatorio(int, int);
void MostrarVector(int[], int);


int main()
{
    srand(time(NULL));
    int grupos[CANT_GRUPOS];
    IniciarGrupos(grupos, CANT_GRUPOS);

    for(int i = 0; i < CANT_GRUPOS; i++){
        int posAleatoria = NumAleatorio(i, CANT_GRUPOS);
        int aux = grupos[i];
        grupos[i] = grupos[posAleatoria];
        grupos[posAleatoria] = aux;
    }

    printf("Orden de exposición de los grupos:\n");
    MostrarVector(grupos, CANT_GRUPOS);

    return 0;
}

void IniciarGrupos(int v[], int ce){
    for(int i = 0; i < ce; i++){
        v[i] = i+1;
    }
}

void MostrarVector(int v[], int ce){
    for (int i = 0; i < ce; i++) {
        printf("Grupo %d\n", v[i]);
    }
}

int NumAleatorio( int min,int max){
    int num = min + (rand() % (max - min));
    return num;
}