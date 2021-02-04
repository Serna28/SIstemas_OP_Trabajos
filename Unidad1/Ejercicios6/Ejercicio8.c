/*
#include <stdio.h>



void f1(int ,int *, int *);

int main() {
    printf("A mimir");

  int d1 = 3, d2 = 1, d3 = 4;
  printf(“d1=%d, d2=%d, d3=%d\n”,d1,d2,d3); // Malas comillas
  f1(--d2,d3,d1); //d3 y d1 debent ener &
  printf(“d1=%d, d2=%d, d3=%d\n”,d1,d2,d3);//Malas comillas
  return 0;
}

void f1(int x,int *y, int *z) {
  *y = x + z; // Z debe tener *
  *z = --(*y);
  x = *y - *z; 
}

*/
//Corregido
/*
#include <stdio.h>

void f1(int ,int *, int *);

int main() 
{
   int d1 = 3, d2 = 1, d3 = 4;
  printf("d1=%d, d2=%d, d3=%d\n",d1,d2,d3);  //Comillas
  f1(--d2,&d3,&d1); //Falto poner & en d3 y d1
  printf("d1=%d, d2=%d, d3=%d\n",d1,d2,d3); //Malas Comillas y mal puestas
  return 0;
}

void f1(int x,int *y, int *z) {
  *y = x + *z; //Error casteo falta * en z
  *z = --(*y);
  x = *y - *z; 
}

*/