#include <stdio.h>
#include <stdlib.h>
#include "./arrays.h"

// Primitivas
bool SetArray(Array* array, int size)
{
    if(size <= 0)
    {
        return false;
    }

    Array arrayAux;
    int* dirAux;

    dirAux = (int*)malloc(size * sizeof(int));

    if(dirAux == NULL)
    {
        return false;
    }

    arrayAux.ce = 0;
    arrayAux.size = size;
    arrayAux.dir = dirAux;

    dirAux = NULL;

    *array = arrayAux;

    return true;
}

void EliminarArray(Array* array)
{
    free(array->dir);
    array->dir = NULL;
    array->ce=0;
    array->size=0;
}

bool InsertarNumEnPos(Array* array, int num, int pos)
{
    if(INVALIDPOS(pos, array->size) || ARRAYOVERFLOW(array->ce, array->size) || INVALIDINSERTNGPOS(pos, array->ce))
    {
        return false;
    }

    int aux1, aux2;
    aux1 = *(array->dir+pos);
    *(array->dir+pos) = num;
    array->ce++;
    for(int i = pos + 1; i < array->ce; i++)
    {
        aux2=*(array->dir+i);
        *(array->dir+i)=aux1;
        aux1=aux2;
    }
    return true;
}


bool InsertarNumEnOrdenA(Array* array, int num)
{
    if(ARRAYOVERFLOW(array->ce,array->size))
    {
        return false;
    }

    if(array->ce==0)
    {
        array->ce++;
        *(array->dir)=num;
        return true;
    }

    int i = array->ce-1;
    while(i >= 0 && *(array->dir+i)>num)
    {
        i--;
    }
    
    return InsertarNumEnPos(array, num, i+1);
}

int GetMinPosNumArr(int* arr, int ce)
{
    int minPos = 0;
    for(int i = 1; i < ce; i++)
    {
        if(*(arr + i) < *(arr + minPos))
        {
            minPos = i;
        }
    }
    return minPos;
}

int GetMaxPosNumArr(int* arr, int ce)
{
    int maxPos = 0;
    for(int i = 1; i < ce; i++)
    {
        if(*(arr + i) > *(arr + maxPos))
        {
            maxPos = i;
        }
    }
    return maxPos;
}

void OrdenAscendenteArr (Array* array)
{
    int aux, minPos;
    for(int i = 0; i < array->size; i++)
    {
        minPos = GetMinPosNumArr(array->dir+i, array->ce-i) + i;
        
        if(minPos != i)
        {   
            aux = *(array->dir+i);
            *(array->dir+i)=*(array->dir+minPos);
            *(array->dir+minPos)=aux;
        }
    }
}

void OrdenDescendenteArr (Array* array)
{
    int aux, maxPos;
    for(int i = 0; i < array->size; i++)
    {
        maxPos = GetMaxPosNumArr(array->dir+i, array->ce-i) + i;

        if(maxPos != i)
        {
            aux = *(array->dir);
            *(array->dir+i) = *(array->dir+maxPos);
            *(array->dir+maxPos) = aux;
        }
    }
}

bool EliminarNumEnPos(Array* array, int pos)
{
    if(INVALIDPOS(pos,array->size) || INVALIDEXISTINGPOS(pos,array->ce))
    {
        return false;
    }

    array->ce--;

    for(int i = pos; i < array->ce; i++)
    {
        *(array->dir+i) = *(array->dir+i+1);
    }
    return true;
}

bool EliminarTodoNum(Array* array, int num)
{
    int i = 0;
    while(i<array->ce)
    {
        if(*(array->dir+i)==num)
        {
            if(!EliminarNumEnPos(array, i))
            {
                return false;
            }
            i--;
        }
        i++;
    }
    return true;
}

// No Primitivas

void CrearArray(Array* array)
{
    int size;
    printf("Ingrese la maxima cantidad de elementos que soporta el array: ");
    scanf("%d",&size);
    while(!SetArray(array, size))
    {
        printf("ERROR.\n");
        printf("Ingrese la maxima cantidad de elementos que soporta el array: ");
        scanf("%d",&size);
    }
}

void CrearArrayPredeterminado(Array* array)
{
    SetArray(array, 10);
}

void IniciarArrEnCero(Array* array)
{
    for(int i = 0; i < array->size; i++)
    {
        *(array->dir+i) = 0;
    }
}

void MostrarArray(Array* array)
{
    for(int i = 0; i < array->size; i++)
    {
        printf("%d", *(array->dir+i));
        if(i < array->size - 1)
        {
            printf(", ");
        }
    }
}

void SaltoDeLinea()
{
    printf("\n");
}

void MeteXAca(Array* array)
{
    int num, pos;
    printf("Ingrese un numero para ingresar en el array: ");
    scanf("%d",&num);
    printf("CANTIDAD DE ELEMENTOS USADOS: %d.\n",array->ce);
    printf("Ingrese en que posicoin del array se ingresara el numero: ");
    scanf("%d",&pos);
    while (!InsertarNumEnPos(array, num, pos))
    {
        printf("ERROR.\n");
        printf("Ingrese un numero para ingresar en el array: ");
        scanf("%d",&num);
        printf("CANTIDAD DE ELEMENTOS USADOS: %d.\n",array->ce);
        printf("Ingrese en que posicoin del array se ingresara el numero: ");
        scanf("%d",&pos);
    }
    
}

void MeteXAcaOrdenadito(Array* array)
{
    int num;
    printf("Ingrese un numero para ingresar en el array: ");
    scanf("%d",&num);
    while (!InsertarNumEnOrdenA(array, num))
    {
        printf("ERROR.\n");
        printf("Ingrese un numero para ingresar en el array: ");
        scanf("%d",&num);
    }
    
}

void SacameloDeAca(Array* array)
{
    int pos;
    printf("Ingrese la posicion que quiere eliminar del array: ");
    scanf("%d",&pos);
    while (!EliminarNumEnPos(array, pos))
    {
        printf("ERROR.\n");
        printf("Ingrese la posicion que quiere eliminar del array: ");
        scanf("%d",&pos);
    }

}

void SacameATodosDeAca(Array* array)
{
    int num;
    printf("Ingrese el numero que quiere eliminar completamente del array: ");
    scanf("%d",&num);
    while (!EliminarTodoNum(array, num))
    {
        printf("ERROR.\n");
        printf("Ingrese el numero que quiere eliminar completamente del array: ");
        scanf("%d",&num);
    }

}