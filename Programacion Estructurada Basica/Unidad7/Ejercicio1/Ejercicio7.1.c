// 7.1
// Realizar un programa que genere el archivo “cadenas.txt” que guarde cadenas de caracteres
// que se ingresan por teclado hasta ingresar la cadena “FINALIZAR”.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void EscribirArchTxtChar(char*);
void EscribirArchTxtStr(char*);

int main(){
    EscribirArchTxtChar("CADENAS_char.txt");
    EscribirArchTxtStr("CADENAS_str.txt");
    return 0;
}

void EscribirArchTxtChar(char *na){
    FILE *arch;
    char car;
    arch = fopen(na,"wt");
    if(arch == NULL){
        printf("FATAL ERROR.\n");
        exit(1);
    }
    car = fgetc(stdin);
    while(car != '\n'){
        fputc(car, arch);
        car = fgetc(stdin);
    }
    fclose(arch);
}

void EscribirArchTxtStr(char *na){
    FILE *arch;
    char str[26];
    arch = fopen(na,"wt");
    if(arch == NULL){
        printf("FATAL ERROR.\n");
        exit(1);
    }
    fgets(str,26,stdin);
    while(strcmpi(str,"FINALIZAR\n")){
        fputs(str,arch);
        fgets(str,26,stdin);
    }
    fclose(arch);
}