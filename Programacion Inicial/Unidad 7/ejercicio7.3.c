/*Dados los legajos y sueldos de los empleados de una empresa (máximo 50 empleados), se pide
determinar el / los empleado/s de máximo sueldo. El fin de carga de sueldos está dado por un
legajo igual a cero.
• Nota 1: Los números de legajo son números correlativos de 1 a 50, pero no se sabe
si están los 50 empleados.
• Nota 2: Realizar el mismo ejercicio considerando que los números de legajo son
números NO correlativos de 4 cifras. No se evalúa si se repite algún legajo.*/

#include <stdio.h>

int IngrDatoVal(int li, int ls, int cf);
int BuscarEnVector(int vecX[],int ce,int intABuscar);
int CargarVector(int vec1[], int vec2[], int ce);
int IngresarSueldo();
int BuscarMaximoEnVector(int vec2[], int ce);
void BuscarYMostrarLegajo(int sueldo[], int legajos[],int ce,int intABuscar);


int main()
{
    int legajos[50], sueldos[50], cantEmpleados, maximoSueldo;
    cantEmpleados = CargarVector(legajos,sueldos,50);
    maximoSueldo = BuscarMaximoEnVector(sueldos,cantEmpleados);
    printf("El o los empleados de mayor sueldo son los de legajo: ");
    BuscarYMostrarLegajo(sueldos,legajos,cantEmpleados, maximoSueldo);
    printf("\n\n\n");
    for (int i = 0; i < cantEmpleados; i++)
        printf("%d %d %d\n",i,legajos[i],sueldos[i]);
    return 0;
}

int IngrDatoVal(int li, int ls, int cf)
{
 int dato;
 int flag=0;
 do{
    if(flag)
        printf("\nERROR - Ingrese un valor entre %d y %d o %d: \t", li, ls,cf);
    else
        printf("\nIngrese un valor entre %d y %d o %d para terminar el proceso: \t", li, ls,cf);
    scanf("%d", &dato);
    flag=1;
 }while((dato<li || dato>ls) && dato != cf);
 return dato;
}

int BuscarEnVector(int vecX[],int ce,int intABuscar){
    int cantNumerosENcontrados = 0;
    for (int i = 0; i < ce; i++)
        if(vecX[i]==intABuscar)
            cantNumerosENcontrados++;
    return cantNumerosENcontrados;
}

void BuscarYMostrarLegajo(int sueldo[], int legajos[],int ce,int intABuscar){
    for (int i = 0; i < ce; i++)
        if(sueldo[i]==intABuscar)
            printf("%d",legajos[i]);
}

int CargarVector(int vec1[], int vec2[], int ce){
    int i = 0;
    int dato = IngrDatoVal(1,50,0);
    while(dato != 0 && i < ce){
        int flag=0;
        vec1[i] = dato;
        vec2[i] = IngresarSueldo();
        i++;
        while (!flag && i < ce){
            if(flag)
                printf("\nERROR - El legajo que se ingreso ya a sido ingresado. Vuelva a ingresar un legajo distinto. ");
            dato = IngrDatoVal(1,50,0);
            flag = BuscarEnVector( vec1, i, dato);
        }
        if(dato==0){
            printf("%d",i);
        }
    }
    return i;
}

int IngresarSueldo(){
    int entero;
    int flag = 0;
    do
    {
        if(flag)
            printf("\nSe a ingresado un sueldo invalido.\nIngrese un numero valido: ");
        else
            printf("\nIngrese el sueldo del empleado: ");
        scanf("%d",&entero);
        flag = 1;
    } while (entero <= 0);
    return entero;
}

int BuscarMaximoEnVector(int vec2[], int ce){
    int max = vec2[0];
    for (int i = 1; i < ce; i++)
        if(vec2[i] > max)
            max = vec2[i];
    return max;
}