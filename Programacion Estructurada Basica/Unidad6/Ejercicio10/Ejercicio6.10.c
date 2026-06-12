// 6.10
// Dado el archivo pagos.dat con los pagos realizados por los alumnos a un curso, se desea registrar los pagos de las cuotas. 
// El archivo tiene el siguiente formato:
// • DNI
// • Fecha de último pago (3 enteros, día, mes y año)
// Para registrar los pagos se ingresa el número de DNI (7 a 8 dígitos) y la fecha de pago. 
// Se debe actualizar el archivo de pagos, y si el DNI no se encuentra se pregunta al usuario si desea agregar un nuevo alumno. 
// En caso afirmativo se debe agregar un nuevo registro en dicho archivo con el nuevo pago y además agregar el nuevo alumno al archivo alumnos.dat, 
// dicho archivo contiene el DNI y nombre completo del alumno (40 caracteres máximo).
// Todos los datos de ingreso deben estar validados (para simplificar al validar la fecha considerar día de 1 a 31 para todos los meses).
// Se procesan varios pagos hasta que se ingresa un DNI 0. Al finalizar mostrar un listado de los alumnos, 
// DNI y nombre de todos aquellos que adeudan la última cuota (del mes de febrero 2024).
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}sFecha;

typedef struct{
    int dni;
    sFecha up;
}sPago;

typedef struct{
    int dni;
    char nom[41];
}sAlumno;

FILE *AbrirArchivo(char*, char*);
void MostrarPagos(char*);
void MostrarAlumnos(char*);
int IngresoEnteroVal(int, int);
void IngresoTextoLimpio(char*, int);
void BuscarPago(FILE*, int, sPago*);

/* Este ejercicio esta incompleto por que no le pregunta a el usuario si quiere anotar al alumno si no hay un pago registrado del mismo,
debido a esto tampoco hay una funcion BuscarAlumno para mostrar a los alumnos que no hayan pagado la cuota del 02/2024.
Para completarlo solo hay que pedir una opcion char con respuetsa s/n y en base a eso agregar a Alumnos.dat, y despues la funcion BuscarAlumno
que es identica en estructura a BuscarPago pero con un tipo de auxiliar distinto*/
int main(){
    FILE *fPagos, *fAlumnos;
    sPago pagAux;
    sAlumno alAux;
    sFecha fAux;
    int dniAux;

    fPagos = AbrirArchivo("PAGOS.dat","w+b");
    fAlumnos = AbrirArchivo("ALUMNOS.dat","w+b");

    printf("Ingrese DNI de alumno: ");
    dniAux = IngresoEnteroVal(0,99999999);
    while(dniAux != 0){
        BuscarPago(fPagos, dniAux, &pagAux);
        printf("Ingrese dia, mes y anio (en ese orden) del ultimo pago realizado por el alumno.");
        fAux.dia = IngresoEnteroVal(1,31);
        fAux.mes = IngresoEnteroVal(1,12);
        fAux.anio = IngresoEnteroVal(1989,2026);
        pagAux.up = fAux;
        if(pagAux.dni == -1){
            // No hay un registro de que el alumno haya pagado el curso.
            // Se toma el dni, la fecha del ultimo pago y se registra el mismo.
            pagAux.dni = dniAux;
            alAux.dni = dniAux;
            // Se crea un registro en ALUMNOS.dat con dni y nombre del Alumno.
            printf("El alumno parece no estar registrado, ingrese su nombre para agregarlo al registro de alumnos.");
            IngresoTextoLimpio(alAux.nom,41);
            fwrite(&alAux, sizeof(sAlumno), 1, fAlumnos);
            fflush(fAlumnos);
        }
        else{
            fseek(fPagos,sizeof(sPago)*-1,1);
        }
        fwrite(&pagAux, sizeof(sPago), 1, fPagos);
        fflush(fPagos);
        printf("Ingrese DNI de alumno: ");
        dniAux = IngresoEnteroVal(0,99999999);
    }
    // Por cada pago realizado antes de 02/2024 mostrar el nombre del alumno con ese dni.
    int regPos;

    fseek(fPagos,0,0);

    printf("Los siguientes alumnos adeudan la cutoa de febrero de 2024:\n%8s|%41s\n","DNI","NOMBRE");
    fread(&pagAux, sizeof(sPago), 1, fPagos);
    while(!feof(fPagos)){
        if((pagAux.up.anio < 2024) || (pagAux.up.anio == 2024 && pagAux.up.mes < 2)){
            regPos = (ftell(fPagos)/sizeof(sPago)) - 1;
            fseek(fAlumnos, sizeof(sAlumno) * regPos, 0);
            fread(&alAux, sizeof(sAlumno), 1, fAlumnos);
            printf("%08d|%41s\n",alAux.dni,alAux.nom);
        }
        else{
            printf("El de DNI %08d esta bien\n",alAux.dni);

        }
        fread(&pagAux, sizeof(sPago), 1, fPagos);
    }
    fclose(fPagos);
    fclose(fAlumnos);

    printf("\n");
    MostrarPagos("PAGOS.dat");

    printf("\n");
    MostrarAlumnos("ALUMNOS.dat");
    return 0;
}

FILE *AbrirArchivo(char *na, char *ma){
    FILE *arch;
    arch = fopen(na, ma);
    if(arch == NULL){
        printf("FATAL ERROR - No se pudo abrir %s en modo %s.",na,ma);
        exit(1);
    }
    return arch;
}

void MostrarPagos(char *na){
    printf("PAGOS:\n");
    FILE *arch;
    sPago aux;
    arch = fopen(na, "rb");
    if(arch == NULL){
        printf("FATAL ERROR - No se pudo abrir %s en modo lectura.",na);
        exit(1);
    }
    fread(&aux, sizeof(sPago), 1, arch);
    while(!feof(arch)){
        printf("%08d|%02d/%02d/%4d\n",aux.dni,aux.up.dia,aux.up.mes,aux.up.anio);
        fread(&aux, sizeof(sPago), 1, arch);
    }
}

void MostrarAlumnos(char *na){
    printf("ALUMNOS:\n");
    FILE *arch;
    sAlumno aux;
    arch = fopen(na, "rb");
    if(arch == NULL){
        printf("FATAL ERROR - No se pudo abrir %s en modo lectura.",na);
        exit(1);
    }
    fread(&aux, sizeof(sAlumno), 1, arch);
    while(!feof(arch)){
        printf("%08d|%41s\n",aux.dni,aux.nom);
        fread(&aux, sizeof(sAlumno), 1, arch);
    }
}

int IngresoEnteroVal(int li, int ls)
{
    int num;
    scanf("%d",&num);
    while(num < li || num > ls){
        printf("ERROR - Se ha ingresado un valor invalido: ");
        scanf("%d",&num);
    }
    return num;
}

void BuscarPago(FILE *arch, int dniBus, sPago *pagoAux){
    rewind(arch);
    int encontrado = 0;
    sPago aux;
    fread(&aux, sizeof(sPago), 1, arch);
    while(!feof(arch) && !encontrado){
        if(aux.dni == dniBus){
            encontrado = 1;
            *pagoAux = aux;
        }
        else
            fread(&aux, sizeof(sPago),1,arch);
    }
    if(!encontrado){
        aux.dni = -1;
        *pagoAux = aux;
    }
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
