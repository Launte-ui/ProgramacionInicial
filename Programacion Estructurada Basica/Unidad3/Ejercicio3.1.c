// 3.1
// Ingresar una frase de hasta 500 caracteres y contar cuántas palabras contiene dicha frase.
// a. Considerar que las palabras están separadas por un único espacio.
// b. Considerar que las palabras pueden estar separadas por más de un espacio consecutivo.

#include <stdio.h>
#include <string.h>
#include <time.h>
#define LONG 1000

int main(){
    srand(time(NULL));
    char palabrasRan[10][15]={"Spinosaurus", "Hola", "Yo","Te","Ayudo","Gojo"," ", " ", "OSTIA", "un"};
    char palabra[15];
    char frase[LONG];
    int enPalabra = 0;
    int palabrasCant =0;
    strcpy(frase, "");
    int i=0;
    while(i<LONG){
        strcpy(palabra,palabrasRan[NumAleatorio(0,10)]);
        if(strlen(palabra)+i<LONG){
            printf("\n%s", palabra);
            strcat(frase,palabra);
            i+=strlen(palabra);
        }
        else i=LONG;
        
    }
    printf("\nLa frase es de longitud %d",strlen(frase));
    printf("\n");
    MostrarChar(frase, LONG);
    printf("\n");

    for(int j=0;j<strlen(frase);j++){
        if(frase[j]!=' ' && !enPalabra){
            palabrasCant++;
            enPalabra=1;
        }
        if(frase[j]==' ' && enPalabra){
            enPalabra=0;
        }
    }
    printf("\nLa frase tiene %d palabras",palabrasCant);

    return 0;
}

void MostrarChar(char c[],int ce){
    printf("%s", c);
}

int NumAleatorio(int min, int max){
    return (min + rand()%(max-min));
}