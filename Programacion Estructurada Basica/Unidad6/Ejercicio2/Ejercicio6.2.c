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
void MostrarArchivo(char*);

int main(){
    FILE *archAlus, *archPro, *archCur, *archRep;
    sAlumno alu;

    archAlus = AbrirArchivo("ALUMNOS.dat","rb");
    archPro = AbrirArchivo("PROMOCIONADOS.dat","wb");
    archCur = AbrirArchivo("CURSADOS.dat","wb");
    archRep = AbrirArchivo("REPROBADOS.dat","wb");
    fread(&alu, sizeof(sAlumno), 1, archAlus);
    while(!feof(archAlus)){
        if(alu.n1 >=7 && alu.n2 >= 7)
            fwrite(&alu, sizeof(sAlumno), 1, archPro);
        else if(alu.n1 < 4 && alu.n2 < 4)
            fwrite(&alu, sizeof(sAlumno), 1, archRep);
        else
            fwrite(&alu, sizeof(sAlumno), 1, archCur);
        fread(&alu, sizeof(sAlumno), 1, archAlus);
    }
    fclose(archAlus);
    fclose(archPro);
    fclose(archRep);
    fclose(archCur);

    printf("ALUMNOS PROMOCIONADOS-------------------------:\n");
    MostrarArchivo("PROMOCIONADOS.dat");
    printf("ALUMNOS REPROBADOS-------------------------:\n");
    MostrarArchivo("REPROBADOS.dat");
    printf("ALUMNOS APROBADOS-------------------------:\n");
    MostrarArchivo("CURSADOS.dat");

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

void MostrarArchivo(char *str){
    FILE *f;
    sAlumno a;
    f = fopen(str, "rb");
    fread(&a, sizeof(sAlumno),1,f);
    while(!feof(f)){
        printf("|%8d| %81s| %2d| %2d| %2.2f|\n",a.dni,a.nomAp,a.n1, a.n2, a.prom);
        fread(&a, sizeof(sAlumno),1,f);
    }
    fclose(f);
}
