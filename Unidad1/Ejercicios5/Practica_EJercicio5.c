#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int operando1, operando2,esultado;
    char opcion;
    

    printf("Ingrese el primer operando \n");
    scanf(" %i", &operando1);

    printf("Ingrese el segundo operando\n");
    scanf(" %i", &operando2);

    printf("DIgite que opcion que desea \n1.Suma \n2.REsta \n3.MUltiplicacion \n");
    scanf(" %c", &opcion);

    switch(opcion)
    {
        case '1':
           esultado = (operando1 + operando2);
           break;  

        case '2':
           esultado = (operando1 - operando2);
           break;

        case '3':
           esultado = (operando1 * operando2);
      
 
    }
    printf("EL resultado es %i \n",esultado);


  

}