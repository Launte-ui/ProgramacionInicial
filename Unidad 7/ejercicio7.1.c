/*Dada una lista de 10 valores enteros. Se pide:
a) Cargar la lista en memoria en un vector llamado VecA.
b) Copiar el vector VecA en otro llamado VecB.
c) Generar un vector VecC correspondiente a la suma de VecA y VecB.
d) Copiar VecA en orden inverso en otro vector llamado VecD.
e) Listar los cuatro vectores simultáneamente informando en la primera columna el
número de orden de los elementos.
f) Informar las posiciones de elementos pares del vector VecA.
g) Informar los elementos de posiciones impares del vector VecA.
h) Informar la suma de los elementos del vector VecA.
i) Informar el valor promedio de los elementos del vector VecA.
j) Ingresar por teclado un valor entero N e informar la cantidad de elementos iguales
a N en el vector VecA.
*/
#include <stdio.h>

void CargarVector(int vecX[], int ce);
void DuplicarVector(int vec1[], int vec2[], int ce);
void SumaDeVectores(int vec1[],int vec2[], int vec3[], int ce);
void InvertirVector(int vec1[], int vec2[], int ce);
int IngresarNumero();
void BuscarEnVector(int vecX[],int ce,int intABuscar);

int main()
{
    int vecA[10], vecB[10], vecC[10], vecD[10];
    float sumaVecA = 0;
    float promedioVecA;
    int buscarInt;
    CargarVector(vecA,10);
    DuplicarVector(vecA,vecB,10);
    SumaDeVectores(vecA,vecB,vecC,10);
    InvertirVector(vecA, vecD,10);
    for (int i = 0; i < 10; i++)
        printf("%d %d %d %d %d\n",i,vecA[i],vecB[i], vecC[i], vecD[i]);
    printf("\nPosiciones de elementos pares del vector A: ");
    for (int i = 0; i < 10; i++)
        if(vecA[i]%2==0)
            printf("%d,", i);
    printf("\nElementos de posiciones impares del vector A: ");
    for (int i = 0; i < 10; i++)
        if(i%2!=0)
            printf("%d,", vecA[i]);
    for (int i = 0; i < 10; i++)
        sumaVecA += vecA[i];
    printf("\nLa suma de todos los elementos del vector A es: %.0f", sumaVecA);
    promedioVecA = sumaVecA/10;
    printf("\nEl promedio de valores de los elementos del vector A es: %.1f", promedioVecA);
    buscarInt = IngresarNumero();
    BuscarEnVector(vecA, 10, buscarInt);
    return 0;
}

void CargarVector(int vecX[], int ce){
    for (int i = 0; i < ce; i++)
        vecX[i]=i+2;
}

void DuplicarVector(int vec1[], int vec2[], int ce){
    for (int i = 0; i < ce; i++)
        vec2[i] = vec1[i];
}

void SumaDeVectores(int vec1[],int vec2[], int vec3[], int ce){
    for (int i = 0; i < ce; i++)
        vec3[i] = vec1[i] + vec2[i];
}

void InvertirVector(int vec1[], int vec2[], int ce){
    for (int i = 0; i < ce; i++)
        vec2[ce-(i+1)] = vec1[i];
}

int IngresarNumero(){
    int entero;
    printf("\nIngrese un entero para buscar en el vector A: ");
    scanf("%d",&entero);
    return entero;
}

void BuscarEnVector(int vecX[],int ce,int intABuscar){
    int cantNumerosENcontrados = 0;
    for (int i = 0; i < ce; i++)
        if(vecX[i]==intABuscar)
            cantNumerosENcontrados++;
    printf("\nEn el vector dado se encontro %d veces el numero %d.",cantNumerosENcontrados,intABuscar);
}