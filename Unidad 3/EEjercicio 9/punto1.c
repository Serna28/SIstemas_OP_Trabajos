#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE 30

int main(int argc, char *argv[])
{
    char buf[BUF_SIZE];
    int pfd[2], nBytes;   
    pid_t pid_hijo1;

    if (argc != 3 || strcmp(argv[1], "--help") == 0)
    {
        printf("COmando erroneo: %s mensajePadre mensajeHijo\n", argv[0]);
        exit(EXIT_FAILURE);
    } 
    if(pipe(pfd)<0)
    {
        printf("Error pipe\n");
        return 0;
    }
    
    pid_hijo1 = fork();

    if(pid_hijo1==0)
    {
        printf("SOy el hijo, mi apa dijo que : %s\n", argv[2]);
        nBytes = read(pfd[0], buf, BUF_SIZE);
        if(nBytes>0)
        {
            printf("MI papà dijo que : %s\n", buf);
        }
        else
        {
            return 0;
        }
        close(pfd[0]);
        write(pfd[1], argv[2], BUF_SIZE);
        close(pfd[1]);
        return 0;
    }
    else
    {
        printf("Soy el papà, el mensaje de mi hijo es: %s\n", argv[1]);
        write(pfd[1], argv[1], BUF_SIZE);
        close(pfd[1]);
        wait(NULL);
        nBytes = read(pfd[0], buf, BUF_SIZE);
        if(nBytes>0)
        {
            printf("MI hijo dijo que : %s\n", buf);
        }
        else
        {
            return 0;
        }
        close(pfd[0]);
        return 0;
    }
}