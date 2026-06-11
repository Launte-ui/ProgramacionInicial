// 6.7
// Se dispone de un archivo llamado Stock.dat que contiene la información de los productos que vende una
// fábrica. En el archivo se guarda:
// • Código de artículo (entero)
// • Descripción (50 caracteres máximo)
// • Stock (entero)
// Luego se ingresan por teclado las ventas a realizar indicando:
// • Código de artículo
// • Cantidad
// La carga por teclado de las ventas finaliza con un código de artículo igual a 0.
// Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar el stock de dicho producto, sino
// hay stock se debe vender lo que quede disponible y grabar un registro en un archivo Faltantes.dat con la
// cantidad que no pudo venderse, dicho registro debe contener:
// • Código de artículo
// • Cantidad faltante
// Si ya hay un registro previo en dicho archivo de faltantes con el mismo producto debe incrementarse la
// cantidad.
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int cod;
    char des[51];
    int stock; 
}sProducto;

typedef struct{
    int cod;
    int cant;
}sFaltante;

void MostrarProductos(char*);
void MostrarFaltantes(char*);
FILE *AbrirArchivo(char*, char*);
int BuscarProducto(FILE*, int, sProducto*);
int IngresoEnteroVal(int, int);
int IngresoEnteroPos();
int BuscarFaltante(FILE*, int, sFaltante*);

int main(){
    FILE *fProds;
    FILE *fFals;
    sProducto prodAux;
    sFaltante falAux;
    int prodPos, falPos, codAux, stockVen;

    MostrarProductos("STOCK.dat");
    fProds = AbrirArchivo("STOCK.dat", "r+b");
    fFals = AbrirArchivo("FALTANTE.dat", "r+b");

    printf("INGRESE CODIGO DEL PRODUCTO A VENDER: ");
    codAux = IngresoEnteroVal(0,9999);
    while(codAux != 0){
        prodPos = BuscarProducto(fProds, codAux, &prodAux);
        if(prodPos != -1){
            fseek(fProds, sizeof(sProducto) * prodPos, 0);
            printf("Ingrese cantidad a vender: ");
            stockVen = IngresoEnteroPos();
            if(prodAux.stock >= stockVen){
                prodAux.stock -= stockVen;
                fwrite(&prodAux, sizeof(sProducto), 1, fProds);
            }
            else{
                falPos = BuscarFaltante(fFals, codAux, &falAux);
                if(falPos == -1){
                    fseek(fFals, 0, 2);
                    falAux.cod = codAux;
                    falAux.cant = stockVen - prodAux.stock;
                    fwrite(&falAux, sizeof(sFaltante), 1, fFals);
                    prodAux.stock = 0;
                    fwrite(&prodAux, sizeof(sProducto),1, fProds);
                }
                else{
                    fseek(fFals, sizeof(sFaltante) * falPos, 0);
                    falAux.cant += stockVen;
                    fwrite(&falAux, sizeof(sFaltante), 1, fFals);
                    prodAux.stock = 0;
                    fwrite(&prodAux, sizeof(sProducto), 1, fProds);
                }
            }
        }
        else
            printf("No se encontro el producto pedido.\n");
        printf("INGRESE CODIGO DEL PRODUCTO A VENDER: ");
        codAux = IngresoEnteroVal(0,9999);
    }

    fclose(fFals);
    fclose(fProds);
    
    printf("\n");
    MostrarProductos("STOCK.dat");
    printf("\n");
    MostrarFaltantes("FALTANTE.dat");
    return 0;
}

void MostrarProductos(char *na){
    FILE *arch;
    arch = fopen(na,"rb");
    sProducto p;
    if(arch == NULL){
        printf("NO SE PUDO ABRIR %s PARA SU LECTURA.", na);
        exit(1);
    }
    fread(&p, sizeof(sProducto),1,arch);
    while(!feof(arch)){
        printf("%d|%51s|%3d\n",p.cod,p.des,p.stock);
        fread(&p, sizeof(sProducto),1,arch);
    }
    fclose(arch);
}

void MostrarFaltantes(char *na){
    FILE *arch;
    arch = fopen(na,"rb");
    sFaltante p;
    if(arch == NULL){
        printf("NO SE PUDO ABRIR %s PARA SU LECTURA.", na);
        exit(1);
    }
    fread(&p, sizeof(sFaltante),1,arch);
    while(!feof(arch)){
        printf("%d|%3d\n",p.cod,p.cant);
        fread(&p, sizeof(sFaltante),1,arch);
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

int IngresoEnteroPos(){
    int num;
    scanf("%d",&num);
    while(num <= 0){
        printf("ERROR - numero invalido.");
        scanf("%d",&num);
    }
    return num;
}

int BuscarFaltante(FILE *arch, int codBus, sFaltante *falt){
    int pos = -1;
    sFaltante f;
    fseek(arch, 0, 0);
    fread(&f, sizeof(sFaltante), 1, arch);
    while(!feof(arch) && pos == -1){
        if(f.cod == codBus){
            pos = (ftell(arch)/sizeof(sFaltante)) - 1;
            *falt = f;
        }
        else
            fread(&f, sizeof(sFaltante), 1, arch);
    }
    return pos;
}