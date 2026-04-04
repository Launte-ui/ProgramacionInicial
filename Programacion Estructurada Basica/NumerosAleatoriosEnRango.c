#include <stdio.h>
#include <time.h>
#define TAM 10

void CargaAleatoria(int [], int, int);
void Mostrar(int [], int);
int main(){
    int vec[TAM];
    srand(time(NULL));
    CargaAleatoria(vec, TAM, 6); // Carga el vector con números aleatorios entre 0 y 99
    Mostrar(vec, TAM); // Muestra los números aleatorios generados

    return 0;

}

void CargaAleatoria(int v[], int ce, int max){
    for(int i = 0; i < ce; i++)    
        v[i] = rand() % max;
}

void Mostrar(int v[], int ce){
    for(int i = 0; i < ce; i++)    
        printf("%d\n", v[i]);
}