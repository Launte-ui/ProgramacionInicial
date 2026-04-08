// 1.2
// Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día.
// Cada producto está identificado por un código de 4 cifras.
// Los códigos deben ingresarse al inicio del programa mediante la función IngresaCódigos y no pueden repetirse.
// Por cada pedido se recibe:
// • Código de producto
// • Cantidad de unidades solicitadas
// Se puede recibir más de un pedido por producto.
// La carga de pedidos finaliza cuando se ingresa un producto igual a 0
// Al finalizar se debe:
// a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
// b) El / los productos del cual se solicitaron mayor cantidad de unidades.
// c) El / los productos del cual se solicitaron menos cantidad de unidades.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRODUCTOS 10

void IngresaCodigos(int [], int);
int Repetido(int [], int, int);
int NumAleatorio(int, int);
int BuscarMinYMax(int [], int, int);


int main()
{
    int codigos[MAX_PRODUCTOS];
    int cantidades[MAX_PRODUCTOS] = {0};
    srand(time(NULL));
    IngresaCodigos(codigos, MAX_PRODUCTOS);
    printf("ID \t| Cod\t| Cant\n");
    int codigo, cant;
    do
    {
        int posicionElemento = -1;
        for(int i = 0; i < MAX_PRODUCTOS; i++){
            printf("%d\t| %d\t| %d\n",i, codigos[i], cantidades[i]);
        }
        printf("Ingrese el codigo del producto (0 para finalizar): ");
        scanf("%d", &codigo);
        if(codigo != 0){
            for(int i = 0; i < MAX_PRODUCTOS; i++){
                if(codigos[i] == codigo){
                    posicionElemento = i;
                }
            }
            if(posicionElemento == -1){
                printf("Producto no encontrado.\n");
            }
            else{
                printf("Ingrese la cantidades de unidades solicitadas: ");
                scanf("%d", &cant);
                cantidades[posicionElemento] += cant;
            }
        }
    } while (codigo != 0);
    int minPos = BuscarMinYMax(cantidades, MAX_PRODUCTOS,0);
    int maxPos = BuscarMinYMax(cantidades, MAX_PRODUCTOS,1);
    printf("Producto/s con menor cantidad de unidades solicitadas: ");
    BuscarYMostrarCodigoPorCantidad(cantidades, codigos, MAX_PRODUCTOS, cantidades[minPos]);
    printf("Producto/s con mayor cantidad de unidades solicitadas: ");
    BuscarYMostrarCodigoPorCantidad(cantidades, codigos, MAX_PRODUCTOS, cantidades[maxPos]);
    return 0;
}

void IngresaCodigos(int codigos[], int ce){
    int codigo;
    for(int i = 0; i < ce; i++){
        do{
            codigo = NumAleatorio(1000, 10000);
        } while(Repetido(codigos, i, codigo) == 0);
        codigos[i] = codigo;
    }
    printf("Codigos ingresados:\n");
}

int Repetido(int codigos[], int ce, int codigo){
    int pos = -1, i = 0;
    // for(int i = 0; i < ce; i++){
    //     if(codigos[i] == codigo){
    //         pos = 1;
    //     }
    // }
    while(pos == -1 && i < ce){
        if (codigos[i] == codigo) pos = i;
        else i++;
    }
    return pos;
}

int NumAleatorio( int min,int max){
        int num = min + (rand() % (max - min));
        return num;
}


int BuscarMinYMax(int v[], int ce, int opcion){
    
    int referencia = v[0];
    int pos = 0;
    for(int i = 1; i < ce; i++){
        if(opcion == 0){
            if(v[i] < referencia){
                referencia = v[i];
                pos = i;
            }
        }
        else{
            if(v[i] > referencia){
                referencia = v[i];
                pos = i;
            }
        }
    }
    return pos;
}

void BuscarYMostrarCodigoPorCantidad(int cant[], int cod[], int ce, int elemento){
    for(int i = 0; i < ce; i++){
        if(cant[i] == elemento){
            printf("%d \n", cod[i]);
        }
    }
}
