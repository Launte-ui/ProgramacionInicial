#include <stdio.h>
#include <time.h>

int main(){
    int num;
    srand(time(NULL)); // Inicializa la semilla para generar números aleatorios

    num = rand(); // Genera un número aleatorio entre 0 y 99
    printf("Numero aleatorio: %d\n", num);

    return 0;

}