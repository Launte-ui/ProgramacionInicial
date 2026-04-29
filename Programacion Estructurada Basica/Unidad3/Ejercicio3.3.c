// 3.3
// Ingresar nombre y DNI de los alumnos de un curso.
// Como máximo el curso puede tener 50 alumnos.
// La carga finaliza con un alumno de nombre FIN.
// Luego de cargar los alumnos se pide:
// a.
// Ingresar nombres de a uno en uno y buscarlos.
// Si el nombre está en el curso mostrar su DNI y sino informar que no está.
// Seguir ingresando nombres hasta que se ingrese un nombre igual a NOBUSCARMAS.
// b.
// Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor.

#include <stdio.h>
#include <string.h>
#define ALUSCANT 50
#define NOMLONG 21

void LeerTextoLimpio(char[],int);
int LeerYValidarEnteroRango(int,int);
int BusquedaBinariaString(char[][NOMLONG], char[], int);
int PosMinStr(char[][NOMLONG], int, int);
void OrdenarMenorMayorParalelos(char[][NOMLONG],int[],int);

int main(){
    char nombre[ALUSCANT][NOMLONG];
    char nomAux[NOMLONG];
    int dni[ALUSCANT];

    int alus = 0;

    do{
        printf("Ingrese su Nombre: ");
        LeerTextoLimpio(nomAux,NOMLONG);
        if(strcmpi(nomAux,"fin")){
            strcpy(nombre[alus],nomAux);
            printf("Ingrese su DNI: ");
            dni[alus] = LeerYValidarEnteroRango(9999999,100000000);
            getchar();
            alus++;
        }
    }while(alus < ALUSCANT && strcmpi(nomAux, "fin"));
    int nomPos;
    do{
        printf("\nIngrese el Nombre que busca: ");
        LeerTextoLimpio(nomAux,NOMLONG);
        if(strcmpi(nomAux,"nobuscarmas")){
            nomPos = BusquedaBinariaString(nombre,nomAux,alus);
            if(nomPos == -1) printf("\nNo encontramos ese alumno");
            else printf("\nEl dni del alumno es: %d. Se encontro en la posicion: %d",dni[nomPos],nomPos);
        }
    }while(strcmpi(nomAux, "nobuscarmas"));
    int i=0;
    OrdenarMenorMayorParalelos(nombre,dni,alus);
    while(i<alus){
        printf("%8d, %20s\n",dni[i],nombre[i]);
        i++;
    }
    if(!alus) printf("\nNo se registro a ningun alumno.");
    printf("\nEl programa a terminao");

    return 0;
}

void LeerTextoLimpio (char texto[], int largo){
    int i = 0;
    fgets(texto, largo, stdin);
    while (texto[i]!='\0'){
        if (texto[i]=='\n') texto[i]='\0';
        else i++;
    }
}

int LeerYValidarEnteroRango(int li, int ls){
    int num;
    scanf("%d",&num);
    while(num<li || num>ls){
        printf("ERROR - Numero entero ingresado fuera de rango. Ingrese nuevamente: ");
        scanf("%d",&num);
    }
    return num;
}

int BusquedaBinariaString(char vStr[][NOMLONG], char strBuscado[], int ce){
    int pos = -1, med;
    int li = 0, ls = ce-1;
    while(li <= ls && pos == -1){
        med = (li+ls)/2;
        int cmp = strcmpi(vStr[med], strBuscado);
        if(cmp == 0) pos = med;
        else if(cmp > 0) ls = med - 1;
        else li = med + 1;
    }
    return pos;
}

int PosMinStr(char vStr[][NOMLONG], int ce, int ini){
    char strAux[NOMLONG];
    int pos = ini;
    strcpy(strAux,vStr[ini]);
    for (int i = ini+1; i<ce;i++){
        if(strcmpi(strAux,vStr[i])>0) {
            strcpy(strAux, vStr[i]);
            pos = i;
        }
    }
    return pos;
}

void OrdenarMenorMayorParalelos(char vStr[][NOMLONG], int vp[] ,int ce){
    int minP, intAux;
    char strAux[NOMLONG];
    for(int i = 0; i < ce; i++){
        minP = PosMinStr(vStr, ce, i);
        // aux = vStr[minP];
        strcpy(strAux, vStr[minP]);
        // vStr[minP] = vStr[i];
        strcpy(vStr[minP], vStr[i]);
        // vStr[i] = aux;
        strcpy(vStr[i], strAux);

        intAux = vp[minP];
        vp[minP] = vp[i];
        vp[i] = intAux;
    }
}
