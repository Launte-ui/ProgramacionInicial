/*6.9
Se dispone de un archivo denominado INSCRIPTOS.dat que contiene la información de los inscriptos a un
curso de programación. El archivo aún no está completo ya que la inscripción se realiza por partes. Por cada
inscripto se tiene la siguiente información:

• DNI (entero)
• Apellido y Nombres (texto de 20 caracteres máximo)
• Pagado (campo entero donde 1 indica que pagó y 0 que aún adeuda la matrícula)

Se desea realizar un programa que cumpla con dos funciones:
a. Registrar los pagos de los alumnos ya inscriptos.
b. SI hay cupo, agregar nuevos inscriptos (el cupo máximo es de 60 alumno).
El programa solicitará el ingreso del DNI y lo buscará entre los inscriptos, en caso de que lo encuentre dará
la opción para registrar el pago (si es que no está pago ya). En caso de que no lo encuentre dará la opción
para inscribirlo al curso (el pago se realiza luego). En el momento que ya no quede cupo en el curso si llega
un nuevo inscripto se le preguntará si desea quedar registrado para un curso futuro, y en caso afirmativo
se le solicitará el teléfono y se guardará el nombre, DNI y teléfono en un archivo Interesados.dat.
El ingreso de datos finaliza con un DNI negativo.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dni;
    char nya[21];
    int pa;
}sAlumno;

FILE *AbrirArchivo(char*, char*);
void MostrarArchivo(char *na);
void BuscarAlumno(FILE*, int, sAlumno*);
void IngresoTexto(char*, int);
int IngresoEnteroVal(int, int);

int main()
{
    FILE *fInscr, *fInter;
    sAlumno alAux;
    int dniAux, cuposLib = 60, telAux;
    char nom[21], op;

    MostrarArchivo("INSCRIPTOS.dat");

    fInscr = AbrirArchivo("INSCRIPTOS.dat", "r+b");
    fInter = AbrirArchivo("INTERESADOS.dat", "r+b");

    fseek(fInscr,0,2);
    cuposLib -= ftell(fInscr)/sizeof(sAlumno);
    printf("Quedan %d cupos libres.\n", cuposLib);

    printf("Ingrese DNI de quien va a inscribirse: ");
    scanf("%d",&dniAux);
    while(dniAux >= 0)
    {
        printf("Ingrese Nombre y Apellido de quien va a inscribirse: ");
        IngresoTexto(nom,21);
        if(cuposLib > 0){
            BuscarAlumno(fInscr,dniAux,&alAux);
            if (alAux.dni > 0)
            {
                if(alAux.pa == 1)
                {
                    printf("El alumno ya esta inscripto y ya abono su inscripcion.\n");
                }
                else
                {
                    printf("El alumno ya esta inscripto pero aun no abono su inscripcion.\n¿Desea abonar la inscipcion ahora?(S/N)\n");
                    scanf("%c",&op);
                    if(op == 's' || op == 'S'){
                        printf("Pago realizado.\n");
                        alAux.pa = 1;
                        fseek(fInscr,sizeof(sAlumno)*-1,1);
                        fwrite(&alAux, sizeof(sAlumno), 1, fInscr);
                        fseek(fInscr, 0,0);
                    }
                }
            }
            else
            {
                alAux.dni = dniAux;
                strcpy(alAux.nya,nom);
                alAux.pa = 0;
                fwrite(&alAux, sizeof(sAlumno), 1, fInscr);
                fflush(fInscr);
                cuposLib--;
                printf(" Se anoto exitosamente en la lista de Inscriptos. GRACIAS.\n ");
            }
        }
        else
        {
            printf("Ya no hay cupos libres para este curso.");
            BuscarAlumno(fInter,dniAux,&alAux);
            if(alAux.dni > 0)
            {
                printf(" Vemos que ya ha intentado inscribirse, en cuanto se liberen cupos le notificaremos por medio del telefono registrado.\n");
            }
            else
            {
                printf(" Porfavor, ingrese su numero de telefono y le notificaremos cuando se liberen cupos: ");
                telAux = IngresoEnteroVal(1100000000,1199999999);
                alAux.dni = dniAux;
                strcpy(alAux.nya,nom);
                alAux.pa = telAux;
                fwrite(&alAux, sizeof(sAlumno), 1, fInter);
                fflush(fInter);
                printf(" Se anoto exitosamente en la lista de Interesados. GRACIAS.\n ");
            }

        }

        printf("Quedan %d cupos libres.\n", cuposLib);
        printf("Ingrese DNI de quien va a inscribirse: ");
        scanf("%d",&dniAux);
    }

    fclose(fInscr);
    fclose(fInter);

    printf("Alumnos inscriptos-----------------------------------------------:\n");
    MostrarArchivo("INSCRIPTOS.dat");
    printf("Alumnos interesados-----------------------------------------------:\n");
    MostrarArchivo("INTERESADOS.dat");
    printf("Quedan %d cupos libres.\n", cuposLib);

    return 0;
}

void MostrarArchivo(char *na)
{
    FILE *arch;
    sAlumno alAux;
    arch = fopen(na,"rb");
    if(arch == NULL)
    {
        printf("ERROR - No se puedo abrir el archivo %s en modo LECTURA",na);
        exit(1);
    }
    fread(&alAux, sizeof(sAlumno), 1, arch);
    while(!feof(arch))
    {
        printf("%d|%21s|%10d\n",alAux.dni,alAux.nya,alAux.pa);
        fread(&alAux, sizeof(sAlumno), 1, arch);
    }
    fclose(arch);
}

FILE *AbrirArchivo(char *na, char *ma)
{
    FILE *arch;
    arch = fopen(na,ma);
    if(arch == NULL)
    {
        printf("ERROR - No se puedo abrir el archivo %s en modo %s",na,ma);
        exit(1);
    }
    return arch;
}

void IngresoTexto(char str[], int largo)
{
    int i = 0;
    getchar();
    fgets(str, largo, stdin);
    while(str[i] != '\0' && i < largo)
    {
        if(str[i] == '\n')
            str[i] = '\0';
        else
            i++;
    }
}

void BuscarAlumno(FILE *arch, int dni, sAlumno *alu)
{
    sAlumno alAux;
    int encontrado = 0;
    fseek(arch,0,0);
    fread(&alAux, sizeof(sAlumno), 1, arch);
    while(!feof(arch) && !encontrado)
    {
        if(alAux.dni == dni)
        {
            encontrado = 1;
            *alu = alAux;
        }
        else
            fread(&alAux, sizeof(sAlumno), 1, arch);
    }
    if(!encontrado){
        alAux.dni = -1;
        *alu = alAux;
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