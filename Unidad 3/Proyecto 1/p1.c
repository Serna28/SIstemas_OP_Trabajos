#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 100

int main(int argc, char *argv[])
{
    int psn[2],pfd[2];
    char Entrada[BUF_SIZE], Salida[BUF_SIZE];
    ssize_t num;

    if (pipe(psn) == -1)
    {
        perror("TUberia psn");
        exit(0);
    }
    if (pipe(pfd) == -1)
    {
        perror("TUberia pfd");
        exit(0);
    }
    switch (fork())
    {
    case -1:
        perror("Erroe en el 'fork'");
        exit(0);
    case 0: //HIjo 
        if (close(pfd[1]) == -1)
        {
            perror("Error en el hijo");
            exit(0);
        }
        if (close(psn[0]) == -1)
        {
            perror("Error en la lectura del hijo");
            exit(0);
        }
        for(;;)
        {
            num = read(pfd[0],Salida,BUF_SIZE);
            int i = 0;
            while(Salida[i])
            {
                Salida[i] = toupper(Salida[i]);
                i++;
            }
            write(psn[1],Salida,BUF_SIZE);
        }
        if (close(pfd[0]) == -1)
        {
            perror("close");
            exit(0);
        }
        if (close(psn[1]) == -1)
        {
            perror("close");
            exit(0);
        }
         
    default: //Papà
        if (close(pfd[0]) == -1)
        {
            perror("close read - parent");
            exit(0);
        }
        if (close(psn[1]) == -1)
        {
            perror("close write - parent");
            exit(0);
        }
        //COnversion de minuscula a mayuscula
        for(;;)
        {
            scanf("%s",Entrada);
            int isa = 0;
            while(Entrada[isa])           
            {
                Entrada[isa] = tolower(Entrada[isa]);
                isa++;
            }
            write(pfd[1],Entrada,BUF_SIZE);
            read(psn[0],Salida,BUF_SIZE);
            printf("Original : %s \n",Entrada);
            printf("COnversion : %s\n", Salida);
        }
        if (close(pfd[1]) == -1)
        {
            perror("Cerrar");
            exit(0);
        }
        if (close(psn[0]) == -1)
        {
            perror("Cerrar");
            exit(0);
        }
    }
}