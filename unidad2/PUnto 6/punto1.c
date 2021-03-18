#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    //Variables que procesan Identificadores
    pid_t pid_hijo1;
    pid_t pid_hijo2;
    pid_t pid_hijo3;
    
    //getpid devuelve el identificador de proceso del proceso actual. (Esto es usado normalmente
    // por rutinas que generan nombres únicos  de  ficheros  temporales.)   getppid  devuelve  el
    //identificador de proceso del padre del proceso actual.

    printf("Padre : %d \n",(int)getpid());

    //crea procesos
    pid_hijo1 = fork();

    switch (pid_hijo1)
    {
    case -1:
    printf("Error");
    return -1;

///Fork en el clon, retorna 0
    case 0:

    printf("El PROCESO HIjo 1 \n");
    //No poner esto en 0, CUIADO
    int isa=1;
    //Tampoco inciar el for en 0
    for(size_t i = 1 ; i <=10;i++)
    {
        isa = isa*i;
        printf("HIjo 1 Factorial de : %d es %d \n",i,isa);
    }
    printf("HIjo 1, PID = %d \n",(int)getpid());

    break;
    
    default:
    printf("Padre: HIjo con PID %d \n",(int)pid_hijo1);
        break;
    }

    printf("Proceso : %d \nTerminado \n",(int)getpid());

}