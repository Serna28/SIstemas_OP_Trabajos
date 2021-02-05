#include <stdio.h>

int main(void)
{
    int a;
    printf("enter a number: ");
    while (scanf("%d", &a) != 1)
    {
        // input was not a number, ask again:
        printf("enter a number: ");
    }
    printf("You entered %d.\n", a);


    printf("Lo que ocurre con este programa es que lee un numero que le damos por consola y lo imprime, pero si ingresamos algo que no sea un numero, este entra al ciclo whhile, pero este ciclo while se repetira demasiadas veces")
}