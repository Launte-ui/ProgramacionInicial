/* 6.4 Realizar un programa que permite actualizar una lista de precios en forma masiva, ingresando un porcentaje
de incremento. El archivo se llama PRECIOS.dat y fue generado utilizando la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int cod;
    float pre;
    char des[51];
}sProducto;

FILE* AbrirArchivo(char*, char*);
void MostrarArchivo(char*);

int main(){
    FILE *fPrecios;
    sProducto prodAux;
    float porInc;

    MostrarArchivo("PRECIOS.dat");

    printf("Ingrese porcentaje de incremento de los productos: ");
    scanf("%f",&porInc);
    
    fPrecios = AbrirArchivo("PRECIOS.dat","r+b");
    fread(&prodAux,sizeof(sProducto),1,fPrecios);
    while(!feof(fPrecios)){
        prodAux.pre += (prodAux.pre/100)*porInc;
        fseek(fPrecios,sizeof(sProducto)*-1,1);
        fwrite(&prodAux,sizeof(sProducto),1,fPrecios);
        fflush(fPrecios);
        fread(&prodAux,sizeof(sProducto),1,fPrecios);
    }
    fclose(fPrecios);

    MostrarArchivo("PRECIOS.dat");

    return 0;
}


FILE* AbrirArchivo(char *na, char *ma){
    FILE *fArch;
    fArch = fopen(na, ma);
    if(fArch == NULL){
        printf("Error al abrir (%s) el archivo %s.",ma,na);
        exit(1);
    }
    return fArch;
}

void MostrarArchivo(char *str){
    FILE *f;
    sProducto p;
    f = fopen(str, "rb");
    if(f==NULL){
        printf("No se pudo abrir el archivo %s para ser mostrado.",str);
        exit(1);
    }
    fread(&p, sizeof(sProducto),1,f);
    while(!feof(f)){
        printf("|%d|\t%.2f|%51s|\n",p.cod, p.pre, p.des);
        fread(&p, sizeof(sProducto),1,f);
    }
    fclose(f);
}