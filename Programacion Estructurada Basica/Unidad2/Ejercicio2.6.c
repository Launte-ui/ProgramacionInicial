// 2.6 
// Se solicita modificar el programa anterior para que además de la butaca y fila ingrese la cantidad de butacas
// de la reserva. En dicho caso se deberá verificar si existen a partir de la butaca ingresada la cantidad suficiente
// de butacas disponibles consecutivas (tomar siempre hacia la derecha del seleccionado). Si están disponibles
// reservar todas las butacas, sino mostrar un mensaje de error.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 12
#define COLUMNAS 9

void LlenarVectorPorFilas(int[][COLUMNAS], int, int, int[]);
void LlenarVectorPorColumnas(int[][COLUMNAS], int, int, int[]);
void MostrarMatriz(int[][COLUMNAS], int, int);
void CargaSalaDeCine(int[][COLUMNAS], int, int);
int NumAleatorio(int, int);
void MostrarVector(int[], int);
int BusquedaSecuencial(int[], int, int);
void OrdenarMayorMenosParalelos(int[], int[], int);
int PosMaximo(int[], int, int);


int main(){
    srand(time(NULL));
    int m[FILAS][COLUMNAS];
    int vFilas[FILAS], vColumnas[COLUMNAS], vParaleloPos[COLUMNAS]={1,2,3,4,5,6,7,8,9};
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
    printf("\n\033[34mLa sala de cine cuenta con %d asientos libres y %d ocupados\033[37m",cantDisponibles,cantReservados);
    LlenarVectorPorFilas(m, FILAS, COLUMNAS, vFilas);
    
    if(BusquedaSecuencial(vFilas,0,FILAS)>=0){
        printf("\n\033[36mHay filas vacias. A continuacion se listan los numeros de las mismas\033[37m:");
        for(int i = 0; i < FILAS; i++) if(vFilas[i]==0)printf("%3d",i+1);
    }
    else printf("\n\033[36mNo hay filas vacias\033[37m");

    int maxFilaPos = PosMaximo(vFilas,FILAS,0);
    printf("\n\033[36mA continuacion se listan las filas con mas espectadores\033[37m:");
    for(int i = 0; i < FILAS; i++) if(vFilas[i]==vFilas[maxFilaPos])printf("%3d",i+1);

    LlenarVectorPorColumnas(m, FILAS, COLUMNAS, vColumnas);
    OrdenarMayorMenosParalelos(vColumnas, vParaleloPos, COLUMNAS);

    printf("\n\033[33mNumero de butacas\t\033[37m:");
    MostrarVector(vParaleloPos, COLUMNAS);
    printf("\033[33mCantidad de personas\t\033[37m:");
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
    for(int i = 0; i < ce; i++){
        printf("%3d",v[i]);
    }
    printf("\n");
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