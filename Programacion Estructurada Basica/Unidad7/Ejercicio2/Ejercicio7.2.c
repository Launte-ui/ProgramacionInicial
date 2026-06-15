// 7.2
// Realizar un programa que lea el contenido del archivo “cadenas.txt” creado en el punto anterior
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void LeerArchTxtChar(char*);
void LeerArchTxtStr(char*);

int main(){
    printf("\n-----LEER POR CARACTER-----\n");
    LeerArchTxtChar("CADENAS.txt");
    printf("\n-----LEER POR CADENA-----\n");
    LeerArchTxtStr("CADENAS.txt");
    return 0;
}

void LeerArchTxtChar(char *na){
    FILE *arch;
    arch = fopen(na,"rt");
    char cAux;
    if(arch==NULL){
        printf("ERROR");
        exit(1);
    }
    cAux = fgetc(arch);
    while(!feof(arch)){
        printf("%c",cAux);
        Sleep(20);
        cAux = fgetc(arch);
    }
    fclose(arch);
}

void LeerArchTxtStr(char *na){
    FILE *arch;
    arch = fopen(na,"rt");
    char strAux[500];
    if(arch==NULL){
        printf("ERROR");
        exit(1);
    }
    while(fgets(strAux,500,arch)){
        Sleep(500);
        printf("%s",strAux);
    }
    fclose(arch);
}