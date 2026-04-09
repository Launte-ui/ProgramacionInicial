// 2.2
// Ingresar una matriz de 5x4 por teclado. Realizar una función que genere un vector con la suma por
// fila de dicha matriz y otra función que calcule la suma por columna en otro vector.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int matriz[5][4];
    CargaAleatoriaMatriz(matriz,5,4);
    MostrarMatriz(matriz,5,4);

    printf("\nVector hecho por filas de matriz:\n");
    CrearVectorPorFilasMatriz(matriz,5,4);
    printf("\nVector hecho por columnas de matriz:\n");
    CrearVectorPorColumnasMatriz(matriz,5,4);

    return 0;
}


int NumAleatorio(){
    int num = rand() % 11;
    return num;
}

void CargaAleatoriaMatriz(int m[][4], int f, int c){
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            m[i][j] = NumAleatorio();
        }
    }
}
void MostrarMatriz(int m[][4], int f, int c){
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            printf("%3d",m[i][j]);
        }
        printf("\n");
    }
}

void CrearVectorPorFilasMatriz(int m[][4], int f, int c){
    int v[f];
    for(int i = 0; i < f; i++){
        int fila = 0;
        for(int j = 0; j < c; j++){
            fila += m[i][j];
        }
        v[i] = fila;
    }
    MostrarVector(v,f);
}
void CrearVectorPorColumnasMatriz(int m[][4], int f, int c){
    int v[c];
    for(int i = 0; i < c; i++){
        int col = 0;
        for(int j = 0; j < f; j++){
            col += m[j][i];
        }
        v[i] = col;
    }
    MostrarVector(v,c);
}
void IniciarVecEnCero(int v[], int ce){
    for (int i = 0; i < ce; i++){
        v[i] = 0;
    }
}
void MostrarVector(int v[], int ce){
    for(int i = 0; i < ce; i++){
        printf("%3d",v[i]);
    }
    printf("\n");
}