// 7.3
// Realizar un programa que genere un archivo llamado “agenda.txt” en el cual se almacene los siguientes datos ingresados por teclado:
// • Apellido
// • Nombre
// • Correo electrónico
// • Teléfono
// El ingreso se datos finaliza con apellido y nombre igual a “FINALIZAR”. Utilice el separador ; (punto y coma) entre campos.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

FILE *AbrirArchivo(char*, char*);
int IngresoEnteroVal(int, int);
void IngresoTextoLimpio(char*, int);
void LeerArchTxtChar(char*);

int main(){
    FILE *fAgenda;
    FILE *fAgendaExcel;
    fAgenda = AbrirArchivo("AGENDA.txt","wb");
    fAgendaExcel = AbrirArchivo("AGENDA.csv","wb");
    char nomAux[26], apAux[26], mailAux[51];
    int telAux;
    printf("Ingrese nombre: ");
    IngresoTextoLimpio(nomAux,26);
    printf("Ingrese apellido: ");
    IngresoTextoLimpio(apAux,26);
    while(strcmpi(apAux, "FINALIZAR") || strcmpi(nomAux, "FINALIZAR")){
        printf("Ingrese mail: ");
        IngresoTextoLimpio(mailAux,51);
        printf("Ingrese numero de telefono: ");
        telAux = IngresoEnteroVal(1100000000, 1199999999);
        fprintf(fAgenda,"%s;%s;%s;%d\n",nomAux, apAux, mailAux, telAux);
        fprintf(fAgendaExcel,"%s;%s;%s;%d\n",nomAux, apAux, mailAux, telAux);
        printf("Ingrese nombre: ");
        IngresoTextoLimpio(nomAux,26);
        printf("Ingrese apellido: ");
        IngresoTextoLimpio(apAux,26);
    }
    
    fclose(fAgenda);
    fclose(fAgendaExcel);

    LeerArchTxtChar("AGENDA.txt");
    LeerArchTxtChar("AGENDA.csv");
    return 0;
}

FILE *AbrirArchivo(char *na, char *ma){
    FILE *arch;
    arch = fopen(na, ma);
    if(arch == NULL){
        printf("FATAL ERROR");
        exit(1);
    }
    return arch;
}

void IngresoTextoLimpio(char *str, int largo){
    int i = 0;
    fflush(stdin);
    fgets(str, largo, stdin);
    while(*(str+i)!='\0' && i < largo){
        if(*(str+i)=='\n')
            *(str+i) = '\0';
        else
            i++;
    }
}

int IngresoEnteroVal(int li, int ls){
    int num;
    scanf("%d",&num);
    while(num < li || num > ls){
        printf("ERROR - Entero invalido. Vuelva a ingresar: ");
        scanf("%d",&num);
    }
    return num;
}

void LeerArchTxtChar(char *na){
    FILE *arch;
    arch = fopen(na,"rt");
    char cAux;
    if(arch==NULL){
        printf("ERROR");
        exit(1);
    }
    cAux = fgetc(arch);
    while(!feof(arch)){
        printf("%c",cAux);
        Sleep(20);
        cAux = fgetc(arch);
    }
    fclose(arch);
}