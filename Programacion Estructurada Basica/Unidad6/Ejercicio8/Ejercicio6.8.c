// 6.8
// Se dispone de un archivo que contiene información de los vuelos realizados por las distintas aerolíneas a lo largo del mes. 
// El archivo se denomina Vuelos.dat y guarda los registros con la siguiente estructura:
// • Código Aerolínea (alfanumérico de 10 caracteres máximo)
// • Día (entero)
// • Número de Vuelo (entero)
// • Costo del pasaje (real)
// • Pasajeros (inicialmente en el archivo viene en 0)
// Luego se dispone de un segundo archivo llamado Pasajeros.dat que incluye la información de los viajeros 
// del mes para la aerolínea con código “Aero1”, el archivo contiene los siguientes campos:
// • DNI (entero)
// • Número de Vuelo (entero)
// Se desea realizar un programa que actualice la cantidad de pasajeros de la aerolínea con código “Aero1” con la información de 
// los pasajeros que realizaron los viajes. Tenga en cuenta que los números de vuelo se repiten entre las distintas aerolíneas.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char cod[11];
    int dia;
    int num;
    float cos;
    int pas;
}sVuelo;

typedef struct{
    int dni;
    int num;
}sPasajero;

void MostrarVuelos(char*);
void MostrarPasajeros(char*);
FILE *AbrirArchivo(char*, char*);
int BuscarVuelo(FILE*, int, sVuelo*);
void IniciaPasajerosEnCero();

int main(){
    FILE *fVuelos, *fPas;
    sPasajero pasAux;
    sVuelo vuelAux;
    int vuelPos;

    IniciaPasajerosEnCero();
    MostrarVuelos("VUELOS.dat");
    MostrarPasajeros("PASAJEROS.dat");

    fVuelos = AbrirArchivo("VUELOS.dat", "r+b");
    fPas = AbrirArchivo("PASAJEROS.dat", "rb");
    
    fread(&pasAux, sizeof(sPasajero), 1, fPas);
    while(!feof(fPas)){
        vuelPos = BuscarVuelo(fVuelos, pasAux.num, &vuelAux);
        if(vuelPos != -1){
            fseek(fVuelos, sizeof(sVuelo) * vuelPos, 0);
            vuelAux.pas++;
            fwrite(&vuelAux, sizeof(sVuelo),1, fVuelos);
            fflush(fVuelos);
        }
        else
            printf("No encontramos el vuelo para el pasajero de dni %d en la aerolinea AERO1. Se buscaba el vuelo %d.\n", pasAux.dni, pasAux.num);

        fread(&pasAux, sizeof(sPasajero), 1, fPas);
    }

    printf("Termino el proceso con exito.\nCerrando archivos...");

    fclose(fVuelos);
    fclose(fPas);

    printf("Archivos cerrados.\n");

    MostrarVuelos("VUELOS.dat");


    return 0;
}

void MostrarVuelos(char *na){
    FILE *arch;
    arch = fopen(na,"rb");
    sVuelo p;
    if(arch == NULL){
        printf("NO SE PUDO ABRIR %s PARA SU LECTURA.", na);
        exit(1);
    }
    printf("VUELOS\n");
    fread(&p, sizeof(sVuelo),1,arch);
    while(!feof(arch)){
        printf("%11s|%3d|%5d|%8.2f$|%4d\n",p.cod,p.dia,p.num,p.cos,p.pas);
        fread(&p, sizeof(sVuelo),1,arch);
    }
    fclose(arch);
}

void MostrarPasajeros(char *na){
    FILE *arch;
    arch = fopen(na,"rb");
    sPasajero p;
    if(arch == NULL){
        printf("NO SE PUDO ABRIR %s PARA SU LECTURA.", na);
        exit(1);
    }
    printf("PASAJEROS\n");
    fread(&p, sizeof(sPasajero),1,arch);
    while(!feof(arch)){
        printf("%8d|%3d\n",p.dni,p.num);
        fread(&p, sizeof(sPasajero),1,arch);
    }
    fclose(arch);
}


void IniciaPasajerosEnCero(){
    FILE *arch;
    arch = fopen("VUELOS.dat","r+b");
    sVuelo p;
    if(arch == NULL){
        printf("NO SE PUDO ABRIR VUELOS.dat PARA REINICIAR LOS PASAJEROS.");
        exit(1);
    }
    fread(&p, sizeof(sVuelo),1,arch);
    while(!feof(arch)){
        p.pas = 0;
        fseek(arch, sizeof(sVuelo) * -1, 1);
        fwrite(&p, sizeof(sVuelo), 1, arch);
        fflush(arch);
        fread(&p, sizeof(sVuelo),1,arch);
    }
    fclose(arch);
}


FILE *AbrirArchivo(char *na, char *ma){
    FILE *arch;
    arch = fopen(na, ma);
    if(arch == NULL){
        printf("ERROR - No se pudo abrir el archivo %s en modo %s.",na,ma);
        exit(1);
    }
    return arch;
}

int BuscarVuelo(FILE *arch, int num, sVuelo *vuelAux){
    int pos = -1;
    sVuelo v;
    fseek(arch,0,0);
    fread(&v, sizeof(sVuelo), 1, arch);
    while(!feof(arch) && pos == -1){
        if(strcmp("AERO1",v.cod) == 0 && v.num == num){
            pos = (ftell(arch)/sizeof(sVuelo))-1;
            *vuelAux = v;
        }
        else{
            fread(&v, sizeof(sVuelo), 1, arch);
        }
    }
    return pos;
}
