// 7.5 
// Se dispone del archivo “sepadaroresVarios.txt” cuyas cadenas se encuentran separadas por punto, espacios
// o comas. Realizar un programa para obtener e imprimir por pantalla cada cadena.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fArch;
    char str[101];
    char sep[4] = " ,.";
    fArch = fopen("SEPARADORESVARIOS.txt", "rb");
    if(fArch == NULL){
        printf("FATAL ERROR.\n");
        exit(1);
    }

    while (fgets(str,101,fArch) != NULL)
    {
        char *parte = strtok(str, sep);
        while(parte != NULL){
            printf(" %s",parte);
            parte = strtok(NULL, sep);
        }
    }
    

    fclose(fArch);
    return 0;
}
