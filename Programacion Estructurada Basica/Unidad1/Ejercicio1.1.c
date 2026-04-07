// 1.1
// Cargar de forma aleatoria un vector de 20 elementos con números de 3 cifras.
// a. Mostrar el menor valor e indicar cuantas veces se repite
// b. Mostrar el mayor valor e indicar en que posición/posiciones se encuentra
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 20

void CargaAleatoria(int [], int, int);
void Mostrar(int [], int);
void BuscarMax(int [], int );
int BuscarMin(int [], int );


int main(){
    int vec[TAM];
    int min;
    srand(time(NULL));
    CargaAleatoria(vec, TAM, 1000); // Carga el vector con números aleatorios entre 0 y 99
    Mostrar(vec, TAM); // Muestra los números aleatorios generados

    min = BuscarMin(vec, TAM);
    printf("El numero minimo es: %d\n", min);

    BuscarMax(vec, TAM);
    return 0;
}

void CargaAleatoria(int v[], int ce, int max){
    for(int i = 0; i < ce; i++)    
        v[i] = rand() % max;
}

void Mostrar(int v[], int ce){
    printf("Id\t| Numero\n");
    for(int i = 0; i < ce; i++)    
        printf("%d\t| %d\n",i+1, v[i]);
}

int BuscarMin(int v[], int ce){
    int min = v[0];
    int repetido = 0;
    for(int i = 1; i < ce; i++){
        if(v[i] < min){
            min = v[i];
            repetido = 1;
        }
        else if(v[i] == min){
            repetido += 1;
        }
    }
    printf("El numero minimo se repite %d veces\n", repetido);
    return min;
}

void BuscarMax(int v[], int ce){
    int max = v[0];
    for(int i = 1; i < ce; i++){
        if(v[i] > max){
            max = v[i];
        }
    }
    printf("El numero maximo es %d y se encuentra en las posiciones: ", max);
    for(int i = 0; i < ce; i++){
        if(v[i] == max){
            printf("%d ", i);
        }
    }
    printf("\n");
}