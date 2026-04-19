// 2.4
// La empresa de turismo GUADALAJARA VIAJES comercializa 10 diferentes tours a través de 15 agencias en todo
// el país. Diariamente cada agencia envía la cantidad de ventas efectuadas de cada tour, indicando agencia,
// tours y la cantidad de pasajes. Algunas agencias envían 0 en la cantidad cuando no existen pasajes para un
// tour determinado, pero no en todas.
// La información que se envía tiene los siguientes datos que se ingresan en forma desordenada:
// • Código de agencia (de 1 a 15)
// • Código de tour (1 a 10)
// • Cantidad de pasajes (0 a 20)
// Informar:
// a. El total de pasajes vendidos por tour en cada agencia.
// b. El número de agencia que obtuvo la máxima cantidad de pasajes vendidos. (puede repetirse)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AGENCIAS 15
#define TOURS 10

int main(){
    srand(time(NULL));
    int matrizToursAgencias[TOURS][AGENCIAS] = {{0}};
    for (int i = 0; i < TOURS; i++){
        for (int j = 0; j < AGENCIAS; j++){
            matrizToursAgencias[i][j] = NumAleatorio(0,21);
        }
    }
    MostrarMatriz(matrizToursAgencias, TOURS, AGENCIAS);
    return 0;
}

int NumAleatorio( int min,int max){
    int num = min + (rand() % (max - min));
    return num;
}

void MostrarMatriz(int m[][AGENCIAS], int f, int c){
    printf("\tA  G  E  N  C  I  A  S\n\n     |");
    for(int k = 0; k < c; k++){
        printf("%3d",k+1);
    }
    printf("\n");
    for(int k = 0; k < (c+2)*3; k++){
        printf("-");
    }
    printf("\n");
    for(int i = 0; i < f; i++){
        if(i==0)printf("T ");
        else 
            if(i==2)printf("O ");
            else
                if (i==4)printf("U ");
                else
                    if (i==6)printf("R ");
                    else
                        if (i==8)printf("S ");
                        else printf("  ");
        printf("%3d|",i+1);
        for(int j = 0; j < c; j++){
            printf("%3d",m[i][j]);
        }
        printf("\n");
    }
}
