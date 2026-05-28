// 4.4
// Se ingresan las ventas de un comercio de insumos de computación. Por cada venta se ingresa:
// • Número de cliente (entero de 4 dígitos no correlativos).
// • Importe (mayor a cero).
// • Número de vendedor (entero de 1 a 10).
// El ingreso de datos finaliza con un número de cliente 999.
// Se sabe que no son más de 100 clientes, la carga de los clientes se debe realizar al inicio del programa con la función CARGA_CLIENTE () y para cada uno se ingresa:
// • Código de cliente (entero de 4 dígitos no correlativos).
// • Nombre y Apellido (50 caracteres máximo).
// Se solicita:
// a. Determinar la cantidad de ventas realizadas por cliente.
// b. La cantidad de ventas realizadas por vendedor.
// c. Informar en forma ordenada por total facturado (modo descendente), el total facturado a cada cliente, informando:
#include <stdio.h>
#include <string.h>
#define CLIENTES 2
#define VENDEDORES 1

typedef struct{
    int codigo;
    char nombreC[51];
}Tcliente;

int CARGA_CLIENTE(Tcliente[], int);
int LeerEnteroValidoRango(int, int);
int BuscarCliente(Tcliente[], int, int);
void LeerTextoLimpio(char[], int);
float LeerRealPositivo();
int PosicionMax(float[], int, int);
void OrdenarClientesPorImportes(Tcliente[], float[], int);

int main(){
    Tcliente vClientes[CLIENTES];
    int mVentasPorVendedor[CLIENTES][VENDEDORES] = {{0}};
    float vClientesImportes[CLIENTES] = {0};
    int clientesCargados = CARGA_CLIENTE(vClientes,CLIENTES);
    int codCl, cliPos = 0, codVen;

    do{
        printf("\nIngrese \033[34mcodigo\033[37m del \033[34mcliente\033[37m al se realizo la venta (o \033[34m999\033[37m para finalizar el proceso): ");
        do{
            if (cliPos == -1)("\nNo se encontro un cliente con el codigo %d, vuelva a intentar: ", codCl);
            codCl = LeerEnteroValidoRango(999,9999);
            cliPos = BuscarCliente(vClientes,clientesCargados,codCl);
        }while(cliPos == -1 && codCl != 999);
        if(codCl != 999){
            printf("\nIngrese \033[34mcodigo\033[37m del \033[34mvendedor\033[37m que realizo la venta: ");
            codVen = LeerEnteroValidoRango(1,VENDEDORES);

            mVentasPorVendedor[cliPos][codVen - 1]++;
            vClientesImportes[cliPos] += LeerRealPositivo();
        }
    }while(codCl != 999);

    printf("\nA cotinuacion se listan las ventas por clientes.\nCLIENTE| N de ventas:");
    for(int i = 0; i < clientesCargados; i++){
        int ventas = 0;
        for(int j = 0; j < VENDEDORES; j++){
            ventas += mVentasPorVendedor[i][j];
        }
        printf("\n%7d| %6d"vClientes[i].codigo, ventas);
    }

    printf("\nA cotinuacion se listan las ventas por vendedor.\nVENDEDOR| N de ventas:");
    for(int j = 0; j < VENDEDORES; j++){
        int ventas = 0;
        for(int i = 0; i < clientesCargados; i++){
            ventas += mVentasPorVendedor[i][j];
        }
        printf("\n%8d| %6d",j+1,ventas);
    }

    OrdenarClientesPorImportes(vClientes,vClientesImportes,clientesCargados);
    printf("\nA cotinuacion se listan los clientes ordenados por total facturado.\nCod. Cliente| %50s| Importe facturado","Nombre y Apellido");
    for(int i = 0; i < clientesCargados; i++)printf("%8d|%51s| %8.2f$",vClientes[i].codigo,vClientes[i].nombre,vClientesImportes);
    return 0;
}

int CARGA_CLIENTE(Tcliente vClientes[], int ce){
    int i = 0, codAux;
    do{
        printf("\nIngrese el codigo del nuevo cliente");
        codAux = LeerEnteroValidoRango(999,9999);
        while(BuscarCliente(vClientes,i,codAux) != -1){
            printf("\nERROR - Ya hay un cliente registrado con el codigo %d. Ingrese un codigo distinto: ",codAux);
            codAux = LeerEnteroValidoRango(999,9999);
        }
        if(codAux != 999){
            vClientes[i].codigo = codAux;

            printf("\nIngrese el nombre del nuevo cliente");
            LeerTextoLimpio(vClientes[i].nombre,51);

            i++;
        }
    }while(codAux != 999 && i < ce);
    return i;
}

int LeerEnteroValidoRango(int li, int ls){
    int num;
    scanf("%d",&num);
    while(num < li && num > ls){
        printf("\nERROR - Se ha ingresado un numero fuera de rango. Ingrese un numero entre %d y %d: ",li,ls);
        scanf("%d",&num);
    }
    return num;
}

int BuscarCliente(Tcliente v[], int ce, int codigo){
    int pos = -1, i = 0;
    while(pos == -1 && i < ce){
        if(v[i].codigo == codigo) pos = i;
        else i++;
    }
    return pos;
}

void LeerTextoLimpio(char str[], int largo){
    int i = 0;
    getchar();
    fgets(str, largo, stdin);
    while(i < largo && str[i] != '\0'){
        if(str[i] == '\n') str[i] = '\0';
        else i++;
    }
}

float LeerRealPositivo(){
    float num;
    scanf("%f",&num);
    while(num <= 0){
        printf("ERROR - Se ha ingresado un valor no admitido. Ingrese un numero real mayor a cero: ")
        scanf("%f",&num);
    }
    return num;
}

int PosicionMax(float vIm[], int ce, int ini){
    int maxPos = ini;
    for(int i = ini + 1; i < ce; i++){
        if(vIm[maxPos] < vIm[i]) maxPos = i; 
    }
    return maxPos;
}

void OrdenarClientesPorImportes(Tcliente vCli[], float vIm[], int ce){
    Tcliente cliAux;
    float impAux;
    int maxP;
    for(int i = 0; i < ce; i++){
        maxP = PosicionMin(vIm, ce, i);

        impAux = vIm[maxP];
        vIm[maxP] = vIm[i];
        vIm[i] = impAux;

        cliAux = vCli[maxP];
        vCli[maxP] = vCli[i];
        vCli[i] = cliAux;
    }
}