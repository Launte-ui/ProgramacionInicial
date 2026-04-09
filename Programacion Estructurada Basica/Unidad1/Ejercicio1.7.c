// 1.7
// Dado un vector de 10 enteros, ingresar un entero por teclado, buscarlo y, si se lo encuentra,
// generar un nuevo vector con los índices correspondientes a las ubicaciones en el primer vector del entero ingresado.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int vectorInicial[10];
    printf("Vector inicial: [ ");
    for(int i = 0; i < 10; i++){
        vectorInicial[i] = rand() % 4;
        printf("%d, ", vectorInicial[i]);
    }
    printf("]\n ");
    int numBuscado = rand() % 4;
    int posNum = BusquedaSecuencial(vectorInicial, numBuscado, 10);
    if(posNum==-1)printf("No se encontro el numero %d\n", numBuscado);
    else {
        int index = 0, j=0 ;
        for(int i = 0; i < 10; i++){
            if(vectorInicial[i]==numBuscado) index++;
        }
        printf("El numero era %d\n", numBuscado);
        int vectorDinamico[index];
        for(int i = 0; i < 10; i++){
            if(vectorInicial[i]==numBuscado){
                vectorDinamico[j] = i;
                j++;
            }
        }
        printf("Vector dinamico: [ ");
        for(int i = 0; i < index; i++){
            printf("%d, ", vectorDinamico[i]);
        }
        printf("]\n ");
    }

    return 0;
}

int BusquedaSecuencial(int v[], int elemento, int ce){
    int pos = -1, i = 0;
    while(i<ce && pos == -1){
        if(v[i]==elemento)pos=i;
        i++;
    }

    return pos;
}