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

int main()
{
    int numeroAutos[60], tiemposAutos[60], primerLugar, ultimoLugar, promedio, supPromedio, noParticipo, cantAutos;
    CargarVectorEnCero(numeroAutos,60);
    CargarVectorEnCero(tiemposAutos,60);
    cantAutos = CargarVevtor(numeroAutos, tiemposAutos, 60);

    for (int i = 0; i < cantAutos; i++)
        printf("%d %d %d\n",i,numeroAutos[i],tiemposAutos[i]);
    return 0;
}

int CargarVevtor(int vec1[], int vec2[], int ce){
    int i = 0;
    int numAuto = IngresarAuto();
    while(numAuto > 0 && i < ce){
        vec1[i] = numAuto;
        vec2[i] = IngresarTiempo();
        i++;
        numAuto = IngresarAuto();
    }
    return i;
}

void CargarVectorEnCero(int vecX[], int ce){
    for (int i = 0; i < ce; i++)
        vecX[i] = 0;
}

int IngresarAuto(){
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
