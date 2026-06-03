#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dni;
    char nomAp[81];
    int n1;
    int n2;
    float prom;
}sAlumno;


FILE *AbrirArchivo(char*, char*);
int IngreseEnteroVal(int, int);
void LeerTextoLimpio(char*, int);

int main(){
    FILE *archAlus;
    sAlumno alu;
    int dniAux;
    int cantAlus = 0;
    float n1Aux, n2Aux;

    archAlus = AbrirArchivo("ALUMNOS.dat","wb");

    printf("Ingrese DNI del alumno: ");
    dniAux = IngreseEnteroVal(0,99999999);
    while(dniAux != 0){

        alu.dni = dniAux;

        printf("Ingrese Nombre y Apellido del alumno: ");
        LeerTextoLimpio(alu.nomAp,81);


        printf("Ingrese Nota 1: ");
        alu.n1 = IngreseEnteroVal(1,10);
        n1Aux = alu.n1;

        printf("Ingrese Nota 2: ");
        alu.n2 = IngreseEnteroVal(1,10);
        n2Aux = alu.n2;

        alu.prom = (n1Aux + n2Aux) / 2;

        fwrite(&alu, sizeof(sAlumno),1,archAlus);
        printf("Ingrese DNI del alumno: ");
        dniAux = IngreseEnteroVal(0,99999999);
    }
    fclose(archAlus);


    archAlus = AbrirArchivo("ALUMNOS.dat","rb");
    fread(&alu, sizeof(sAlumno), 1, archAlus);
    while(!feof(archAlus)){
        printf("|%8d| %81s| %2d| %2d| %2.2f|\n",alu.dni,alu.nomAp,alu.n1, alu.n2, alu.prom);
        fread(&alu, sizeof(sAlumno), 1, archAlus);
    }
    fclose(archAlus);

    return 0;
}

FILE *AbrirArchivo(char *na, char *ma){
    FILE *pf;
    pf = fopen(na, ma);

    if(pf == NULL){
        printf("A ocurrido un error con el archivo %s...",na);
        exit(1);
    }

    return pf;
}

int IngreseEnteroVal(int li, int ls){
    int num;
    scanf("%d",&num);
    while(num < li || num > ls){
        printf("ERROR -  Se ingreso un valor invalido: ");
        scanf("%d",&num);
    }
    return num;
}

void LeerTextoLimpio(char *str, int largo){
    int i = 0;
    getchar();
    fgets(str, largo, stdin);
    while(*(str+i) != '\0' && i < largo){
        if(*(str+i) == '\n')
            *(str+i) = '\0';
        else
            i++;
    }
}
