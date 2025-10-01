#include<stdio.h>

int main(){
    int s,j,k,i,l;
    s=0;
    for(j=1; j<=5;j++);
    {printf("%d",j);
        if(j%2==0){s=s+j;}
    }
    printf("\n%d",s);
    i=10;
    while(i>0)
    i=i-1;
    printf("\n%d",i);
    printf("\n\n");
    system("pause");
    return 0;

}