/*6.12
Se dispone de un archivo con nombre Llamadas.dat que contiene llamadas telefónicas realizadas en una
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
• Costo de la llamada (float)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char sec[16];
    int dur;
    int tipo;
}sLlamada;

typedef struct{
    float t1;
    float t2;
    float t3;
}sCosto;

typedef struct{
    char sec[16];
    float cos1;
    float cos2;
    float cos3;
}sGasto;

typedef struct{
    int dur;
    int tipo;
    float cos;
}sSector;


sCosto ObtenerCostos();
FILE *AbrirArchivo(char*, char*);
void MostrarGastos();
void MostrarLlamadasSector(char *);


int main(){
    FILE *fLlamadas;
    FILE *fGastos;

    sCosto costos;
    sLlamada llamadaAux;
    sGasto gastoAux;
    sSector llamadaSecAux;
    
    fLlamadas = AbrirArchivo("LLAMADAS.dat","rb");
    fGastos = AbrirArchivo("GASTOS.dat", "wb");
    costos = ObtenerCostos();
    
    int tiempoLlamadaMax, primero = 1;
    char secAnterior[16];
    char maxSector[16];
    char nomArchSec[20];
    fread(&llamadaAux, sizeof(sLlamada),1,fLlamadas);
    while(!feof(fLlamadas)){
        strcpy(secAnterior, llamadaAux.sec);
        FILE *fSector;

        strcpy(nomArchSec, secAnterior);

        fSector = AbrirArchivo(strcat(nomArchSec, ".dat"), "wb");

        int locCont = 0, larDisCont = 0, celCont = 0;
        int locTie = 0, larDisTie = 0, celTie = 0;
        int tiempoTotal = 0;
        while(!feof(fLlamadas) && !strcmpi(secAnterior, llamadaAux.sec)){
            switch(llamadaAux.tipo){
                case 1:
                    locCont++;
                    locTie += llamadaAux.dur;
                    break;
                case 2:
                    larDisCont++;
                    larDisTie += llamadaAux.dur;
                    break;
                case 3:
                    celCont++;
                    celTie += llamadaAux.dur;
                    break;
                default:
                    printf("Una llamada se registro con tipo de llamada invalido.\n");
                    break;
            }
            tiempoTotal += llamadaAux.dur;
            
            llamadaSecAux.dur = llamadaAux.dur;
            llamadaSecAux.tipo = llamadaAux.tipo;
            if(llamadaSecAux.tipo == 1){
                llamadaSecAux.cos = llamadaSecAux.dur * costos.t1;
            }
            else{
                if(llamadaSecAux.tipo == 2){
                    llamadaSecAux.cos = llamadaSecAux.dur * costos.t2;
                }
                else{
                    if(llamadaSecAux.tipo == 3){
                        llamadaSecAux.cos = llamadaSecAux.dur * costos.t3;
                    }
                }
            }
            fwrite(&llamadaSecAux, sizeof(sSector), 1, fSector);

            fread(&llamadaAux, sizeof(sLlamada),1,fLlamadas);
        }
        printf("\nCANTIDAD Y TIPO DE LLAMADAS DEL SECTOR %s\nLocal: %d\nLarga Distancia:%d\nCelular: %d\n",secAnterior,locCont,larDisCont,celCont);
        if(primero || tiempoTotal > tiempoLlamadaMax){
            tiempoLlamadaMax = tiempoTotal;
            primero = 0;
            strcpy(maxSector, secAnterior);
        }
        strcpy(gastoAux.sec, secAnterior);
        gastoAux.cos1 = locTie * costos.t1;
        gastoAux.cos2 = larDisTie * costos.t2;
        gastoAux.cos3 = celTie * costos.t3;
        fwrite(&gastoAux, sizeof(sGasto), 1, fGastos);
        
        fclose(fSector);
        MostrarLlamadasSector(nomArchSec);
    }

    fclose(fLlamadas);
    fclose(fGastos);

    printf("\nEl sector que hablo mas tiempo es el sector %s\n",maxSector);


    printf("\n------------------------------GASTOS-------------------------------------\n");
    MostrarGastos();
    return 0;
}

FILE *AbrirArchivo(char *na, char *ma){
    FILE *arch;
    arch = fopen(na, ma);
    if(arch == NULL){
        printf("FATAL ERROR - %s", na);
        exit(1);
    }
    return arch;
}

sCosto ObtenerCostos(){
    FILE *arch;
    arch = fopen("COSTOS.dat", "rb");
    sCosto aux;
    if(arch == NULL){
        printf("FATAL ERROR - LEYENDO COSTOS");
        exit(1);
    }
    fread(&aux, sizeof(sCosto), 1, arch);
    fclose(arch);
    return aux;
}

void MostrarGastos(){
    FILE *arch;
    arch = fopen("GASTOS.dat","rb");
    sGasto aux;
    if(arch == NULL){
        printf("FATAL ERROR - No se pudo leer COSTOS");
        exit(1);
    }
    fread(&aux, sizeof(sGasto), 1, arch);
    while(!feof(arch)){
        printf("SECTOR: \t%s|LOCAL: \t%0.2f$|LAR. DIST.: \t%0.2f$|CELULAR: \t%0.2f$\n",aux.sec,aux.cos1,aux.cos2,aux.cos3);
        fread(&aux, sizeof(sGasto), 1, arch);
    }
    fclose(arch);
}


void MostrarLlamadasSector(char *na){
    FILE *arch;
    arch = fopen(na,"rb");
    sSector aux;
    printf("#%s-------------------------------------\n",na);
    if(arch == NULL){
        printf("FATAL ERROR - No se pudo leer %s",na);
        exit(1);
    }
    fread(&aux, sizeof(sSector), 1, arch);
    while(!feof(arch)){
        printf("TIEMPO EN LLAMADA: %d\nTIPO: %d\nCOSTO DE LA LLAMADA.: %0.2f$\n",aux.dur,aux.tipo,aux.cos);
        fread(&aux, sizeof(sSector), 1, arch);
    }
    fclose(arch);
}