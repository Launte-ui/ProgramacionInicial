// 2.3
// Cargar de forma aleatoria una matriz de 5 x 8 con números de 2 cifras. Determinar el máximo valor
// almacenado en la matriz indicando cuantas veces se repite y en que posiciones.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 5
#define COLUMNAS 8

int NumAleatorio();
void CargaAleatoriaMatriz(int[][COLUMNAS],int,int);
void MostrarMatriz(int[][COLUMNAS],int,int);
int MaximoValMatriz(int[][COLUMNAS],int,int);


int main(){
    srand(time(NULL));
    int matriz[FILAS][COLUMNAS];
    int maxNum, repeticion = 0;
    
    CargaAleatoriaMatriz(matriz,FILAS,COLUMNAS);
    MostrarMatriz(matriz,FILAS,COLUMNAS);
    
    maxNum = MaximoValMatriz(matriz,FILAS,COLUMNAS);
    printf("El numero %d aparece en las pociciones:\n",maxNum);
    
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            if(matriz[i][j] == maxNum){
                printf("Fila:%3d, Columna:%3d\n",i+1,j+1);
                repeticion++;
            }
        }
    }
    printf("Un numero de %d veces",repeticion);
    return 0;
}

int NumAleatorio(){
    int num = (10 + rand() % (100 - 10));
    return num;
}

void CargaAleatoriaMatriz(int m[][COLUMNAS], int f, int c){
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            m[i][j] = NumAleatorio();
        }
    }
}
void MostrarMatriz(int m[][COLUMNAS], int f, int c){
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            printf("%3d",m[i][j]);
        }
        printf("\n");
    }
}
int MaximoValMatriz(int m[][COLUMNAS],int f,int c){
    int max = m[0][0];
    for (int i = 0; i < f; i++){
        for (int j = 0; j < c; j++){
            if (max < m[i][j]) max = m[i][j];
        }
    }

    return max;
}