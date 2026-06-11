// 6.5
// Se desea realizar un programa que permita actualizar la lista de precios de una empresa en forma individual
// a cada uno de sus productos.
// Los productos que están guardados en el archivo productos.dat con la siguiente estructura:
// • Código (entero)
// • Precio (float)
// • Descripción (de hasta 50 caracteres)
// Para modificar un precio se ingresa por teclado el código del producto y el nuevo precio. La modificación
// de precios finaliza con un código de producto igual a 0.
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int cod;
    float pre;
    char des[51];
}sProducto;


void MostrarArchivo(char*);
FILE* AbrirArchivo(char*,char*);
int BuscarRegistro(FILE*, int, sProducto*);
float IngresoRealPos();
int IngresoEnteroVal(int, int);

int main(){
    FILE *fProductos;
    sProducto prodAux;
    int codAux;
    int regPos;

    MostrarArchivo("PRODUCTOS.dat");

    fProductos = AbrirArchivo("PRODUCTOS.dat", "r+b");

    printf("Ingrese Codigo que Busca: ");
    codAux = IngresoEnteroVal(0,9999);
    while(codAux != 0){
        regPos = BuscarRegistro(fProductos, codAux, &prodAux);
        if(regPos == -1){
            printf("No encontramos ese registro.");
        }
        else{
            fseek(fProductos, sizeof(sProducto) * regPos, 0);

            printf("Ingrese nuevo precio para %s: ", prodAux.des);
            prodAux.pre = IngresoRealPos();

            fwrite(&prodAux, sizeof(sProducto), 1, fProductos);
            fflush(fProductos);
        }

        printf("Ingrese Codigo que Busca: ");
        codAux = IngresoEnteroVal(0,9999);
    }

    fclose(fProductos);

    MostrarArchivo("PRODUCTOS.dat");

    return 0;
}

FILE* AbrirArchivo(char* na, char* ma){
    FILE *arch;
    arch = fopen(na, ma);

    if(arch == NULL){
        printf("El archivo %s no pudo abrirse en el modo %s.", na, ma);
        exit(1);
    }

    return arch;
}

void MostrarArchivo(char *na){
    FILE *arch;
    sProducto p;

    arch = fopen(na, "rb");
    if(arch == NULL){
        printf("El archivo %s no pudo abrirse para su lectura.", na);
        exit(1);
    }

    fread(&p, sizeof(sProducto), 1, arch);
    while(!feof(arch)){
        printf("%d|%10.2f|  %-50s\n", p.cod, p.pre, p.des);
        fread(&p, sizeof(sProducto), 1, arch);
    }

    fclose(arch);
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

int BuscarRegistro(FILE *arch, int code, sProducto *dirProdAux){
    sProducto aux;
    int pos = -1;
    fseek(arch, 0, 0);
    fread(&aux, sizeof(sProducto), 1, arch);
    while(!feof(arch) && pos == -1){
        // printf("Buscamos %d y este es %d\n", aux.cod, code);
        if(aux.cod == code){
            pos = (ftell(arch)/sizeof(sProducto)) - 1;
            *dirProdAux = aux;
        }
        else
            fread(&aux, sizeof(sProducto), 1, arch);
    }
    return pos;
}

float IngresoRealPos(){
    float num;
    scanf("%f",&num);
    while(num <= 0){
        printf("ERROR - real no positivo.");
        scanf("%f",&num);
    }
    return num;
}