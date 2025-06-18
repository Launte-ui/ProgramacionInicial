#include<stdio.h>
char IngreseOpcionVal();
int main()
{
    int d,m,a;
    return 0;
}

char IngreseOpcionVal(){
    char op;
    printf("'I' para Ingreso - 'E' para Egreso");
    do
    {
        scanf("%c",&op);
    } while (op != 'I' && op != 'E');
    return op;
}