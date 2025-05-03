//  Dadas los legajos y las notas de 20 alumnos de un curso, determinar:
// a. La cantidad de alumnos aplazados.
// b. Cuando la nota sea mayor a 7, mostrar el mensaje: “El alumno con legajo xxx ha
// Promocionado”.
// c. El promedio de notas de los alumnos que han sido enviados a final, con por lo
// menos dos decimales en dicho promedio

#include <stdio.h>

int main()
{
    int contAplazos = 0, cont = 0, sumaAlumnosaAFinal = 0;
    float nota;
    for (int i = 0; i < 5; i++)
    {
        printf("Ingerese la nota del alumno de legajo %d: ", i+1);
        scanf("%f",&nota);
        if(nota>=4)
        {
            if(nota>=7)
                printf("El alumno con legajo %d a promocionado", i+1);
            else
            {
                sumaAlumnosaAFinal += nota;
                cont++;
            }
        }
        else
            contAplazos++;
    }
    float notaPromedio;
    notaPromedio = sumaAlumnosaAFinal / cont;
    printf("El promedio de las notas de los alumnos que fueron a final es de: %f", notaPromedio);
    printf("\nLa cantidad de alumnos que han aplazado la materia es de %d alumnos", contAplazos);
    return 0;
}
