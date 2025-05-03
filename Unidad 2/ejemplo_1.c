#include <stdio.h>
#include <conio.h>
int main ()
{
 float precioXbolsa, precioXkg, Total;
 int kgs;
 printf("\nIngrese el precio de la bolsa de 5 kgs de fruta: \t");
 scanf("%f", & precioXbolsa);
 printf("\nIngrese el precio del kilo de fruta: \t");
 scanf("%f", & precioXkg);
 printf("\nIngrese los kilos comprados de fruta (numero entero): \t");
 scanf("%d", & kgs);
 Total=((kgs/5)*precioXbolsa) + ((kgs%5)*precioXkg);
 printf("\n\nEl total a pagar por %d kilos de fruta es: $ %.2f\n", kgs, Total);
 getchar();
 return 0;
}
