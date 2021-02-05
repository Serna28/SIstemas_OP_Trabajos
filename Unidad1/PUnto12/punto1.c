#include <stdio.h>

int main(void)
{
    char name[40];
    printf("What's your name? ");
    scanf("%39s", name);
    printf("Hello %s!\n", name);


    printf("Ahora que tenemos mas espacios en el arreglo, ahora este si imprimira correctamente todos los nombres");
}