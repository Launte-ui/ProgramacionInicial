/*Se dispone de un archivo con nombre Llamadas.dat que contiene llamadas telefónicas realizadas en una
empresa. Por cada llamada se dispone de la siguiente información:
• Sector (15 caracteres máximo)
• Duración en segundos (entero)
• Tipo de llamada (entero: 1 local, 2 larga distancia, 3 celular)
El archivo se encuentra organizado por Sector. Se solicita:

a. Calcular y mostrar por cada sector, la cantidad de llamadas realizadas de cada tipo.
b. Determinar cuál es el sector que habló la mayor cantidad de tiempo.
c. En un archivo llamado costos.dat hay un único registro que contiene los costos por segundo de los
tres tipos de llamadas (3 float). Se debe generar el archivo gastos.dat que totalice los gastos de
llamadas de cada sector.
d. Realizar una función que muestre los datos almacenados en gastos.dat en forma de listado.
e. Generar un archivo para cada sector con el detalle de llamadas valorizado. El archivo se debe
generar con nombresector.dat y debe contener:
• Duración en segundos (entero)
• Tipo de llamada (entero)
• Costo de la llamada (float)



*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char sector[16];
    int duracion;
    int tipo;
}sLlamada;

typedef struct
{
    float cosxsegTipo1;
    float cosxsegTipo2;
    float cosxsegTipo3;
}sCostos;

typedef struct 
{
    char sector[16];
    float totalxsect;
}sGastos;

typedef struct 
{
    int duracion;
    int tipo;
    float costo;
}sSector;

FILE *abrirArch(char*,char*);
void MostrarGastos();

int main()
{
    FILE *PFL,*PFC,*PFG,*PFS;
    sLlamada l;
    sCostos c;
    sGastos g;
    sSector s;

    int tipo[3];
    int duracionTipo[3];
    float costos[3];

    char secAnterior[16],secMayor[16],nombrArch[19];
    int band=0,i,j,k;
    int duracionTotal,duracionMayor;   
    PFL=abrirArch("LLAMADAS.dat","rb");
    PFC=abrirArch("COSTOS.dat","rb");
    PFG=abrirArch("GASTOS.dat","wb");
    fread(&c,sizeof(c),1,PFC);          //
    costos[0]=c.cosxsegTipo1;           //
    costos[1]=c.cosxsegTipo2;           //  CARGA DIRECTA DE LOS COSTOS EN EL VECTOR    
    costos[2]=c.cosxsegTipo3;           //    
    fclose(PFC);
    fread(&l,sizeof(l),1,PFL);
    while(!feof(PFL))
    {
        strcpy(secAnterior,l.sector);
        for(i=0;i<3;i++)
        {
            duracionTipo[i]=0;
            tipo[i]=0;
        }
        duracionTotal=0;
        while(!feof(PFL) && strcmp(secAnterior,l.sector)==0)
        {
            tipo[l.tipo-1]++;                       //
            duracionTipo[l.tipo-1]+=l.duracion;     //
            duracionTotal+=l.duracion;              //
            fread(&l,sizeof(l),1,PFL);
        }
        strcpy(g.sector,secAnterior);



        g.totalxsect=0;                                 //
        for(j=0;j<3;j++)                                //
        {                                               //
            g.totalxsect+=duracionTipo[j]*costos[j];    //      PARA CARGAR EL ARCHIVO DE GASTOS
        }                                               //
        fwrite(&g,sizeof(g),1,PFG);                     //


        strcpy(nombrArch,secAnterior);
        strcat(nombrArch,".dat");
        PFS=abrirArch(nombrArch,"wb");
        for(k=0;k<3;k++)
        {
            s.tipo=k+1;
            s.duracion=duracionTipo[k];
            s.costo=duracionTipo[k]*costos[k];
            fwrite(&s,sizeof(s),1,PFS);
        }
        fclose(PFS);


        if(!band || duracionTipo>duracionMayor)
        {
            band=1;
            strcpy(secMayor,secAnterior);
            duracionMayor=duracionTotal;
        }
        printf("\nSECTOR %s:\nTIPO 1:\t%d\nTIPO 2:\t%d\nTIPO 3:\t%d",secAnterior,tipo[0],tipo[1],tipo[2]);
    }
    printf("\nEl sector con mayor cantidad de llamadas fue el sector %s con:\t%d",secMayor,duracionMayor);
    fclose(PFG);
    fclose(PFL);
    MostrarGastos();
    return 0;
}

FILE* abrirArch(char *na,char *ma)
{
    FILE *arch;
    arch=fopen(na,ma);
    if(arch==NULL)
    {
        printf("\nNO SE PUDO ABRIR EL ARCHIVO %s",na);
        exit(1);
    }
    return arch;
}

void MostrarGastos()
{
    FILE *arch;
    sGastos g;
    arch=abrirArch("GASTOS.dat","rb");
    fread(&g,sizeof(g),1,arch);
    while(!feof(arch))
    {
        printf("\nSECTOR:  %-15sTOTAL:  %10.4f",g.sector,g.totalxsect);
        fread(&g,sizeof(g),1,arch);
    }
    fclose(arch);
}