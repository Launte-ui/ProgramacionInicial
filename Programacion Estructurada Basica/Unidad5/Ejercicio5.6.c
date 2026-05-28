// 5.6
// Cargar un vector de enteros con números aleatorios de 3 cifras máximo.
// Realizar una función que retorne un puntero al mayor valor del vector
// Mostrar el máximo valor mediante el puntero y la posición en la cual se encuentra
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MostrarVector(int[], int);
void CargaVector(int[], int);
int* BuscarMax(int*, int);
int NumAleatorio(int, int);

int main(){
    srand(time(NULL));
    int vec[10];

    CargaVector(vec,10);
    MostrarVector(vec,10);

    printf("El maximo valor encontrado es %d y se encontro en la posicion %d del vector.", *BuscarMax(vec,10),BuscarMax(vec,10) - vec);

    return 0;
}

void CargaVector(int v[], int ce){
    for(int i = 0; i < ce; i++){
        *(v+i) = NumAleatorio(0, 1000);
    }
}

void MostrarVector(int v[], int ce){
    for(int i = 0; i < ce; i++){
        printf("%d| %03d\n",i,*(v+i));
    }
}

int* BuscarMax(int *v, int ce){
    int* dir = v, i = 1;
    while(i < ce){
        if(*(v+i) > *dir)
            dir = v+i;
        i++;
    }
    return dir;
}

int NumAleatorio( int min,int max){
    int num = min + (rand() % (max - min));
    return num;
}