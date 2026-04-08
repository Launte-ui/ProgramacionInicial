//1.4
// Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI negativo. 
// Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no pueden existir 2 o más alumnos con el mismo DNI.
// Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado de mayor a menor por nota.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ALUMNOS 60

int NumAleatorio(int, int);
int Repetido(int [], int, int);
void MostrarNotasPorAlumno(int [], int [], int);
void IniciarVectorEnCeros(int [], int);

int main() {
    srand(time(NULL));
    int alumnos = NumAleatorio(10, MAX_ALUMNOS);
    int dni[MAX_ALUMNOS];
    int notas[MAX_ALUMNOS];

    IniciarVectorEnCeros(dni, MAX_ALUMNOS);
    IniciarVectorEnCeros(notas, MAX_ALUMNOS);

    int dniAlumno;

    for(int i = 0; i < alumnos; i++){
        do{
           dniAlumno = NumAleatorio(4000000, 600000000);
        }while(Repetido(dni, i, dniAlumno) != -1);
        dni[i] = dniAlumno;
        notas[i] = NumAleatorio(1, 11);
    }

    int posMax, aux;
    for(int i = 0; i < alumnos; i++){
        posMax = PosMaximo(notas, alumnos, i);
        aux = notas[posMax];
        notas[posMax] = notas[i];
        notas[i] = aux;

        aux = dni[posMax];
        dni[posMax] = dni[i];
        dni[i] = aux;

    }
    MostrarNotasPorAlumno(dni, notas, alumnos);
    return 0;
}

int NumAleatorio( int min,int max){
    int num = min + (rand() % (max - min));
    return num;
}

int Repetido(int v[], int ce, int elemento){
    int pos = -1, i = 0;
    while(pos == -1 && i < ce){
        if (v[i] == elemento) pos = i;
        else i++;
    }
    return pos;
}

void MostrarNotasPorAlumno(int alumno[],int notas[], int ce){
    for (int i = 0; i < ce; i++) {
        printf("%d\t| %d\n", alumno[i], notas[i]);
    }
}

void IniciarVectorEnCeros(int v[], int ce){
    for(int i = 0; i < ce; i++){
        v[i] = 0;
    }
}

int PosMaximo(int v[], int ce, int ini){
    int posMax = ini;
    for (int i = ini + 1; i < ce; i++){
        if (v[i] > v[posMax]) {
            posMax = i;
        }
    }
    return posMax;
}