// 5.11
// Se debe realizar un programa para ingresar los DNI de los asistentes a un evento. Se cargan todos los DNI
// hasta que se recibe un DNI igual 0. Al finalizar mostrar el listado de todos los DNI ingresados. Los datos
// deben almacenarse en un vector en memoria dinámica al no saber la cantidad comenzar con un vector de 5
// elementos y si es necesario y el vector se llena ir aumentando la capacidad del vector de 5 en 5.
#include <stdio.h>
#include <stdlib.h>

int IngresoEnteroVal(int, int);
int BuscarDni(int*, int, int);

int main(){
    int *vDnis, maxCant = 5, cant = 0, dniAux, pos;
    vDnis = (int*) calloc(maxCant,sizeof(int));

    if(vDnis == NULL){
        printf("FATAL ERROR.\n");
        exit(1);
    }

    printf("INGRESE DNI: ");
    dniAux = IngresoEnteroVal(0,99999999);
    while( dniAux != 0){
        pos = BuscarDni(vDnis, dniAux, cant);
        if(pos == -1){
            if(cant == maxCant){
                maxCant+=5;
                vDnis = (int*) realloc(vDnis,sizeof(int)*maxCant);
                if(vDnis == NULL){
                    printf("FATAL ERROR.\n");
                    exit(1);
                }
            }
            *(vDnis+cant) = dniAux;
            cant++;
            printf("El dni fue guardado SATISFACTORIAMENTE.\n");
        }
        else{
            printf("El dni ingreado YA SE encuentra guardado, en la pos %d.\n", pos);
        }
        printf("INGRESE DNI: ");
        dniAux = IngresoEnteroVal(0,99999999);
    }

    for(int i = 0; i < cant; i++){
        printf("%3d|%8d\n",i+1,*(vDnis+i));
    }

    free(vDnis);
    vDnis = NULL;

    return 0;
}

int IngresoEnteroVal(int li, int ls)
{
    int num;
    scanf("%d",&num);
    while(num < li || num > ls){
        printf("ERROR - Se ha ingresado un valor invalido: ");
        scanf("%d",&num);
    }
    return num;
}

int BuscarDni(int *v, int bus, int ce){
    int pos = -1, i = 0;
    while(i<ce && pos == -1){
        if(*(v+i)==bus){
            pos = i;
        }
        else
            i++;
    }
    return pos;
}
