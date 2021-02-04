//Sirve para modificar ejemplos anteriores
#include <stdio.h>
#include <stdlib.h>

typedef struct pto_t
{
   int x;
   int y;
}
punto;

int main(void)
{
   punto punto1;
   punto punto2;
   int area;

   printf("Ingrese la posicion #1 asi x,y: ");
   scanf("%d,%d", &punto1.x, &punto1.y);
   printf("Ingrese la posicion #2 asi x,y: ");
   scanf("%d, %d", &punto2.x, &punto2.y);
   area = abs(punto1.x - punto2.x)*abs(punto1.y - punto2.y);
   printf("El área es: %d \n  ", area);
   return 0;
}