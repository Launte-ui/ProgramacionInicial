// 5.9
// Desarrolle un programa que solicite el ingreso de un numero entero, que indica a su vez cuantos números
// enteros ingresara el usuario. Crear en memoria dinámica el vector para almacenar el tamaño exacto de los
// datos y leer los enteros que serán guardados en el vector “dinámico”. Informar el promedio de los datos
// ingresados.
#include <stdio.h>

int main(){
    int longVec;
    int *pVec;
    printf("Ingrese numero entero: ");
    scanf("%d",&longVec);

    pVec = (int*) malloc(sizeof(int)*longVec);
    if(pVec == NULL){
        printf("No se hayo espacio para esa longitud de vector");
        exit(1);
    }
    for(int i = 0; i < longVec; i++){
        *(pVec + i) = i*5;
    }
    for(int j = 0; j < longVec; j++){
        printf("%d\n",*(pVec+j)); 
    }
    free(pVec);
    pVec = NULL;
    return 0;
}
