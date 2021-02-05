#include <stdio.h>

int main()
{
    int num;
    char key;
    printf("Prueba a scanf. Ingrese el numero 325 y presione ENTER:\n");
    scanf("%d",&num);
    printf("Ingrese cualquier tecla para terminar y presione ENTER:\n");
    scanf("%c",&key);

  

    printf("LO que ocurre es que este solamente realiza el primer enter(numero) y el programa te salta para el final sin tener el otro caracter \n");
    printf("Esto ocurre debido al flujo, que toma enter como otro dato, y como no tenemos salto de linea, al ponerlo lo toma ya como caracter, lo cual direcciona al final \n");

    printf("Solucione el error de una manera un poco rara, y tirando mas a la suerte, ya que tengo un factor con el orden en cuanto a codigo a veces y al darle espacio antes de las comillas donde estaba %d y ejecutar funciono, esto debido a que con el espacio, no toma al enter, y soluciona el flujo \n");
  
    printf(" \n");

    printf("Prueba a scanf. Ingrese el numero 325 y presione ENTER:\n");
    scanf("%d",&num);
    printf("Ingrese cualquier tecla para terminar y presione ENTER:\n");
    scanf("%c ",&key);
}