// 1.6
// Dado un conjunto de 10 números enteros ordenados de menor a mayor, ingresar por teclado 3 números más no ordenados.
// Insertarlos donde correspondan. Mostrar en pantalla la serie inicial y la final.
#import <stdio.h>
#import <stdlib.h>
#import <time.h>

int NumAleatorio();
void OrdenarMenosMayor(int[], int);
int PosMinimo(int[], int, int);

int main(){
    srand(time(NULL));
    int iniciales[10], nuevos[3], final[13];
    for (int i = 0; i < 10; i++){
        iniciales[i] = NumAleatorio(); 
    }
    for (int j = 0; j < 3; j++){
        nuevos[j] = NumAleatorio(); 
    }
    OrdenarMenosMayor(iniciales, 10);
    OrdenarMenosMayor(nuevos, 3);

    int i = 0, j = 0, k = 0, valor;
    
        while(k<13){
        if(j>=3 || (i<10 && iniciales[i]<nuevos[j])){
            final[k]=iniciales[i];
            i++;
        }else{
            final[k]=nuevos[j];
            j++;
        }
        k++;
    }
    MostrarVector(final, 13);
    return 0;
}

int NumAleatorio(){
    int num = rand()%51;
    return num;
}

void OrdenarMenosMayor(int v[], int ce){
    int minP, aux;
    for(int i = 0; i < ce; i++){
        minP = PosMinimo(v, ce, i);
        aux = v[minP];
        v[minP] = v[i];
        v[i] = aux;
    }
}

int PosMinimo(int v[], int ce, int ini){
    int pos = ini;
    for(int i = ini + 1; i < ce; i++){
        if(v[i]<v[pos]) pos = i;
    }
    return pos;
}

void MostrarVector(int v[], int ce){
    for (int i = 0; i < ce; i++) {
        printf(" %d\n", v[i]);
    }
}