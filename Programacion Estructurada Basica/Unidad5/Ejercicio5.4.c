// 5.4
// Hacer un programa que cargue un vector de 10 enteros y lo muestre usando una función para cargar y otra mostrar sin utilizar subíndices.
#include <stdio.h>
void MostrarVector(int[]);
void CargaVector(int[]);

int main(){
    int vec[10] = {0};

    CargaVector(vec);
    MostrarVector(vec);

    return 0;
}

void CargaVector(int v[]){
    for(int i = 0; i < 10; i++){
        *(v+i) = i;
    }
}

void MostrarVector(int v[]){
    for(int i = 0; i < 10; i++){
        printf("%d\n",*(v+i));
    }
}