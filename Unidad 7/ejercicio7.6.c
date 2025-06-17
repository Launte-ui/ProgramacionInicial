/*7.6 Una f�brica produce 14 tipos de muebles de oficina con la mano de obra de 25 operarios
especializados. Al finalizar el mes se genera una planilla, donde cada registro indica:
� D�a h�bil del mes de fabricaci�n (entero, de 1 a 22)
� Tipo de mueble que se fabric� (entero, de 1 a 14)
� C�digo del operario que fabric� el mueble (entero, de 1 a 25)
En la �ltima informaci�n se ingres� un d�a h�bil negativo. No hay orden alguno en los datos
ingresados y un mismo operario puede hacer m�s de un mueble (del mismo tipo o no, en el
mismo d�a o distintos d�as) durante el mes.
Determinar e informar:
a) La cantidad de cada tipo de mueble fabricado durante el mes.
b) Tipo de mueble del cual se ha fabricado la mayor cantidad. (puede haber m�s de
uno).
c) Listado de cantidad de muebles fabricados por operario (sin importar el tipo),
indicando:
C�digo de operario Cantidad de muebles fabricada
d) D�a o d�as h�bil/es en los cuales no hubo nada de producci�n.
*/

#include<stdio.h>

void CargarVectIntEnCero(int[],int);
int LeeryValidarIntRango(int,int);
int LeeryValidarIntRangoCFMENOR(int,int,int);
int LeeryValidarInt(int);
void MostrarMuebles(int[]);
int MuebleMayorCant(int[]);
void MostrarMuebleMayorCant(int[], int);
void MostrarMueblesPorOperario(int[]);
void MostrarDiasSinProduccion(int[]);

int MesTrabajo(int[],int[],int[],int,int,int);



int main()
{
    int Cant_Dias=0;
    int vDias[22],vMuebles[14],vEmpleado[25];
    int mayorCant;
    CargarVectIntEnCero(vDias,22);
    CargarVectIntEnCero(vMuebles,14);
    CargarVectIntEnCero(vEmpleado,25);
    puts("Bienvenido al codigo de la actividad 6");
    Cant_Dias=MesTrabajo(vDias,vMuebles,vEmpleado,22,14,25);


    if(Cant_Dias>0){
        MostrarMuebles(vMuebles);
        mayorCant = MuebleMayorCant(vMuebles);
        MostrarMuebleMayorCant(vMuebles, mayorCant);
        MostrarMueblesPorOperario(vEmpleado);
        MostrarDiasSinProduccion(vDias);
    }
    else printf("\nNo se trabajo ningun dia");
    return 0;
}

void CargarVectIntEnCero(int v1[],int lim)
{
    for(int i=0;i<lim;i++)v1[i]=0;
}

int LeeryValidarIntRango(int lim_menor,int lim_mayor)
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

int LeeryValidarIntRangoCFMENOR(int lim_menor,int lim_mayor,int excepcion)
{
    int n;
    scanf("%d",&n);
    while((n<lim_menor || n>lim_mayor) && n>=excepcion)
    {
        printf("ERROR-El numero debe estar entre el valor %d a %d- ingrese un numero menor a %d para terminar: ",lim_menor,lim_mayor,excepcion);
        scanf("%d",&n);
    }
    return n;
}

int LeeryValidarInt(int lim)
{
    int n;
    scanf("%d",&n);
    while(n<lim)
    {
        printf("ERROR- Ingrese un valor mayor a %d: ",lim);
        scanf("%d",&n);
    }
    return n;
}

int MesTrabajo(int VD[],int VM[],int VE[],int fecha_lim,int mueble_limite,int empleado_limite)
{
    int i=0;
    int Dia,Mueble,Codigo_Empleado,Cant_Mueble;
    printf("\nIngrese el dia- Numero Negativo para terminar:\t");
    Dia=LeeryValidarIntRangoCFMENOR(1,22,0);
    while(Dia>0)
    {
        printf("\nIngrese el codigo del empleado:\t");
        Codigo_Empleado=LeeryValidarIntRango(1,25);
        printf("\nIngrese el tipo de mueble:\t");
        Mueble=LeeryValidarIntRango(1,14);
        printf("\nCuantos muebles hizo?:\t");
        Cant_Mueble=LeeryValidarInt(0);
        VM[Mueble-1]+=Cant_Mueble;
        VE[Codigo_Empleado-1]+=Cant_Mueble;
        VD[Dia-1]++;
        i++;
        printf("\nIngrese el dia- Numero negativo para terminar:\t");
        Dia=LeeryValidarIntRangoCFMENOR(1,22,0);
    }
    return i;
}

void MostrarMuebles(int vecX[]){
    puts("Se han fabricado las siguientes cantidades de cada tipo de mueble:");
    for(int i = 0; i < 14;i++){
        printf("\nTIPO: %d CANTIDAD: %d",i+1,vecX[i]);
    }
}

int MuebleMayorCant(int vecX[])
{
    int max = vecX[0];
    for (int i = 1; i < 14; i++){
        if(vecX[i]>max)
            max = vecX[i];
    }
    return max;
}

void MostrarMuebleMayorCant(int vecX[], int max){
    printf("\nLa maxima cantidad de muebles que se hizo de un tipo de mueble fue %d y se hizo de los muebles de tipo: ",max);
    for(int i = 0;i < 14;i++){
        if(vecX[i]== max)
            printf("%d, ", i+1);
    }
}



void MostrarMueblesPorOperario(int vecX[]){
    printf("\nCada operario fabrico la siguiente cantidad de muebles:");
    printf("\nCODIGO DEL OPERARIO:\t\tCANTIDAD DE MUEBLES FABRICADO");
    for(int i = 0; i < 25;i++){
        printf("\n%d\t\t\t\t%d",i+1,vecX[i]);
    }
}


void MostrarDiasSinProduccion(int vecX[]){
    printf("\nEn los siguientes dias no hubo produccion: ");
    for(int i = 0;i < 22;i++){
        if(vecX[i]== 0)
            printf("%d, ", i+1);
    }
}
