/*Se ingresan DNI (entero, entre 1000000 y 99999999), código de sector (entero, 1 a 5) y sueldo
de los empleados (real, mayor a cero) de una empresa. Se sabe que como máximo la empresa
tiene 100 empleados. Se desea:
a. Cargar los datos de los empleados en vectores paralelos mediante la función
CargaEmpleados(). La carga finaliza con un empleado con DNI a 99.
b. Generar un vector con la cantidad de empleados en cada sector mediante la función
CuentaPorSector() y mostrarlo en forma de listado.
c. Determinar el importe total a pagar de sueldos.*/

#include <stdio.h>

int CargaEmpleados(int[],int[],float[]);
int IngreseIntRangoCF(int,int,int);
int IngreseIntRango(int,int);
int IngreseFloatMayorA0();
void CuentaPorSector(int[], int[], int);
float TotalDeSueldos(float[], int );
void MostrarSectores(int[]);
void CargarVectorEnCero(int vecX[], int ce);
int BuscarEnVector(int vecX[],int ce,int intABuscar);

int main()
{
    int vDNI[100], vSector[100], vEmpleadosPorSector[5];
    float vSueldos[100];
    int cantEmpleados;
    float totalDeSueldos;
    CargarVectorEnCero(vEmpleadosPorSector,5);
    cantEmpleados = CargaEmpleados(vDNI,vSector,vSueldos);
    CuentaPorSector(vSector,vEmpleadosPorSector,cantEmpleados);
    MostrarSectores(vEmpleadosPorSector);
    totalDeSueldos = TotalDeSueldos(vSueldos, cantEmpleados);
    printf("Sueldos a pagar %.2f",totalDeSueldos);
    return 0;
}

void CargarVectorEnCero(int vecX[], int ce){
    for (int i = 0; i < ce; i++)
        vecX[i] = 0;
}

int CargaEmpleados(int vDNI[],int vSector[],float vSueldos[]){
    int i = 0;
    int dato;
    printf("Ingrese DNI del empleado: ");
    dato = IngreseIntRangoCF(10000000,99999999,99);
    while(dato != 99 && i < 100){
        int flag = 0;
        vDNI[i]=dato;
        printf("Ingrese sector del empleado: ");
        vSector[i]=IngreseIntRango(1,5);
        printf("Ingrese sueldo del empleado: ");
        vSueldos[i]=IngreseFloatMayorA0();
        i++;
        printf("Ingrese DNI del empleado: ");
        dato = IngreseIntRangoCF(10000000,99999999,99);
        while (!flag && i < 100){
            flag = BuscarEnVector( vDNI, i, dato);
            if(flag >= 0)
            {
                printf("\nERROR - El legajo que se ingreso ya a sido ingresado. Vuelva a ingresar un legajo distinto. ");
                dato = IngreseIntRangoCF(10000000,99999999,99);
            }
        }
    }
    return i;
}

int IngreseIntRangoCF(int lim_menor,int lim_mayor,int excepcion)
{
    int n;
    scanf("%d",&n);
    while((n<lim_menor || n>lim_mayor) && n!=excepcion)
    {
        printf("ERROR-El numero debe estar entre el valor %d a %d- ingrese %d para terminar: ",lim_menor,lim_mayor,excepcion);
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

int IngreseFloatMayorA0()
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

void CuentaPorSector(int vSector[], int vEmpleadosPorSector[], int ce){
    for (int i = 0; i < ce; i++)
        vEmpleadosPorSector[vSector[i]-1]++;
}

float TotalDeSueldos(float vSueldos[], int ce){
    float sumaVecA = 0;
    for (int i = 0; i < ce; i++)
        sumaVecA += vSueldos[i];
    return sumaVecA;
}

void MostrarSectores(int vSectores[]){
    printf("En cada sector hay la siguiente cantidad de empleados:\n");
    for (int i = 0; i < 5; i++)
        printf("%d %d\n",i+1,vSectores[i]);
}

int BuscarEnVector(int vecX[],int ce,int intABuscar){
    int cantNumerosENcontrados = -1;
    for (int i = 0; i < ce; i++)
        if(vecX[i]==intABuscar)
            cantNumerosENcontrados++;
    return cantNumerosENcontrados;
}