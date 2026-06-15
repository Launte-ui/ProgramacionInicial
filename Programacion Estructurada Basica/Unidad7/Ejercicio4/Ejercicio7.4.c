// 7.4
// Realizar un programa que permita buscar un contacto en el archivo de agenda generado en punto anterior,
// por apellido o nombre y mostrar el / los datos coincidentes si los hay.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nom[26];
    char ap[26];
    char mail[51];
    int tel;
}sAgendaLinea;

FILE *AbrirArchivo(char*, char*);
void CompletarCampo(sAgendaLinea*, int, char*);
char SelectOp();
void IngresoTextoLimpio(char*, int);

int main(){
    FILE *fAgenda;

    sAgendaLinea agAux;
    char str[114], strBus[26];
    int campo, encontrado;
    char op;

    fAgenda = AbrirArchivo("AGENDA.txt","rt");
    op = SelectOp();
    while(op != 'F' && op != 'f'){

        printf("Ingrese palabra buscada: ");
        IngresoTextoLimpio(strBus,26);
        fseek(fAgenda,0,0);
        encontrado = 0;
        fgets(str, 114, fAgenda);
        while(!feof(fAgenda)){
            campo = 1;
            char *parte = strtok(str,";");
            while(parte != NULL){
                CompletarCampo(&agAux,campo, parte);
                parte = strtok(NULL,";");
                campo++;
            }
            if((op == 'N' || op == 'n') && !strcmpi(strBus, agAux.nom)){
                printf("%26s|%26s|%51s|%10d\n",agAux.nom, agAux.ap,agAux.mail, agAux.tel);
                encontrado = 1;
            }
            else if((op == 'A' || op == 'a') && !strcmpi(strBus, agAux.ap)){
                printf("%26s|%26s|%51s|%10d\n",agAux.nom, agAux.ap,agAux.mail, agAux.tel);
                encontrado = 1;
            }
            // printf("NOMBRE: %s\nAPELLIDO: %s\nMAIL: %s\nTELEFONO: +54 9 %d\n",agAux.nom,agAux.ap,agAux.mail,agAux.tel);
            
            fgets(str, 114, fAgenda);
        }
        if(!encontrado){
            printf("No encontramos ningun registro en la agenda con ese dato.\n");
        }
        op = SelectOp();
    }

    fclose(fAgenda);

    return 0;
}

FILE* AbrirArchivo(char *na, char *ma){
    FILE *fArch;
    fArch = fopen(na, ma);
    if(fArch == NULL){
        printf("Error al abrir (%s) el archivo %s.",ma,na);
        exit(1);
    }
    return fArch;
}

char SelectOp(){
    char op;
    
    printf("Ingrese el parametro de busqueda (H para mas ayuda): ");
    fflush(stdin);
    scanf("%c",&op);
    while(op != 'N' && op != 'n' && op != 'A' && op != 'a' && op != 'F' && op != 'f'){
        if(op =='h' || op == 'H')
            printf("Opciones de busqueda.\nN: Se buscaran datos en la agenda a partir del nombre ingresado\nA: Se buscaran datos en la agenda a partir del apellido ingresado\nF: Se finalizara la busqueda\nH: Se volvera a mostrar este menu de ayuda\n");
        else
            printf("ERROR - Opcion Invalida: ");
        fflush(stdin);
        scanf("%c",&op);
    }
    return op;
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

void CompletarCampo(sAgendaLinea *estr, int field, char *part){
    switch (field)
    {
    case 1:
        strcpy(estr->nom, part);
        break;
    
    case 2:
        strcpy(estr->ap, part);
        break;
    
    case 3:
        strcpy(estr->mail, part);
        break;
    
    case 4:
        estr->tel = atoi(part);
        break;
    
    default:
    printf("ERROR - fallo la conversion a un campo. Se pidio un campo de id %d. Se trabajaba con una agenda a nombre de %s\n", field, (*estr).nom);
        break;
    }

}
