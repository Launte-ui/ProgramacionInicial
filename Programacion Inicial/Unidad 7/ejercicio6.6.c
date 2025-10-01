/*Se realizó un concurso de tiro al blanco. Por cada participante se ingresa un número
(entero, mayor a cero) que lo identifica. El ingreso finaliza con un número de participante
negativo.
 Cada participante efectúa 5 disparos, registrándose las coordenadas X-Y de cada disparo.
• No considerar disparos sobre los ejes, pero sí en el centro (si es sobre los ejes
las coordenadas deberán volver a ingresarse).
• Para determinar el cuadrante utilizar la función CUADRANTE que reciba las dos
coordenadas y retorne el cuadrante al cual pertenece (1 a 4) y 0 para indicar un
tiro en el centro.
Para calcular el puntaje utilizar la función PUNTAJE que reciba 5 parámetros que
representan la cantidad disparos en cada cuadrante y en el centro. La función debe retornar
el puntaje obtenido según la siguiente escala:
✓ Cuadrantes 1 y 2: 50 puntos
✓ Cuadrantes 3 y 4: 40 puntos
✓ Centro: 100 puntos
Determinar:
a. El puntaje obtenido por cada participante, detallando cuantos disparos realizó en
cada cuadrante.
b. Mostrar el número del participante ganador y el puntaje obtenido.
c. Calcular y mostrar la cantidad total de disparos en el centro de todos los
participantes*/

#include <stdio.h>

int ingreseNumParticipante(int min)
{
    int _dato;
    int flag = 0;
    do
    {
        if(flag) printf("Se a ingresado un numero no valido para el participante, ingrese un dato vaildo: ");
        else printf("Ingrese el numero de participante: ");
        scanf("%d",&_dato);
        flag=1;
    } while (_dato < min);
    return _dato;
}

int IngreseCoord(char coord)
{
    int _dato;
    printf("Ingrese la coordenada %c: ", coord);
    scanf("%d",&_dato);
    return _dato;
}

int Cuadrante(int x, int y)
{
    int cuadrante;
    if (x == 0 && x == y)
        cuadrante = 0;
    else{
        if(x > 0 && y > 0)
            cuadrante = 1;
        else{
            if(x < 0 && y > 0)
                cuadrante = 2;
            else{
                if(x < 0 && y < 0)
                    cuadrante = 3;
                else{
                    if(x > 0 && y < 0)
                        cuadrante = 4;
                }
            }
        }
    }
    return cuadrante;
}

int main()
{
    int participante;

    participante = ingreseNumParticipante(0);
    while(participante != 0)
    {
        int centro, cuad1, cuad2, cuad3, cuad4;
        for (int i = 0; i < 5; i++)
        {
            int coordX;
            int coordY;
            int cuadrante;
            int puntaje;
            printf("Intento %d/5\n",i+1);
            do {
                int flag = 0;
                if (flag)
                printf("Se han ingresado coordenadas invalidos.\n");
                coordX = IngreseCoord('X');
                coordY = IngreseCoord('Y');
                flag = 1;
            }while ((coordX == 0 && coordX != coordY) || (coordY == 0 && coordY != coordX));
            cuadrante = Cuadrante(coordX, coordY);
            switch(cuadrante)
            {
                case 0:
                    centro++;
                    break;
                case 1:
                    cuad1++;
                    break;
                case 2:
                    cuad2++;
                    break;
                case 3:
                    cuad3++;
                    break;
                case 4:
                    cuad4++;
                    break;
            }
        }
        

        participante = ingreseNumParticipante(0);
    }
    return 0;
}
