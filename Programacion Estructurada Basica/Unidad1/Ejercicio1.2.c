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


int main()
{
    int codigos[MAX_PRODUCTOS];
    int cantidad[MAX_PRODUCTOS] = {0};
    srand(time(NULL));
    IngresaCodigos(codigos, MAX_PRODUCTOS);
    printf("ID \t| Cod\t| Cant\n");
    int codigo, cant;
    do
    {
        int noEncontrado = 1;
        for(int i = 0; i < MAX_PRODUCTOS; i++){
            printf("%d\t| %d\t| %d\n",i, codigos[i], cantidad[i]);
        }
        printf("Ingrese el codigo del producto (0 para finalizar): ");
        scanf("%d", &codigo);
        if(codigo != 0){
            for(int i = 0; i < MAX_PRODUCTOS; i++){
                if(codigos[i] == codigo){
                    noEncontrado = 0;
                }
            }
            if(noEncontrado){
                printf("Producto no encontrado.\n");
            }
            else{
                printf("Ingrese la cantidad de unidades solicitadas: ");
                scanf("%d", &cant);
                for(int i = 0; i < MAX_PRODUCTOS; i++){
                    if(codigos[i] == codigo){
                        cantidad[i] += cant;
                    }
                }
            }
        }
    } while (codigo != 0);
    return 0;
}

void IngresaCodigos(int codigos[], int ce){
    int codigo;
    for(int i = 0; i < ce; i++){
        do{
            codigo = NumAleatorio(1000, 10000);
        } while(Repetido(codigos, ce, codigo));
        codigos[i] = codigo;
    }
    printf("Codigos ingresados:\n");
}

int Repetido(int codigos[], int ce, int codigo){
    int flag = 0;
    for(int i = 0; i < ce; i++){
        if(codigos[i] == codigo){
            flag = 1;
        }
    }
    return flag;
}

int NumAleatorio( int min,int max){
        int num = min + (rand() % (max - min));
        return num;
}

