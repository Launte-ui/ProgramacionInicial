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
// Al finalizar mostrar:
// a. la cantidad de asientos disponibles y la cantidad de asientos reservados.
// b. los números de filas que quedaron vacías.
// c. la o las filas con mayor cantidad de espectadores.
// d. un listado con la cantidad de personas que se sentaron en los mismos números de butacas en
// todo el cine ordenado de mayor a menor. Por ejemplo:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 12
#define COLUMNAS 9

int main(){
    srand(time(NULL));
    int m[FILAS][COLUMNAS];
    int vFilas[FILAS], vColumnas[COLUMNAS], vParaleloPos[COLUMNAS]={0,1,2,3,4,5,6,7,8};
    int cantReservados = 0, cantDisponibles;
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
    for(int i = 0; i < FILAS; i++){
        for (int j = 0; j < COLUMNAS; j++){
            cantReservados += m[i][j];
        }
    }
    cantDisponibles = FILAS*COLUMNAS-cantReservados;
    printf("\nLa sala de cine cuenta con %d asientos libres y %d ocupados",cantDisponibles,cantReservados);
    LlenarVectorPorFilas(m, FILAS, COLUMNAS, vFilas);
    
    if(BusquedaSecuencial(vFilas,0,FILAS)>=0){
        printf("\nEl numero de las filas vacias son:");
        for(int i = 0; i < FILAS; i++) if(vFilas[i]==0)printf("%3d",i+1);
    }
    else printf("\nNo hay filas vacias");

    LlenarVectorPorColumnas(m, FILAS, COLUMNAS, vColumnas);
    OrdenarMayorMenosParalelos(vColumnas, vParaleloPos, COLUMNAS);
    MostrarVector(vParaleloPos, COLUMNAS);
    MostrarVector(vColumnas, COLUMNAS);
    return 0;
}

void LlenarVectorPorFilas(int m[][COLUMNAS], int f, int c, int v[]){
    for(int i = 0; i < f; i++){
        int filaSum = 0;
        for (int j = 0; j < c; j++){
            filaSum += m[i][j];
        }
        v[i]= filaSum;
    }
}

void LlenarVectorPorColumnas(int m[][COLUMNAS], int f, int c, int v[]){
    for(int i = 0; i < c; i++){
        int colSuma = 0;
        for (int j = 0; j < f; j++){
            colSuma += m[j][i];
        }
        v[i]= colSuma;
    }
}

void MostrarMatriz(int m[][COLUMNAS], int f, int c){
    printf("\033[47;30m   ");
    for(int j = c-1; j >= 0; j--){
        if(j%2!=0)
        printf("%3d",j+1);
    }
    for(int j = 0; j < c; j++){
        if(j%2==0)
        printf("%3d",j+1);
    }
    printf("\033[40;0m\n");
    for(int i = 0; i < f; i++){
        printf("\033[47;30m%3d\033[40;0m",i+1);
        for(int j = c-2; j > 0; j-=2){
                if(!m[i][j])printf("\033[40;32m  D\033[40;0m");
                else printf("\033[40;31m  R\033[40;0m");
        }
        for(int j = 0; j < c; j+=2){
                if(!m[i][j])printf("\033[40;32m  D\033[40;0m");
                else printf("\033[40;31m  R\033[40;0m");
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

void MostrarVector(int v[], int ce){
    printf("\n");
    for(int i = 0; i < ce; i++){
        printf("%3d",v[i]);
    }
}

int BusquedaSecuencial(int v[], int elemento, int ce){
    int pos = -1, i = 0;
    while(i<ce && pos == -1){
        if(v[i]==elemento)pos=i;
        i++;
    }

    return pos;
}

void OrdenarMayorMenosParalelos(int v[], int vp[], int ce){
    int maxP, aux;
    for(int i = 0; i < ce; i++){
        maxP = PosMaximo(v, ce, i);
        aux = v[maxP];
        v[maxP] = v[i];
        v[i] = aux;

        aux = vp[maxP];
        vp[maxP] = vp[i];
        vp[i] = aux;
    }
}

int PosMaximo(int v[], int ce, int ini){
    int pos = ini;
    for(int i = ini + 1; i < ce; i++){
        if(v[i]>v[pos]) pos = i;
    }
    return pos;
}