// 6.11 
// Se dispone de un archivo llamado Rating.dat que guarda la información de los puntos obtenidos de rating
// en los distintos programas de canales de cable a lo largo del día. Cada registro contiene:
// • Número de canal (entero)
// • Programa (texto de 35 caracteres máximo)
// • Rating (float)
// El archivo se encuentra ordenado por canal.
// Se solicita informar:
// a. Aquellos canales que obtengan menos de 15 puntos en total.
// b. El canal más visto.
// c. Generar un archivo con el promedio de rating de cada canal que incluya dos campos:
// • Número de canal.
// • Promedio.
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    char prog[36];
    float rat;
}sRating;

typedef struct{
    int num;
    float pro;
}sPromedio;

FILE *AbrirArchivo(char*, char*);
void MostrarRating(char*);
void MostrarPromedio(char*);

int main(){
    FILE *fRating;
    FILE *fPromedio;
    sRating ratAux;
    sPromedio proAux;

    fRating = AbrirArchivo("RATING.dat", "rb");
    fPromedio = AbrirArchivo("PROMEDIO.dat", "wb");

    fread(&ratAux, sizeof(sRating), 1, fRating);
    int maxCan;
    float maxRat = 0;
    while(!feof(fRating)){
        proAux.num = ratAux.num;
        int progCant = 0;
        float ratAcum = 0;
        while(!feof(fRating) && ratAux.num == proAux.num){
            ratAcum += ratAux.rat;
            progCant++;
            fread(&ratAux, sizeof(sRating), 1, fRating);
        }
        if(ratAcum < 15){
            printf("El canal %d tiene menos de 15 puntos de rating\n",proAux.num);
        }
        if(ratAcum > maxRat){
            maxCan = proAux.num;
            maxRat = ratAcum;
        }
        proAux.pro = ratAcum / progCant;
        fwrite(&proAux, sizeof(sPromedio), 1, fPromedio);
    }
    printf("El canal mas visto es el canal %d\n",maxCan);

    fclose(fRating);
    fclose(fPromedio);

    MostrarRating("RATING.dat");
    MostrarPromedio("PROMEDIO.dat");

    return 0;
}


FILE *AbrirArchivo(char *na, char *ma){
    FILE *arch;
    arch = fopen(na, ma);
    if(arch == NULL){
        printf("FATAL ERROR - No se pudo abrir %s en modo %s.",na,ma);
        exit(1);
    }
    return arch;
}

void MostrarRating(char *na){
    printf("RATING:\n");
    FILE *arch;
    sRating aux;
    arch = fopen(na, "rb");
    if(arch == NULL){
        printf("FATAL ERROR - No se pudo abrir %s en modo lectura.",na);
        exit(1);
    }
    fread(&aux, sizeof(sRating), 1, arch);
    while(!feof(arch)){
        printf("%d|%36s|%f\n",aux.num,aux.prog,aux.rat);
        fread(&aux, sizeof(sRating), 1, arch);
    }
    fclose(arch);
}

void MostrarPromedio(char *na){
    printf("PROMEDIO:\n");
    FILE *arch;
    sPromedio aux;
    arch = fopen(na, "rb");
    if(arch == NULL){
        printf("FATAL ERROR - No se pudo abrir %s en modo lectura.",na);
        exit(1);
    }
    fread(&aux, sizeof(sPromedio), 1, arch);
    while(!feof(arch)){
        printf("%d|%.2f\n",aux.num,aux.pro);
        fread(&aux, sizeof(sPromedio), 1, arch);
    }
    fclose(arch);
}
