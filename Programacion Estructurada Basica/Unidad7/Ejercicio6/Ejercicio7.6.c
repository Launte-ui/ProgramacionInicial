// 7.6 
// Dado un archivo ventas.csv con ventas de productos que contiene producto;precio;cantidad;sucursal siendo
// • Producto un string correspondiente al código de producto de máximo 10 caracteres
// • Precio un valor real con el precio unitario el producto
// • Cantidad la cantidad de productos vendida (entero)
// • Sucursal, el código la sucursal de la venta (entero)
// Calcular:
// • La cantidad total de ventas realizadas
// • La cantidad total de productos vendidos
// • El importe total vendido por cada sucursal (usar un vector dinámico en memoria que pueda ir
// creciendo para guarda estar información)
// • Generar un archivo resumenVenta.txt que contenga, la información de los 3 items anteriores
// Nota: para realizar los cálculos debe recuperar cada registro del archivo y pasarlo a una estructura en memoria
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char prod[10];
    float pre;
    int cant;
    int suc;
}tVenta;

typedef struct{
    int cantVent;
    int cantProd;
    float impTotal;
}tResumen;

FILE* AbrirArchivo(char*, char*);
void CompletarCampo(tVenta*, char*, int);
tVenta ParsearLineaAVenta(char*);
void OrdenarVentas(tVenta*, int);
void CargarResumenes(tVenta*, int);

int main(){
    FILE *fVentas;
    char linea[999];
    tVenta ventaAux;
    int cantVentas = 0;
    tVenta *vVentas;

    vVentas = (tVenta*)malloc(0 * sizeof(tVenta));
    if(vVentas == NULL){
        printf("No se pudo asignar memoria para el vector de ventas.\n");
        exit(1);
    }

    fVentas = AbrirArchivo("VENTAS.csv", "rt");
    fgets(linea, sizeof(linea), fVentas);
    while(!feof(fVentas)){
        cantVentas++;
        vVentas = realloc(vVentas, cantVentas * sizeof(tVenta));
        if(vVentas ==  NULL){
            printf("No se pudo redimensionar el vector de ventas.\n");   
            exit(1);
        }
        ventaAux = ParsearLineaAVenta(linea);
        *(vVentas + (cantVentas-1)) = ventaAux;
        fgets(linea, sizeof(linea), fVentas);
    }
    fclose(fVentas);

    

    CargarResumenes(vVentas, cantVentas);

    free(vVentas);
    vVentas = NULL;

    return 0;
}

FILE* AbrirArchivo(char *na, char *ma){
    FILE *arch;
    arch = fopen(na, ma);
    if(arch == NULL){
        printf("Fatala error.");
        exit(1);
    }
    return arch;
}

void CompletarCampo(tVenta *venta, char *parte, int campo){
    switch (campo){
    case 0:
        strcpy(venta->prod, parte);
        break;
    case 1:
        venta->pre = atof(parte);
        break;
    case 2:
        venta->cant = atoi(parte);
        break;
    case 3:
        venta->suc = atoi(parte);
        break;
    default:
        printf("Ocurrio un error en el parseo de la linea.\n");
        break;
    }
}

tVenta ParsearLineaAVenta(char *linea){
    tVenta ventaAux;
    int campo = 0;
    char *parte;
    // printf("%s",linea);
    parte = strtok(linea, ";");
    // printf("print de debug\n");
    while(parte != NULL){
        CompletarCampo(&ventaAux,parte,campo);
        // printf("%s|%d\n",parte,campo);
        parte = strtok(NULL, ";");
        campo++;
    }
    return ventaAux;
}

void OrdenarVentas(tVenta *v, int ce){
    tVenta ventaAux;
    for(int i = 0; i < ce; i++){
        for(int j = 0; j < ce - i -1; j++){
            if((v+j)->suc >= (v+j+1)->suc){
                ventaAux = *(v+j+1);
                *(v+j+1) = *(v+j);
                *(v+j) = ventaAux;
            }
        }
    }
}

void CargarResumenes(tVenta *v, int ce){
    FILE *fResumen;
    fResumen = AbrirArchivo("RESUMENVENTA.txt","wb");

    OrdenarVentas(v,ce);

    int sucActual, i = 0;
    while(i < ce){
        int cantVentas = 0;
        int cantProductos = 0;
        float importTotal = 0;
        
        sucActual = (v+i)->suc;
        while((v+i)->suc == sucActual && i<ce){
            cantVentas++;
            cantProductos += (v+i)->cant;
            importTotal += (v+i)->pre;
            i++;
        }
        
        fprintf(fResumen,"%d;%d;%d;%.2f\n",sucActual,cantVentas,cantProductos,importTotal);
    }

    fclose(fResumen);
}