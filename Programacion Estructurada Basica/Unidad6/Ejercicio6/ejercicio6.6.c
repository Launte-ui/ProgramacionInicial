// 6.6
// Dado el archivo productos.dat con la siguiente estructura:
// • Código (entero)
// • Precio (float)
// • Descripción (de hasta 50 caracteres)
// Realizar un programa que permita eliminar productos dado su código
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int cod;
    float pre;
    char des[51];
}sProducto;

void MostrarArchivo(char*);
FILE *AbrirArchivo(char*, char*);

int main(){
    FILE *fProds;
    FILE *fTemp;
    sProducto prodAux;
    int codBus, prodPos;

    MostrarArchivo("PRODUCTOS.dat");
    
    codBus = IngresoEnteroVal(0, 9999);

    fProds = AbrirArchivo("PRODUCTOS.dat","rb");
    fTemp = AbrirArchivo("PRODUCTOS.tmp","wb");
    prodPos = BuscarProducto(fProds,codBus,&prodAux);
    if(prodPos != -1){
        printf("Lo encontramos.\n");
        fseek(fProds, 0, 0);
        fread(&prodAux, sizeof(sProducto), 1, fProds);
        while(!feof(fProds)){
            if(prodAux.cod != codBus){
                fwrite(&prodAux, sizeof(sProducto), 1, fTemp);
            }
            fread(&prodAux, sizeof(sProducto), 1, fProds);
        }
    }
    else
        printf("No esta che.\n");

    fclose(fProds);
    fclose(fTemp);

    MostrarArchivo("PRODUCTOS.dat");
    MostrarArchivo("PRODUCTOS.tmp");

    if(prodPos != -1){
        remove("PRODUCTOS.dat");
        rename("PRODUCTOS.tmp","PRODUCTOS.dat");
    }
    remove("PRODUCTOS.tmp");

    return 0;
}

void MostrarArchivo(char *na){
    FILE *arch;
    sProducto p;
    arch = fopen(na,"rb");
    if(arch == NULL){
        printf("NO SE PUDO ABRIR %s PARA SU LECTURA.",na);
        exit(1);
    }
    fread(&p,sizeof(sProducto),1,arch);
    while(!feof(arch)){
        printf("%d|%10.2f$|%-50s|\n",p.cod,p.pre,p.des);
        fread(&p,sizeof(sProducto),1,arch);
    }
    fclose(arch);
}

FILE *AbrirArchivo(char *na, char *ma){
    FILE *arch;
    arch = fopen(na, ma);
    if(arch == NULL){
        printf("ERROR - No se pudo abrir el archivo %s en modo %s.",na,ma);
        exit(1);
    }
    return arch;
}

int BuscarProducto(FILE *arch, int codBus, sProducto *prod){
    int pos = -1;
    sProducto p;
    fseek(arch, 0, 0);
    fread(&p, sizeof(sProducto),1,arch);
    while(!feof(arch) && pos == -1){
        if(p.cod == codBus){
            pos = (ftell(arch) / sizeof(sProducto)) - 1;
            *prod = p;
        }
        else
            fread(&p,sizeof(sProducto),1,arch);
    }
    return pos;
}

int IngresoEnteroVal(int li, int ls){
    int num;
    scanf("%d",&num);
    while(num < li || num > ls){
        printf("ERROR - numero invalido.");
        scanf("%d",&num);
    }
    return num;
}