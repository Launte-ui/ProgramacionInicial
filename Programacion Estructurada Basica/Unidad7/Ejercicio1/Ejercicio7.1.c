// 7.1
// Realizar un programa que genere el archivo “cadenas.txt” que guarde cadenas de caracteres
// que se ingresan por teclado hasta ingresar la cadena “FINALIZAR”.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arch;
    char str[26];
    arch = fopen("CADENAS.txt","wt");
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
    return 0;
}