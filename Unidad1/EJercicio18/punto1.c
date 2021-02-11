#include <stdio.h>
 #define MAX 100

 void imprimir(int *pelementos,int a)
 {

     printf("\n El vector es : \n");

     for(int i = 0; i < a ;i++) 
     {
         printf("Elemto[%d]: %d\n",i,  *(pelementos+i) );
     }
 }

 int main(){
     int a;
     int elementos[MAX];
     int cambio;

     printf("Ingrese el tamaño del vector: \n");
     scanf("%d", &a);


     for(int i = 0; i < a; i++)
     {
         printf("El elemento en la poscicion [%i] es : ",i);
         scanf("%d", &elementos[i]);
     }
     imprimir(elementos, a);

     printf("\n Ingrese que posicion desea cambiar: /Recuerde que va des la posicion 1 hasta el tamaño) \n");
     scanf("%d", &cambio);
     cambio=cambio-1;
     for(int i = a;i >= cambio; i--)
     {
         elementos[i+1] = elementos[i];
     }
     printf("Ingrese el nuevo valor del vector : ");
     scanf("%d", &elementos[cambio]);

     imprimir(elementos,a);
     return 0;
 }