#include <stdio.h>

void romperStack(int i)
{
    printf("%d\n", i);
    int x = i + 1;
    romperStack(x);
}

int main()
{
    romperStack(0);
    return 0;
}