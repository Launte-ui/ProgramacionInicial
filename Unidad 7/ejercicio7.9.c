/*Una empresa de venta de artículos de limpieza trabaja con 300 artículos diferentes. Al comenzar
el programa se ingresa el estado del stock hasta el momento. De cada artículo se ingresa los
siguientes datos:
• Código de artículo (entero, mayor a cero).
• Número de depósito donde se encuentra el artículo (entero, entre 1 y 20).
• Stock (entero, entre 0 y 2000).
• Punto de reposición (entero, entre 500 y 1000).
Luego se procesan los movimientos del mes en el stock: egresos (resta al stock) e ingresos (suma
al stock). Por cada movimiento se ingresa:
• Código del artículo
• Código del movimiento (carácter, ‘I’: ingreso a stock - suma; ‘E’: egreso de stock -
resta)
• Cantidad ingresada / egresada (entero, mayor a cero)
La carga de movimientos finaliza con un código de artículo igual a cero.
Se pide informar lo siguiente:
a. El detalle de la cantidad de artículos en stock, informando código y existencia.
b. El porcentaje de artículos que hayan quedado con el stock igual a cero.
c. Los códigos de artículos que hayan quedado con stock por debajo del punto de
reposición.
d. Cuántos depósitos tuvieron movimientos de egreso durante el mes.
NOTA: Se permite que el stock pueda quedar negativo, de artículos vendidos pero pendiente
de ingreso al stock.*/

#include <stdio.h>

int CargarVectores(int[],int[],int[],int[]);

int main()
{
    int vCodigos[300], vDepositos[300], vStock[300], vReposicion[300];
    int cantElementos;
    CargarVectorEnCero(vStock);
    cantElementos = CargarVectores(vCodigos,vDepositos,vStock,vReposicion);
    return 0;
}

void CargarVectorEnCero(int vecX[], int ce){
    for (int i = 0; i < ce; i++)
        vecX[i] = 0;
}

int CargarVectores(int vCodigos[],int vDepositos[],int vStock[],int vReposicion[]){
    int i=0;
    int dato;
    dato = IngreseFloatMayorA0();
    while(dato!=0&&i<300){
        int flag = -1;
        vCodigos[i] = dato;
        vDepositos = IngreseIntRango(1,20);
        vStock = IngreseIntRango(0,2000);
        vReposicion = IngreseIntRango(500,1000);

        dato = IngreseFloatMayorA0();
        while(flag<0 && i<300){
            flag = BuscarEnVector(vCodigos, i, dato);
            if (flag>=0){
                printf("ERROR-El codigo ya a sido registrado, ingrese un codigo distinto: ");
                flag = BuscarEnVector(vCodigos, i, dato);
            }
        }
    }
    return i;
}

int IngreseFloatMayorA0()
{
    int n;
    scanf("%d",&n);
    while(n<0)
    {
        printf("ERROR-El numero debe ser mayor a 0- ingrese 0 para finalizar: ");
        scanf("%d",&n);
    }
    return n;
}


int IngreseIntRango(int lim_menor,int lim_mayor)
{
    int n;
    scanf("%d",&n);
    while(n<lim_menor || n>lim_mayor)
    {
        printf("ERROR-El numero debe estar entre el valor %d a %d: ",lim_menor,lim_mayor);
        scanf("%d",&n);
    }
    return n;
}

int BuscarEnVector(int vecX[],int ce,int intABuscar){
    int cantNumerosENcontrados = -1;
    for (int i = 0; i < ce; i++)
        if(vecX[i]==intABuscar)
            cantNumerosENcontrados++;
    return cantNumerosENcontrados;
}