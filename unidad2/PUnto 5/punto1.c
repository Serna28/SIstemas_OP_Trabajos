#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char  *argv[])
{

    
    //Atoi convierte una cadena en su equivalente numerico

    int vector[argc-1];
    int maximo;
    int minimo;

    minimo = atoi(argv[1]);

    for(int i =1; i < argc; i++)
    {
        vector[i-1]= atoi(argv[i]);
    }
     
     double promedio;

    for(int i =0; i < argc-1;i++)
    {
     promedio += vector[i];

     if(minimo > vector[i])
     {
         minimo = vector[i];
     }

     if(maximo < vector[i])
     {
         maximo = vector[i]; 
     }
    }

    printf("Valor maximo : %d \n", maximo);
    printf("Valor minimo : %d \n", minimo);
    printf("Promedio : %f \n",promedio / (argc -1) );
}