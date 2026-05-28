// 5.5
//  Al programa anterior agregarle una función que reciba la dirección de inicio del vector 
// y un número a buscar y retorne un puntero al dato encontrado o NULL sino lo encuentra.
//  En el main agregar un proceso de búsqueda que se repita hasta ingresar un número negativo o cero a buscar. 
//  Si se lo encontró se debe indicar en que posición del vector estaba
// (calcular dicha posición utilizando la dirección retornada)
#include <stdio.h>

void MostrarVector(int[], int);
void CargaVector(int[], int);
int* BusquedaSecuencial(int*, int, int);

int main(){
    int vec[10] = {0};
    int numBuscado;
    int* dirBuscado;

    CargaVector(vec,10);
    MostrarVector(vec,10);

    printf("Ingrese un numero a buscar entre 0 y 10: ");
    scanf("%d",&numBuscado);
    while(numBuscado >= 0){
        dirBuscado = BusquedaSecuencial(vec, 10, numBuscado);
        printf("Dir %x\n",vec);
        printf("Dir %x\n",dirBuscado);
        if(dirBuscado == NULL)
            printf("No se encontro el elemento en el vector\n");
        else
            printf("Se econtro el elemento en la poscion %d\n",dirBuscado - vec);
        printf("Ingrese un numero a buscar entre 0 y 10: ");
        scanf("%d",&numBuscado);
    }

    return 0;
}

void CargaVector(int v[], int ce){
    for(int i = 0; i < ce; i++){
        *(v+i) = i;
    }
}

void MostrarVector(int v[], int ce){
    for(int i = 0; i < ce; i++){
        printf("%d\n",*(v+i));
    }
}

int* BusquedaSecuencial(int *v, int ce, int elemento){
    int *dir = NULL, i = 0;
    while(dir == NULL && i < ce){
        if(*(v+i) == elemento)
            dir = v+i;
        else
            i++;
    }
    return dir;
}
