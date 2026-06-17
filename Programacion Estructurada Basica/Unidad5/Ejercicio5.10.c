// 5.10
// Utilizando la siguiente definición de estructura, realice un programa que solicite memoria para 5 alumnos.
// struct alumno
// {
// int legajo;
// char sexo;
// char nombre[30];
// float promedio;
// };
// El usuario ingresara por teclado los datos que se cargara en la estructura- Mostrar el nombre de los alumnos
// uno debajo del otro. A continuación, mostrar el alumno con mejor promedio.
#include <stdio.h>
#include <stdlib.h>
#define cant 5

typedef struct {
    int legajo;
    char sexo;
    char nombre[30];
    float promedio;
}sAlumno;

void BuscarMaxProm(sAlumno*, sAlumno*, int);

int main(){
    sAlumno *pVec, mejorProm;
    pVec = (sAlumno*) calloc(sizeof(sAlumno), cant);

    if(pVec == NULL){
        printf("FATAL ERROR.\n");
        exit(1);
    }

    for(int i = 0; i < cant; i++){
        printf("Ingrese legajo: ");
        scanf("%d",&(pVec+i)->legajo);
        while((pVec+i)->legajo < 0 || (pVec+i)->legajo > 9999){
            printf("Legajo invalido: ");
            scanf("%d",&(pVec+i)->legajo);
        }
        printf("Ingrese sexo: ");
        getchar();
        scanf("%c",&(pVec+i)->sexo);
        while((pVec+i)->sexo != 'm' && (pVec+i)->sexo != 'f'){
            printf("Sexo invalido: ");
            scanf("%c",&(pVec+i)->sexo);
        }
        printf("Ingrese nombre: ");
        getchar();
        gets((pVec+i)->nombre);
        printf("Ingrese promedio: ");
        scanf("%f",&(pVec+i)->promedio);
        while((pVec+i)->promedio < 1 || (pVec+i)->promedio > 10){
            printf("Promedio invalido: ");
            scanf("%f",&(pVec+i)->promedio);
        }
    }
    for(int i = 0; i < cant; i++){
        printf("%d|%c|%30s|%2.1f\n",(pVec+i)->legajo,(pVec+i)->sexo,(pVec+i)->nombre,(pVec+i)->promedio);
    }

    BuscarMaxProm(pVec, &mejorProm, cant);
    printf("El alumno con mejor promedio es %s.\n",mejorProm.nombre);
    free(pVec);
    pVec = NULL;
    return 0;
}

void BuscarMaxProm(sAlumno *vec, sAlumno *maxProm, int ce){
    int i = 1;
    sAlumno max = *(vec);
    while(i < ce){
        if(max.promedio < (vec+i)->promedio){
            max = *(vec+i);
        }
        i++;
    }
    *maxProm = max;
}