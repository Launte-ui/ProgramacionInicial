/*Una empresa de alquiler de autos tiene una flota de 30 autos de alta gama, identificados cada
uno con código. Como primera acción, se ingresan por teclado los siguientes datos:
• Código del auto (entero, mayor a cero)
• Precio diario del alquiler en dólares (real, mayor que cero)
Al comenzar el procesamiento de los alquileres, se ingresa la fecha del día y la cotización del
dólar de ese día. A continuación, se ingresan los siguientes datos correspondiente a cada
alquiler realizado en el día:
• Código del auto
• Cantidad de días de alquiler (entero, mayor que cero)
 Para finalizar la carga del día, se ingresa un código de auto igual a cero.
 Determinar e informar:
a. Porcentaje de vehículos alquilados durante el día.
b. Informar la siguiente planilla:
ALQUILERES DE AUTOS DEL DÍA*/

#include <stdio.h>

void CargarVector(int[],float[], int[]);
int IngreseEntero();
float IngresePrecio();
int BuscarIntVector(int[],int,int);


int main()
{
    int vCodigo[30], vDias[30];
    float vPrecio[30], vAlquiler[30];
    int vFecha[3];
    CargarVectorEnCero(vFecha,0);
    CargarVectorEnCero(vAlquiler,0);
    CargarVectorEnCero(vPrecio,0);
    CargarVectorEnCero(vDias,0);
    CargarVectorEnCero(vCodigo,0);
    CargarVector(vCodigo, vPrecio, vFecha);
    CargarAlquileres(vCodigo, vPrecio, vDias, vAlquiler);
    MostrarDatos(vCodigo,vDias,vPrecio,vFecha,vAlquiler);
    return 0;
}

void CargarVectorEnCero(int vecX[], int ce){
    for (int i = 0; i < ce; i++)
        vecX[i] = 0;
}

void CargarVector(int vCodigos[], float vPrecios[], int vFechas[]){
    int i = 0;
    int f = 0;
    int fecha = 1;
    int flag;
    int codigo;
    do
    {
        if(!fecha)
            printf("Fecha invalida: ");
        for (int j = 0; j < 3; j++)
        {
            printf("Ingrese fecha: ");
            vFechas[j] = IngreseEntero();
        }
        fecha = ValidarFecha( vFechas[0], vFechas[1], vFechas[2]);
    } while (!fecha);

    printf("Ingrese Codigo del auto: ");
    codigo = IngreseEntero();
    while(i<1){
        vCodigos[i] = codigo;
        printf("Ingrese el precio diario: ");
        vPrecios[i] = IngresePrecio();
        i++;
        printf("Ingrese Codigo de otro auto: ");
        do{
            codigo = IngreseEntero();
            flag = BuscarIntVector(vCodigos,i,codigo);
            if(flag>=0)
                printf("ERROR-El codigo ya a sido registrado, ingrese un codigo distinto: ");
        }while(flag>=0);
    }
}

int IngreseEntero()
{
    int n;
    scanf("%d",&n);
    while(n<=0)
    {
        printf("ERROR-El numero debe ser mayor a 0: ");
        scanf("%d",&n);
    }
    return n;
}

float IngresePrecio()
{
    float n;
    scanf("%f",&n);
    while(n<=0)
    {
        printf("ERROR-El numero debe ser mayor a 0: ");
        scanf("%f",&n);
    }
    return n;
}

int BuscarIntVector(int vecX[],int ce,int intABuscar){
    int cantNumerosENcontrados = -1;
    for (int i = 0; i < ce; i++)
        if(vecX[i]==intABuscar)
            cantNumerosENcontrados++;
    return cantNumerosENcontrados;
}

void CargarAlquileres(int vCodigo[], float vAlquiler[], int vDias[], float vPrecios[]){
    int codigo;
    int pos;
    printf("Ingrese Codigo del auto: ");
    codigo = IngreseIntMayorA0();
    while(codigo!=0){
        pos = BuscarPosEnVector(vCodigo,30,codigo);
        if(pos <0){
            printf("No hay un auto con ese codigo.\n");
        }
        else{
            printf("Ingrese la cantiadad de dias que se alquila el auto: ");
            vDias[pos] = IngreseEntero();
            vAlquiler[pos] = vDias[pos] * vPrecios[pos];
            printf("Ingrese Codigo de otro auto: ");
        }
        codigo = IngreseIntMayorA0();
    }
}

int ValidarFecha(int d, int m, int a){
    int val = 0;
    if(a >= 1582){
        if(m > 0 && m < 13){
            if(d > 0 && d < DiasDelMes(m,a)){
                val = 1;
            }
        }
    }
    return val;
}

int DiasDelMes(int m, int a){
    int cdm;
    if(m == 4 ||m == 6 ||m == 9 ||m == 11){
        cdm = 30;
    }
    else{
        if(m == 2)
            cdm = 28 + Bisiesto(a);
        else
            cdm = 31;
    }
    return cdm;
}

int Bisiesto(int a){
    int b;
    if(a%4==0 && a%100!=0 || a%400)
        b = 1;
    else
        b = 0;
    return b;
}

int BuscarPosEnVector(int vecX[],int ce,int intABuscar){
    int pos = -1;
    for (int i = 0; i < ce; i++)
    {
        if(vecX[i]==intABuscar)
            pos = i;
    }
    return pos;
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

void MostrarDatos(int vCodigos[], int vDias[], float vPrecio[], int vFechas[], float vAlquiler[]){
    printf("\nCODIGO\t\t\tDIAS ALQUILADOS\t\t\tPRECIO DEL ALQUILER\t\t\tFECHA DE DEVOLUCION");
    for (int i = 0; i < 30; i++)
    {
        printf("\n%d\t\t\t%d\t\t\t%f\t\t\t",vCodigos[i],vDias[i],vPrecio[i]);
        CorregirFecha(vDias[i],vFechas);
    }
    
}

void CorregirFecha(int dias, int vFechas[]){
    int d,m,a;
    m = vFechas[1];
    a = vFechas[2];
    d = vFechas[0] + dias;
    while(d>DiasDelMes(m,a)){
        d-=DiasDelMes(m,a);
        m++;

    }
    while(m>12){
        m-=12;
        a++;
    }
    printf("%d/%d/%d",d,m,a);
}