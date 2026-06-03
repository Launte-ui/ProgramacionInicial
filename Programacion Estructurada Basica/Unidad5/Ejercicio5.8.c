// 5.8
// Dada la estructura alumno:
// struct alumno
// {
// char nom[31];
// int dni;
// };
// Realizar un programa que permita cargar alumnos y mostrarlos. Como máximo permitir 50 alumnos. El ingreso finaliza con un DNI igual a 0.
// Realizar una función para cargar y otra para mostrar usando notación de punteros.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 50

typedef struct
{
    char nom[31];
    int dni;
}sAlumno;

int IngresoEnteroVal(int, int);
void CargarAlumnos(sAlumno*,int,int*);
void MostrarAlumnos(sAlumno*,int);

int main(){
    sAlumno alus[TAM];
    sAlumno *pAlus;
    pAlus = alus;
    int cantAlus;
    int *pCantAlus;
    pCantAlus = &cantAlus;
    
    CargarAlumnos(pAlus,TAM,pCantAlus);
    
    MostrarAlumnos(pAlus,cantAlus);
    return 0;
}

int IngresoEnteroVal(int li, int ls){
    int num;
    scanf("%d",&num);
    while(num < li || num > ls){
        printf("\nERROR - Se ha ingresado un numero fuera de rango. Ingrese un numero entre %d y %d: ",li,ls);
        scanf("%d",&num);
    }
    return num;
}

sAlumno* BusquedaSecuencial(sAlumno *v, int ce, int elemento){
    int i = 0;
    sAlumno* dir = NULL;
    while(dir == NULL && i < ce){
        if((*(v+i)).dni == elemento)
            dir = v+i;
        else
            i++;
    }
    return dir;
}

void CargarAlumnos(sAlumno *dA,int ce, int *cant){
    int dniAux, i = 0;
    sAlumno *aluPos;
    printf("Ingrese DNI del alumno: ");
    dniAux = IngresoEnteroVal(0, 99999999);
    while(dniAux != 0 && i < ce){
        aluPos = BusquedaSecuencial(dA, i, dniAux);
        if(aluPos == NULL){
            printf("Ingrese Nombre del alumno: ");
            scanf("%s",dA+i);
            (*(dA + i)).dni = dniAux;
            i++;
        }
        else
            printf("Se ingreso un DNI repetido\n");
        if(i<ce){
            printf("Ingrese DNI del alumno: ");
            dniAux = IngresoEnteroVal(0, 99999999);
        }
    }
    *cant = i;
}

void MostrarAlumnos(sAlumno* dA,int ce){
    for(int i = 0; i < ce; i++)
        printf("DNI: %08d| Nombre: %s\n", (dA+i)->dni,(dA+i)->nom);
}
