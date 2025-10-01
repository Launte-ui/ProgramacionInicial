
int ingreseDatoInt(int min)
{
    int _dato;
    int flag = 0;
    do
    {
        if(flag) printf("Dato invalido, ingrese un dato vaildo");
        else printf("Ingrese dato: ");
        scanf("%d",&_dato);
        flag=1;
    } while (_dato < min);
    return _dato;
}