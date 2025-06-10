/* Para una carrera de automóviles, se toman los tiempos de clasificación (real, mayor que 0 en
segundos) de como máximo 60 autos de carrera inscriptos para la competencia.
Los autos se identifican con números correlativos del 1 al 60, quedando sin información aquellos
que no participan de la presente carrera. Cuando ya no hay más tiempos de clasificación para
cargar, se ingresa un auto con número negativo.
Se solicita determinar:
• El número de auto que clasificó en primer lugar.
• El número de auto que obtuvo el peor tiempo de clasificación.
• La cantidad de autos que superaron el promedio de tiempo de clasificación.
• El o los números de autos que no participan de la carrera actual. */

#include <stdio.h>

int CargarVector(int vec1[], int vec2[], int ce);
void CargarVectorEnCero(int vecX[], int ce);
int IngresarDato();
int IngresarTiempo();
int BuscarMejorTiempo(int vec1[], int vec2[], int ce);
int BuscarPeorTiempo(int vec1[], int vec2[], int ce);

int main()
{
    int numeroAutos[60], tiemposAutos[60], primerLugar, ultimoLugar, cantAutos;
    float promedio = 0;
    CargarVectorEnCero(numeroAutos,60);
    CargarVectorEnCero(tiemposAutos,60);
    cantAutos = CargarVector(numeroAutos, tiemposAutos, 60);
    primerLugar = BuscarMejorTiempo(numeroAutos, tiemposAutos, cantAutos);
    ultimoLugar = BuscarPeorTiempo(numeroAutos, tiemposAutos, cantAutos);
    if(cantAutos > 0){
        for (int i = 0; i < cantAutos; i++)
        {
            promedio += tiemposAutos[i];
        }
            promedio = promedio/ 10;
        printf("\nEl auto que quedo en primer lugar fue el de numero %d\nEl auto que logro el peor tiempo es el de numero %d ",primerLugar, ultimoLugar);
        printf("\nLos autos que superaron el promedio fueron los de numero: ");
        for (int i = 0; i < cantAutos; i++)
        {
            if(tiemposAutos[i] > promedio){
                printf("%d, ",numeroAutos[i]);
            }
        }
        printf("\nLos autos que no participaron en la carreara son los de numero: ");
        for (int i = 1; i <= 60; i++)
        {
            int flag = 1, j = 0;
            while (flag && j < cantAutos)
            {
                if(numeroAutos[j] == i){
                    flag = 0;
                }
                j++;
            }
            if(flag){
                printf("%d, ",i);
            }
        }
    }
    else{
        printf("No participo ningun auto en la carrera.");
    }
    
    return 0;
}

int CargarVector(int vec1[], int vec2[], int ce){
    int i = 0;
    int numAuto = IngresarDato();
    while(numAuto > 0 && i < ce){
        vec1[i] = numAuto;
        vec2[i] = IngresarTiempo();
        i++;
        numAuto = IngresarDato();
    }
    return i;
}

void CargarVectorEnCero(int vecX[], int ce){
    for (int i = 0; i < ce; i++)
        vecX[i] = 0;
}

int IngresarDato(){
    int entero;
    int flag = 0;
    do
    {
        if(flag)
            printf("\nSe a ingresado un numero invalido de auto, si quiere dejar de ingresar autos ingrese un numero negativo. \nSino ingrese un numero valido: ");
        else
            printf("\nIngrese el numero de un auto que participo en el carrera: ");
        scanf("%d",&entero);
        flag = 1;
    } while (entero == 0 && entero >= 60);
    return entero;
}

int IngresarTiempo(){
    int entero;
    int flag = 0;
    do
    {
        if(flag)
            printf("\nSe a ingresado un tiempo invalido. Ingrese un tiempo valido: ");
        else
            printf("\nIngrese el tiempo en el que el auto termino la carrera carrera: ");
        scanf("%d",&entero);
        flag = 1;
    } while (entero <= 0);
    return entero;
}

int BuscarMejorTiempo(int vec1[], int vec2[], int ce){
    int max = vec2[0];
    int primerAuto = vec1[0];
    for (int i = 1; i < ce; i++)
    {
        if(vec2[i] < max){
            max = vec2[i];
            primerAuto = vec1[i];
        }
    }
    return primerAuto;
}

int BuscarPeorTiempo(int vec1[], int vec2[], int ce){
    int max = vec2[0];
    int primerAuto = vec1[0];
    for (int i = 1; i < ce; i++)
    {
        if(vec2[i] > max){
            max = vec2[i];
            primerAuto = vec1[i];
        }
    }
    return primerAuto;
}