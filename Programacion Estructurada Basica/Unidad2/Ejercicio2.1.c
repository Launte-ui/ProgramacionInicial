// 2.1
// Ingresar una matriz de 3x3 por teclado y un número entero. Realizar el producto de la matriz por la constante.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int matriz[3][3];
    int factor = NumAleatorio();
    printf("La matriz se multplicara por el numero %d\n",factor);
    for(int f = 0; f<3; f++){
        for(int c = 0; c<3; c++){
            matriz[f][c] = NumAleatorio();
        }
    }
    
    for(int f = 0; f<3; f++){
        for(int c = 0; c<3; c++){
            printf("%2d", matriz[f][c]);
        }
        printf("\n");
    }
    printf("\n");

    for(int f = 0; f<3; f++){
        for(int c = 0; c<3; c++){
            matriz[f][c] *= factor;
        }
    }
    
    for(int f = 0; f<3; f++){
        for(int c = 0; c<3; c++){
            printf("%2d", matriz[f][c]);
        }
        printf("\n");
    }
    return 0;
}

int NumAleatorio(){
    int num = rand() % 4;
    return num;
}
