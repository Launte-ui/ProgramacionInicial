// 2.5 
// Se desea desarrollar un sistema de reservas de entradas para un cine. La sala consta de 12 filas numeradas de
// la 1 a la 12 y cada fila tiene 9 butacas numeradas a partir de la columna central, con las butacas impares a la
// derecha y las pares a la izquierda, como en el siguiente esquema:
// 8 6 4 2 1 3 5 7 9
// Para la carga, se debe mostrar al usuario un esquema con las butacas disponibles y reservadas, marcando
// con la letra D las disponibles y con la letra R las reservadas.
// Por cada reserva se debe solicitar la fila y número de butaca a reservar. Cada vez que se realice una
// reserva se deberá actualizar el esquema que muestra las butacas. Si la butaca seleccionada ya estaba
// ocupada se debe informar al usuario para que seleccione otra. El proceso de reserva finaliza con una fila
// con un número negativo.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 12
#define COLUMNAS 9

int main(){
    srand(time(NULL));
    int m[FILAS][COLUMNAS];
    CargaSalaDeCine(m,FILAS,COLUMNAS);
    int f, c,libre=1;
    do{
        libre=1;
        MostrarMatriz(m,FILAS,COLUMNAS);
        do{
            f=NumAleatorio(-1,FILAS);
            if(f!=-1){
                c=NumAleatorio(0,COLUMNAS);
                printf("Se eligio la butaca %d %d\n",f,c);
                if(!m[f][c]){
                    m[f][c]=1;
                    libre = 0;
                }
                else printf("Esa butaca esta ocupada. Elegi otra\n");
            }
            else printf("Bye bye.");
        }while(f>=0&&libre);
    }while(f>=0);
    return 0;
}

void MostrarMatriz(int m[][COLUMNAS], int f, int c){
    printf("   ");
    for(int j = c-1; j >= 0; j--){
        if(j%2!=0)
        printf("%3d",j+1);
    }
    for(int j = 0; j < c; j++){
        if(j%2==0)
        printf("%3d",j+1);
    }
    printf("\n");
    for(int i = 0; i < f; i++){
        printf("%3d",i+1);
        for(int j = c-2; j > 0; j-=2){
                if(!m[i][j])printf("\033[32m  D\033[0m");
                else printf("\033[31m  R\033[0m");
        }
        for(int j = 0; j < c; j+=2){
                if(!m[i][j])printf("\033[32m  D\033[0m");
                else printf("\033[31m  R\033[0m");
        }
        printf("\n");
    }
}

void CargaSalaDeCine(int m[][COLUMNAS], int f, int c){
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            m[i][j] = 0;
        }
    }
}

int NumAleatorio(int min, int max){
    int num = (min + rand() % (max - min));
    return num;
}
