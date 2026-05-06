/*Se desea hacer un estudio de los alumnos de la Universidad que están cursando
el 4to. año de la carrera de Ingeniería (como máximo hay 5000 alumnos).
Para ello, de cada alumno se ingresan los siguientes datos:
        DNI (entero, entre 1 y 99.999.999)
        Apellido y Nombre (string, de 30 caracteres)
        Domicilio (string, de 30 caracteres)
        Sexo (carácter, ‘F’ o ‘M’)
        Fecha de Nacimiento (enteros, día, mes y año)
        Cantidad de materias aprobadas (entero, mayor o igual a cero)
        Promedio de notas de las materias aprobadas (real, mayor a cero)
La información finaliza con un DNI igual a cero.

Informar:
Los datos de los alumnos ordenados descendente por promedio.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ALUS 5000


typedef struct{
    int dia;
    int mes;
    int anio;
}FECHA;

typedef struct {
    int dni;
    char nombreCompleto[31];
    char domicilio[31];
    char sexo;
    int aprobadas;
    float promedio;
    FECHA nacimiento;
}ALUMNO;

int NumAleatorio(int,int);
int ValidarFecha(int, int, int);
int DiasDelMes(int, int);
int Bisiesto(int);
void MostrarChar(char[], int);
int LeeryValidarIntRango(int,int);
void OrdenarVectorMinAMax(ALUMNO[], int);
int PosMinimo(ALUMNO[], int, int);

int main(){
    srand(time(NULL));
    ALUMNO alumnos[ALUS];
    //printf("%d", NumAleatorio(0,100000000));
    int dni, i = 0;
    int dia, mes, anio;
    int fechaFlag;
    FECHA fechaAlu;
    do{
        printf("Ingrese su DNI\n");
        dni = LeeryValidarIntRango(0,100000000);
        if(dni){
            alumnos[i].dni = dni;

            printf("Ingrese su apellido y nombre\n");
            getchar();
            gets(alumnos[i].nombreCompleto);

            printf("Ingrese su domicilio\n");
            gets(alumnos[i].domicilio);

            printf("Ingrese su genero(F/M)\n");
            if(NumAleatorio(0,10)%2)alumnos[i].sexo = 'F';
            else alumnos[i].sexo = 'M';

            alumnos[i].aprobadas = NumAleatorio(0,11);

            float prom;
            prom = 10/NumAleatorio(1,11);
            alumnos[i].promedio = prom;

            do{
                fechaAlu.anio = NumAleatorio(1582,2027);
                fechaAlu.mes = NumAleatorio(1,13);
                fechaAlu.dia = NumAleatorio(1,32);
                ValidarFecha(dia, mes, anio);
                if(!fechaFlag) printf("\nMAL, TU FECHA ESTA MAAAAAAAAL");
            }while(!fechaFlag);
            alumnos[i].nacimiento = fechaAlu;

            i++;
        }
        //printf("El DNI generado fue: %d\n", dni);
    }while(dni && i < ALUS);
    OrdenarVectorMinAMax(alumnos,i);
    printf("\n  id\t|     DNI\t|Nombre y Apellido\t|Domicilio\t|Sexo\t|Aprobadas\t|Promedio\t|Nacimiento");
    for(int j=0; j<i;j++){
        printf("\n%4d\t",j);
        printf("%8d", alumnos[j].dni);
        MostrarChar(alumnos[j].nombreCompleto,31);
        printf("\t");
        MostrarChar(alumnos[j].domicilio,31);
        printf("\t");
        printf("%c\t", alumnos[j].sexo);
        printf("%2d\t", alumnos[j].aprobadas);
        printf("%.2f\t", alumnos[j].promedio);
        printf("%d/%d/%d",alumnos[j].nacimiento.dia,alumnos[j].nacimiento.mes,alumnos[j].nacimiento.anio);
        printf("\n");
    }

    printf("Saliste del ciclo o se llenaron los %d espacios\n", ALUS);
    printf("Por si te interesa se llenaron %d espacios",i);

    return 0;
}

int NumAleatorio(int min, int max){
    int num = min+(rand()%(max-min));
    return num;
}

int ValidarFecha(int d, int m, int a){
    int val = 0;
    if(a >= 1582){
        if(m > 0 && m < 13){
            if(d > 0 && d < DiasDelMes(m,a)){
                val = 1;
            }
        }
    }
    return val;
}

int DiasDelMes(int m, int a){
    int cdm;
    if(m == 4 ||m == 6 ||m == 9 ||m == 11){
        cdm = 30;
    }
    else{
        if(m == 2)
            cdm = 28 + Bisiesto(a);
        else
            cdm = 31;
    }
    return cdm;
}

int Bisiesto(int a){
    int b;
    if(a%4==0 && a%100!=0 || a%400)
        b = 1;
    else
        b = 0;
    return b;
}

void MostrarChar(char s[], int ce){
    for (int i = 0; i < ce; i++) printf("%c",s[i]);
}

int LeeryValidarIntRango(int lim_menor,int lim_mayor){
    int n;
    scanf("%d",&n);
    while(n<lim_menor || n>lim_mayor){
        printf("ERROR-El numero debe estar entre el valor %d a %d: ",lim_menor,lim_mayor);
        scanf("%d",&n);
    }
    return n;
}

void OrdenarVectorMinAMax(ALUMNO v[], int ce){
    ALUMNO aux;
    int minP;
    for(int i = 0; i < ce; i++){
        minP = PosMinimo(v, ce, i);
        aux = v[minP];
        v[minP] = v [i];
        v[i] = aux;
    }
}

int PosMinimo(ALUMNO v[], int ce, int ini){
    int posMin = ini;
    for(int i = ini + 1; i < ce; i++){
        if(v[i].promedio<v[posMin].promedio) posMin = i;
    }
    return posMin;
}
