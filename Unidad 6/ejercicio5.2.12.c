/*
El gobierno de la Ciudad de Buenos Aires realiza una encuesta a los estudiantes de los
colegios secundarios. Los primeros datos que ingresar son la fecha (enteros, mes entre 1
y 12, y año mayor a 2024) y la cantidad de colegios de la ciudad en que se realizó la
encuesta (entero, mayor a cero).
De cada colegio se conoce: número de escuela (entero, mayor a cero), la cantidad de
alumnos inscriptos (entero, entre 1 y 35) y la especialidad (caracter, ‘T’: técnico, ‘N’: no
técnico).
De cada alumno del colegio que respondió la encuesta se conoce:
• DNI (entero, entre 1 y 99999999)
• Edad (entero, entre 10 y 25)
• Sexo (carácter, ‘M’, ‘F’ o ‘X’)
• Opinión con respecto a los conocimientos adquiridos (‘B’: buenos, ‘M’: malos)
Se identifica el fin de ingreso de datos de los alumnos que respondieron la encuesta por
cada colegio con el ingreso de DNI igual a cero del estudiante.
Informar:
a. Por cada colegio, el porcentaje de alumnos que contestaron la encuesta sobre
la cantidad de alumnos inscriptos del colegio.
b. Cantidad de estudiantes de colegio no técnicos que respondieron la encuesta.
c. Porcentaje de mujeres de escuelas técnicas sobre la cantidad de estudiantes
que respondieron la encuesta.
d. Porcentaje de estudiantes que respondieron que los conocimientos
adquiridos eran malos, sobre el total de encuestados.
e. Mayor edad de los estudiantes encuestados.
f. Número del colegio con mayor opinión buena sobre los conocimientos
adquiridos.
*/

#include <stdio.h>

int main(){
    int mes = 1, ano = 2025;
    int cantidadColegio=1;
    int colegioMejorOpinon;
    int respuestas, respuestasMujeresTecnicas;
    int numColegio = 1;


    do
    {
        if(mes < 1 || mes >12)
            printf("Se a ingresado un valor invalido para el mes. Porfavor ingrese un valor valido: ");
        else
            printf("Ingrese el numero del mes actual(Enero:1, Febrero:2,...): ");
        scanf("%d",&mes);
    } while (mes < 1 || mes >12);

    do
    {
        if(ano <= 2024)
            printf("Se a ingresado un valor invalido para el año. Porfavor ingrese un valor valido: ");
        else
            printf("Ingrese el año actual: ");
        scanf("%d",&ano);
    } while (ano <= 2024);

    {
        if(cantidadColegio <= 0)
            printf("No puede haber un numero negativo de colegios o ningun colegio. Porfavor ingrese un valor valido: ");
        else
            printf("Ingrese la cantidad de colegios encuestados: ");
        scanf("%d",&cantidadColegio);
    } while (cantidadColegio <= 0);

    for (int i = 0; i < cantidadColegio; i++)
    {
        int  cantAlumnos = 1, dni = 1;
        int edad;
        char sexo;
        char opinion; 
        char espacialidad = 'N';
        do
        {
            if(numColegio <= 0)
                printf("No existe un colegio numero 0 o de numero negativo. Porfavor inigrese un colegio valido: ");
            else
                printf("Ingrese el numero del colegio: ");
            scanf("%d",&numColegio);
        } while (numColegio <= 0);
        
        do
        {
            if(cantAlumnos <= 0)
                printf("No puede no haber ningun estudiante o estudiantes negativos. Porfavor ingrese un cantidad valida de estudiantes: ");
            else        
                printf("Cuantos alumnos estan ingresados en el colegio %d?: ", numColegio);
            scanf("%d",&cantAlumnos);
        } while (cantAlumnos <= 0);

        do
        {
            if (espacialidad != 'T' && espacialidad != 'D')
                printf("No a ingresado una opcion valida. Porfavor, ingrese 'T' si el colegio es Tecnico o 'N' si no es de especialidad tecnica: ");
            else
                printf("Ingrese la especialidad del colegio. 'T' si el colegio es Tecnico o 'N' si no es de especialidad tecnica: ");
            fflush(stdin);
            scanf("%c",&espacialidad);
            printf("%c", espacialidad);
        } while (espacialidad != 'T' && espacialidad != 'D');

        do
        {
            printf("Ingrese el DNI de un alumno del colegio numero %d(Ingrese 0 para identificar el fin del ingreso de datos): ", numColegio);
            scanf("%d",&dni);
            if (dni != 0)
            {
                
            }
        } while (dni != 0);
        
        
    }
    

    return 0;
}
