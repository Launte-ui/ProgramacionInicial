#include<stdio.h>
char IngreseOpcionVal();
int main()
{
    char c;
    c = IngreseOpcionVal();
    printf("%c",c);
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