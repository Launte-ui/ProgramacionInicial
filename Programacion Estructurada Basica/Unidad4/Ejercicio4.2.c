// 4.2 Un laboratorio dispone de una lista con sus 50 medicamentos. De cada uno conoce:
// • Código del medicamento (entero, de 3 cifras).
// • Precio (real).
// • Stock (entero).
// Se solicita:
// a. Declarar un tipo de dato que contenga la información del medicamento.
// b. Declarar un vector de estructura de tipo de datos creado en a.
// c. Cargar en un sector de estructuras, los datos referentes a los medicamentos. Función INGRESO.
// d. Consultar el precio según código del medicamento. Función BUSQUEDA_MEDI.
// e. Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME.

#include <stdio.h>
#define MEDIS 2

typedef struct {
    int codigo;
    float precio;
    int stock;
}Tmedicamento;

Tmedicamento Ingreso(Tmedicamento[], int);
int LeerEneteroVal(int, int);
int BUSQUEDA_MEDI(Tmedicamento[], int, int);
float LeerRealPositivo();
int LeerEneteroPositivo();
void INFORME(Tmedicamento[], int);

int main(){
    Tmedicamento vMedis[MEDIS];
    int medPos, codAux;
    for(int i = 0; i < MEDIS; i++){
        vMedis[i] = Ingreso(vMedis, i);
    }

    do{
        printf("\nIngrese codigo del medicamento buscado o ingrese 99 para finalizar la busqueda: ");
        codAux = LeerEneteroVal(99,999);
        if(codAux != 99){
            medPos = BUSQUEDA_MEDI(vMedis, MEDIS, codAux);
            if(medPos!=-1) printf("\nEl medicamento solicitado tiene un precio de %.2f$.", vMedis[medPos].precio);
            else printf("\nNo se encontro un medicamento con el codigo %d.", codAux);
        }

    }while(codAux != 99);

    INFORME(vMedis, MEDIS);
    return 0;
}

Tmedicamento Ingreso(Tmedicamento v[], int ce){
    Tmedicamento nuevoMedicamento;
    int codAux, codRep=-1;
    printf("\nIngrese codigo del nuevo medicamento: ");
    do{
        if(codRep != -1) printf("\nHa ingresado un codigo ya existente. Porfavor vuelva a intentar: ");
        codAux = LeerEneteroVal(100,999);
        codRep = BUSQUEDA_MEDI(v, ce, codAux);
    }while(codRep != -1);
    nuevoMedicamento.codigo = codAux;
    printf("\nIngrese precio del nuevo medicamento: ");
    nuevoMedicamento.precio = LeerRealPositivo();
    printf("\nIngrese stock del nuevo medicamento: ");
    nuevoMedicamento.stock = LeerEneteroPositivo();
    return nuevoMedicamento;
}

int LeerEneteroVal(int li, int ls){
    int num;
    scanf("%d",&num);
    while(num<li || num>ls){
        printf("ERROR - Se a ingresado un valor entero no admitido. Ingrese un nuevo valor (Entre %d y %d): ",li,ls);
        scanf("%d",&num);
    }
    return num;
}

int BUSQUEDA_MEDI(Tmedicamento v[], int ce, int codigo){
    int pos = -1, i = 0;
    while(i<ce && pos==-1){
        if(v[i].codigo == codigo) pos = i;
        else i++;
    }
    return pos;
}

float LeerRealPositivo(){
    float num;
    scanf("%f",&num);
    while(num<0){
        printf("ERROR - Se a ingresado un valor real no admitido. Ingrese un nuevo valor (Mayor a cero): ");
        scanf("%f",&num);
    }
    return num;
}

int LeerEneteroPositivo(){
    int num;
    scanf("%d",&num);
    while(num<0){
        printf("ERROR - Se a ingresado un valor entero no admitido. Ingrese un nuevo valor (Mayor a cero): ");
        scanf("%d",&num);
    }
    return num;
}

void INFORME(Tmedicamento v[], int ce){
    printf("\nA continuacion se informan los codigos de medicamentos con stock menos a 10 unidades:\n");
    for(int i = 0; i < ce; i++){
        if(v[i].stock < 10)
        {
            printf("%d",v[i].codigo);
            if(i != ce-1) printf(", ");
            else printf(".");
        }
    }

}