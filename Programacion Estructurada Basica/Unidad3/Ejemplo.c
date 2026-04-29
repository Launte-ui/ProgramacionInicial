#include <stdio.h>
#include <string.h>

void carga(char[][20],int);
void mostrar(char[][20],int);
int buscar(char[][20],char [], int);
void ordenar (char[][20],int);

int main ()
{
    int pos;
    char nombres[5][20], abuscar[20];
    carga(nombres,5);
    printf("\nListado de nombres ingresado:\n");
    mostrar(nombres,5);
    printf ("\nIngrese un nombre a buscar (FIN para terminar): ");
    gets(abuscar);
    while (strcmpi(abuscar, "FIN")!=0)
    {
        pos = buscar(nombres,abuscar,5);
        if (pos!=-1)
        printf ("\nEl nombre buscado se encuentra en el vector");
        else
        printf ("\nEl nombre buscado NO se encuentra en el vector");
        printf ("\nIngrese un nombre a buscar (FIN para terminar): ");
        gets(abuscar);
    }
    ordenar(nombres,5);
    printf("\n\nListado de nombres ordenado:\n");
    mostrar(nombres,5);
    return 0;
}

void carga(char vn[][20],int cant){
    int i;
    for (i=0;i<cant;i++){
        printf ("Ingrese el nombre numero %d: ", i+1);
        gets(vn[i]);
    }
}

void mostrar(char vn[][20],int cant){
    int i;
    for (i=0;i<cant;i++)
    puts(vn[i]);
}

int buscar(char vn[][20],char buscado[], int cant){
    int i=0, pos=-1;
    while (pos==-1 && i<cant){
        if (strcmpi(vn[i], buscado)==0)
        pos =i;
        else
        i++;
    }
    return pos;
}

void ordenar (char vn[][20],int cant)
{
    int i,j;
    char aux[20];
    for (i=0;i<cant-1;i++){
        for (j=0;j<cant-1-i;j++){
            if (strcmpi(vn[j],vn[j+1]) > 0){
                strcpy(aux, vn[j]);
                strcpy(vn[j],vn[j+1]);
                strcpy(vn[j+1], aux);
            }
        }
    }
}