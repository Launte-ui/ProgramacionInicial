#include <stdio.h>
#include <string.h>
#define CHOF 100

struct Tchofer{
    int codigo;
    char nombreC[51];
    int antig;
    float importe;
};

int IngreseEnteroValido(int, int);
int BuscarCodigo(struct Tchofer[], int, int);
void LeerTextoLimpio (char [], int);
float IngreseRealMayorA(float);
int IngreseEnteroMayorACero();
int MaxPosicion(int [], int);


int main(){
    struct Tchofer vChof[CHOF];
    int codAux, antigAux, codRepetido = -1;
    char nombre[51], vZonas[CHOF];
    float impAux;
    int chofPos;
    int kms[CHOF] = {0};
    char zonas[CHOF], zonaAux = 'L';
    for (int i = 0; i < CHOF; i++){
        do{
            if(codRepetido == -1) printf("\nIngrese codigo de Chofer: ");
            else printf("\nEse codigo ya fue utilizado. Ingrese codigo de Chofer: ");
            codAux = IngreseEnteroValido(1000,9999);
            codRepetido = BuscarCodigo(vChof,codAux,i);
        }while(codRepetido != -1);
        vChof[i].codigo = codAux;

        printf("Ingrese nombre de Chofer: ");
        LeerTextoLimpio(nombre, 51);

        strcpy(vChof[i].nombreC,nombre);

        printf("Ingrese antiguedad de Chofer: ");
        antigAux = IngreseEnteroValido(0,75);
        vChof[i].antig = antigAux;

        printf("Ingrese importe cobrado por el Chofer: ");
        impAux = IngreseRealMayorA(2150);
        vChof[i].importe = impAux;
    }
    
    

    do{
        printf("\nIngrese codigo de Chofer para Buscar: ");
        codAux = IngreseEnteroValido(999,9999);
        if(codAux != 999){
            chofPos = BuscarCodigo(vChof,codAux,CHOF);
            if(chofPos == -1){
                printf("\nNo se a ecnotrado un chofer con el codigo ingresado.");
            }
            else{
                printf("\nIngrese KMs recorridos por el Chofer: ");
                kms[chofPos] += IngreseEnteroMayorACero();
                printf("\nIngrese zona recorrida por el Chofer: ");
                do{
                    if(zonaAux != 'L' && zonaAux != 'B' && zonaAux != 'P' && zonaAux != 'N') printf("\nA ingresado una zona invalida. Ingrese zona recorrida por el Chofer: ");
                    getchar();
                    scanf("%c",&zonaAux);
                }while(zonaAux != 'L' && zonaAux != 'B' && zonaAux != 'P' && zonaAux != 'N');
                zonas[chofPos] = zonaAux;
            }
        }
    }while(codAux != 999);

    printf("\n%33sNombre del chofer| KMs Recorridos| Importe recaudado","");
    for (int i = 0; i < CHOF; i++) printf("\n%50s|%15d|%15.2f$",vChof[i].nombreC,kms[i],kms[i]*vChof[i].importe);
    printf("\nA continuacion se nombrara a el/los chofer/es que mas KMs ha/n recorrido:");
    int maxRecPos = MaxPosicion(kms, CHOF);
    for (int i = 0; i < CHOF; i++) if(kms[i]==kms[maxRecPos])printf("\n%50s",vChof[i].nombreC);
    printf("\nLos siguientes choferes no han recorrido ningun KM en el dia de la fecha:");
    for (int i = 0; i < CHOF; i++) if(kms[i]==0)printf("\n%50s",vChof[i].nombreC);

    return 0;
}

int IngreseEnteroValido(int li, int ls){
    int num;
    scanf("%d",&num);
    while(num<li || num>ls){
        printf("\nERROR - Se a ingresado un valor no admitido. Intente nuevamente (Entrero entre %d y %d): ", li, ls);
        scanf("%d",&num);
    }
    return num;
}

int BuscarCodigo(struct Tchofer vChof[], int cod, int ce){
    int pos = -1, i = 0;
    while(pos == -1 && i<ce){
        if(vChof[i].codigo == cod) pos = i;
        else i++;
    }
    return pos;
}


void LeerTextoLimpio (char texto[], int largo){
    int i = 0;
    fgets(texto, largo, stdin);
    while (texto[i]!='\0'){
        if (texto[i]=='\n') texto[i]='\0';
        else i++;
    }
}

float IngreseRealMayorA(float min){
    float num;
    scanf("%f",&num);
    while(num<min){
        printf("\nERROR - Se a ingresado un valor no admitido. Intente nuevamente (Real mayor a %f): ", min);
        scanf("%f",&num);
    }
    return num;
}

int IngreseEnteroMayorACero(){
    int num;
    scanf("%d",&num);
    while(num<=0){
        printf("\nERROR - Se a ingresado un valor menor a cero. Intente nuevamente: ");
        scanf("%d",&num);
    }
    return num;
}

int MaxPosicion(int v[], int ce){
    int pos = 0;
    for(int i = 1; i < ce; i++){
        if (v[pos]<v[i]) pos = i;
    }
    return pos;
}