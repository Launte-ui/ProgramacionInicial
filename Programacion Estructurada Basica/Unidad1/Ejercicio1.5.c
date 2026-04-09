// 1.5
// Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos). Luego del ingreso se debe ordenar de forma ascendente 
// la colección con dichos códigos para permitir realizar búsquedas binarias.
// Luego se ingresan las ventas realizadas durante el día. Por cada venta se ingresa código de vendedor, código de artículo y cantidad.
// Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una venta de un mismo vendedor y artículo. 
// El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
// a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.
// b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRODUCTOS 15
#define VENDEDORES 5

void IniciarProductos(int[], int);
void IniciarEnCeros(int [], int);
int NumAleatorio(int, int);
void MostrarProductos(int[], int[]);
void MostrarVentas(int[]);
void OrdenarVectorMinAMax(int[], int);
void OrdenarVectorParaleloMaxAMin(int[], int[], int);
int PosMinimo(int[], int, int);
int PosMaximo(int[], int, int);
int IngreseCodigo(int[]);
int BusquedaBinariaDeProductos(int[],int);
int IngreseVendedor();


int main(){
    srand(time(NULL));
    int productos[PRODUCTOS];
    int productosVendidos[PRODUCTOS];
    IniciarEnCeros(productos, PRODUCTOS);
    IniciarEnCeros(productosVendidos, PRODUCTOS);

    int ventas[VENDEDORES];
    IniciarEnCeros(ventas, VENDEDORES);

    IniciarProductos(productos, PRODUCTOS);
    OrdenarVectorMinAMax(productos, PRODUCTOS);



    MostrarProductos(productos, productosVendidos);
    int codPos, vendedor, unidades;
    do{
        printf("Ingrese el vendedor: ");
        vendedor = IngreseVendedor();
        if(vendedor){

            printf("Ingrese el codigo del articulo: ");
            codPos = IngreseCodigo(productos);
            printf("Ingrese cantidad de unidades vendidas: ");
            scanf("%d",&unidades);
            productosVendidos[codPos]+= unidades;
            ventas[vendedor-1001]++;
        }
    }while(vendedor);

    OrdenarVectorParaleloMaxAMin(productos, productosVendidos, PRODUCTOS);
    MostrarProductos(productos, productosVendidos);

    int minVendedor = PosMinimo(ventas, VENDEDORES, 0);
    printf("El/los vendedor/es con menos ventas es/son los del codigo: ");
    for (int i = 0; i < VENDEDORES; i++){
        if(ventas[i]==ventas[minVendedor]){
            printf("%d, ", i+1001);
        }
    }



    return 0;
}

void IniciarProductos(int v[], int ce){
    int i = 0, codigo;
    do{
        codigo = NumAleatorio(100,1000);
        if (BusquedaBinariaDeProductos(v, codigo)==-1){
            v[i]=codigo;
            i++;
            OrdenarVectorMinAMax(v, i);
        }
    }while(i<ce);
}
void IniciarEnCeros(int v[], int ce){
    for (int i = 0; i < ce; i++){
        v[i] = 0;
    }
}

int NumAleatorio(int min, int max){
    int num = min + (rand() % (max-min));
    return num;
}

void MostrarProductos(int prod[], int prodV[]){
    printf("Codigo\t|Unidades vendidas\n");
    for(int i = 0; i < PRODUCTOS; i++){
        printf("%d\t|%d\n", prod[i], prodV[i]);
    }
}
void MostrarVentas( int ventas[]){
    printf("\nVend.\t|Ventas\n");
    for(int i = 0; i < VENDEDORES; i++){
        printf("%d\t|%d\n", i+1001, ventas[i]);
    }
}

void OrdenarVectorMinAMax(int v[], int ce){
    int aux, minP;
    for(int i = 0; i < ce; i++){
        minP = PosMinimo(v, ce, i);
        aux = v[minP];
        v[minP] = v [i];
        v[i] = aux;
    }
}

void OrdenarVectorParaleloMaxAMin(int productos[], int productosV[], int ce){
    int maxP, aux;
    for (int i = 0; i < ce; i++){
        maxP = PosMaximo(productosV, ce, i);
        aux = productosV[maxP];
        productosV[maxP] = productosV[i];
        productosV[i] = aux;

        aux = productos[maxP];
        productos[maxP] = productos[i];
        productos[i] = aux;
    }
}

int PosMinimo(int v[], int ce, int ini){
    int posMin = ini;
    for(int i = ini + 1; i < ce; i++){
        if(v[i]<v[posMin]) posMin = i;
    }
    return posMin;
}

int PosMaximo(int v[], int ce, int ini){
    int posMax = ini;
    for(int i = ini + 1; i < ce; i++){
        if(v[i]>v[posMax]) posMax = i;
    }
    return posMax;
}

int IngreseCodigo(int v[]){
    int codigo;
    scanf("%d",&codigo);
    int codigoPos = BusquedaBinariaDeProductos(v, codigo);
    while(codigoPos==-1)
    {
        printf("ERROR-El codigo ingresado no pertence a ningun producto valido. Ingrese un codigo valido: ");
        scanf("%d",&codigo);
        codigoPos = BusquedaBinariaDeProductos(v, codigo);
    }
    return codigoPos;
}

int BusquedaBinariaDeProductos(int v[], int elemento){
    int med, pos = -1;
    int li = 0, ls = PRODUCTOS-1;
    while(pos == -1 && li <= ls){
        med = (li+ls)/2;
        if(v[med] == elemento) pos = med;
        else{
            if(v[med] < elemento) li = med+1;
            else ls = med-1;
        }
    }
    // printf("\nSe realizo una busqueda binaria que resolvio la pos: %d\n", pos);
    return pos;
}

int IngreseVendedor(){
    int n;
    scanf("%d",&n);
    while(n != 0 && (n < 1001 || n>1005))
    {
        printf("ERROR-El numero de vendedor no es valido, porfavor ingrese un numero entre 1001 y  1005 o 0 para finalizar: ");
        scanf("%d",&n);
    }
    return n;
}