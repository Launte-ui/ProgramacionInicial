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

void CargarVectorEnCero(int vecX[], int ce);
int CargarVectores(int[],int[],int[],int[]);
int CargarVectores(int vCodigos[],int vDepositos[],int vStock[],int vReposicion[]);
int IngreseIntMayorA0();
int IngreseIntRango(int,int);
int BuscarEnVector(int[],int,int);
void CargasDeMovimientos( int[], int);
int BuscarPosEnVector(int[],int,int);

int main()
{
    int vCodigos[300], vDepositos[300], vStock[300], vReposicion[300];
    int cantElementos;
    CargarVectorEnCero(vStock,300);
    cantElementos = CargarVectores(vCodigos,vDepositos,vStock,vReposicion);
    if(cantElementos>0){
        CargasDeMovimientos(vStock,cantElementos);
    }
    MostrarDatosCompletos(vCodigos, vDepositos, vStock, vReposicion,cantElementos);
    return 0;
}

void CargarVectorEnCero(int vecX[], int ce){
    for (int i = 0; i < ce; i++)
        vecX[i] = 0;
}

int CargarVectores(int vCodigos[],int vDepositos[],int vStock[],int vReposicion[]){
    int i=0;
    int dato;
    printf("Ingrese codigo del articulo: ");
    dato = IngreseIntMayorA0();

    while(dato != 0 && i < 300){
        int flag = 0;
        vCodigos[i] = dato;
        printf("Ingrese el deposito del articulo: ");
        vDepositos[i] = IngreseIntRango(1,20);
        printf("Ingrese el stock del articulo: ");
        vStock[i] = IngreseIntRango(0,2000);
        printf("Ingrese el punto de reposicion del articulo: ");
        vReposicion[i] = IngreseIntRango(500,1000);
        i++;
        printf("Ingrese codigo del articulo: ");
        while(flag>=0 && i<300){
            dato = IngreseIntMayorA0();
            flag = BuscarEnVector(vCodigos, i, dato);
            if (flag>=0)
                printf("ERROR-El codigo ya a sido registrado, ingrese un codigo distinto: ");
        }
    }
    return i;
}

int IngreseIntMayorA0()
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

void MostrarDatosCompletos(int vCodigos[], int vDeposito[], int vStock[], int vReposicion[],int ce){
    printf("\nCada operario fabrico la siguiente cantidad de muebles:");
    printf("\nCODIGO DEL OPERARIO:\t\tDEPOSITO DEL ARTICULO:\t\tSTOCK DEL ARTICULO:\t\tPUNTO DE REPOSICION:");
    for(int i = 0; i < ce;i++){
        printf("\n%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d",vCodigos[i],vDeposito[i],vStock[i],vReposicion[i]);
    }
}

void CargasDeMovimientos(int vStock[], int ce){
    int codigo, pos, cant;
    char op;
    codigo = IngreseIntMayorA0();
    while(codigo!=0){
        pos = BuscarPosEnVector(vStock,ce,codigo);
        printf("Ingrese cantidad del articulo: ");
        cant = IngreseIntMayorA0();
        op = IngreseOpcionVal();
        if(op == 'I'){
            vStock[pos]+=cant;
        }
        else{
            vStock[pos]-=cant;
        }
    }
    int pos = BuscarPosEnVector(vStock,codigo,ce);

}

int BuscarPosEnVector(int vecX[],int ce,int intABuscar){
    int pos;
    for (int i = 0; i < ce; i++)
        if(vecX[i]==intABuscar)
            pos = i;
    return pos;
}

char IngreseOpcionVal(){
    char op;
    printf("'I' para Ingreso - 'E' para Egreso");
    do
    {
        scanf("%c",&op);
    } while (op != 'I' && op != 'E');
    return op;
}
