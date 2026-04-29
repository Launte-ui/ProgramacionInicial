// 4.1
// Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes de sus productos. Para ello primeramente se ingresan la información de los productos formados por:
// Código (5 caracteres).
// Precio (real).
// Descripción (30 caracteres).
// Cantidad de unidades vendidas (al mes anterior, entero).
// Importe Total Vendido (al mes anterior, real).
// Se sabe que la empresa no vende más de 50 productos.
// El ingreso de la carga de productos finaliza con un producto con descripción “FIN”.
// Luego ingresan las ventas del mes:
// Código de Producto (5 caracteres).
// Cantidad pedida.
// El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
// a. Actualizar la información de los productos con las ventas realizadas en el mes.
// b. Al finalizar, mostrar el listado de productos actualizado, informando:

#include <stdio.h>
#include <string.h>
#define CANT 50 

struct PRODUCTO {
    char codigo[6];
    float precio;
    char descripcion[31];
    int unVendidas;
    float impTotal;
};

void PrintProducto(PRODUCTO);
struct PRODUCTO SetProductoNull();

int main(){
    struct PRODUCTO vProductos[CANT];
    char desAux[31], codAux[6];
    float preAux, impAux;
    int unAux, repito, j = 0;
    for(int i = 0; i < CANT; i++)vProductos[i] = SetProductoNull();
    
    do{
        LeerTextoLimpio(desAux,31);
        repito = strcmpi(desAux, "fin");
        if(repito){
            strcpy(vProductos[j].descripcion,desAux);
            j++;
        }
        //puts(desAux);
        j++;
    }while(repito && j < CANT);
    // int prodPos = BusquedaBinariaStr(vProductos, "bbbbb", CANT);
    // if(prodPos!=-1) PrintProducto(vProductos[prodPos]);
    // else printf("Que decis pa?");
    for(int i = 0; i < CANT; i++)    {
        PrintProducto(vProductos[i]);
        printf("\n");
    }
    return 0;
}

void PrintProducto(struct PRODUCTO prod){
    printf("Codigo: %s| Precio: %4.2f$| Descripcion: %s",prod.codigo, prod.precio, prod.descripcion);
}

struct PRODUCTO SetProductoNull(){
    struct PRODUCTO nullProduct;
    strcpy(nullProduct.codigo,"aaaaa");
    nullProduct.precio = 0;
    strcpy(nullProduct.descripcion,"Undefined");
    nullProduct.unVendidas = 0;
    nullProduct.impTotal = 0;

    return nullProduct;
}

void LeerTextoLimpio(char str[], int largo){
    int i = 0;
    fgets(str, largo,stdin);
    while(str[i] != '\0'){
        if(str[i] == '\n') str[i] = '\0';
        else i++;
    }
}

int BusquedaBinariaStr(struct PRODUCTO vProd[], char elemento[], int ce){
    int pos = -1, med, cmp;
    int li = 0, ls = ce -1;
    while(li<=ls && pos == -1){
        med = (li+ls)/2;
        cmp = strcmpi(elemento,vProd[med].codigo);
        if(!cmp) pos = med;
        else if(cmp < 0) li = med + 1;
        else ls = med - 1;
    }
    return pos;
}