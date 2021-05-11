#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>
#include <errno.h>
#include <sys/types.h>
#define PERMISOS 0644 

struct parametro
{
    int msqid;
};
struct msgbuf
{
    long mtype;
    char msg[300];
};

void *recibirmsg(void *parametro)
{
    struct msgbuf buf;
    struct parametro *isa = (struct parametro*) parametro;
    buf.mtype = 1;
    int holder;

    for(;;)
    {
        if (msgrcv(isa->msqid, &buf, sizeof(buf.msg),1,0) == -1)
        {
            perror("error en RecibirmENSAJE");
            exit(8);
        }
        printf("Mazo Says:  %s \n", buf.msg);
        holder = strcmp(buf.msg,"XD");
        if (holder==0)
        {
            break;
        }        
    }
    printf("FIn conexcion");

    exit(8);
}

void *enviarmsg(void *parametro){//FUNCION ENVIAR MENSAJE
    struct msgbuf buf;
    struct parametro *isa = (struct parametro*) parametro;
    int lenght;

    printf("EStado: Listo para enviar o recibir mensajes \n");
    printf("Ingresa un mensaje\n");
    
    buf.mtype=1;

    while (fgets(buf.msg,sizeof buf.msg, stdin) !=NULL)
    {
        lenght = strlen(buf.msg);
        if (buf.msg[lenght-1] == '\n')
        {
            buf.msg[lenght-1] = '\0';
        }
        if (msgsnd(isa->msqid, &buf, lenght+1,0) == -1)
        {
            perror("error en EnviarMEnsjae");
        }
    }
      if (msgctl(isa->msqid,IPC_RMID,NULL) == -1)
        {
            perror("error en msctl");
            exit(8);
        }
    exit(8);
    
} 


int main(void)
{

key_t key1;
key_t key2;
pthread_t henviar;
pthread_t hrecibir;
int id1;
int id2;

system("touch cola1.txt"); //Creamos la cola 1

if((key1 = ftok("cola1.txt", 'B')) == -1){
    perror("Error en FTOK");
    exit(1);
}

if ((id1 = msgget(key1,PERMISOS | IPC_CREAT)) == -1){
    perror("msgget");
    exit(1);
    
}

system("touch cola2.txt"); //Creamos la cola 2

if((key2 = ftok("cola2.txt", 'B')) == -1){
    perror("Error en FTOK");
    exit(1);
}

if ((id2 = msgget(key2,PERMISOS | IPC_CREAT)) == -1){
    perror("msgget");
    exit(1);  
}

struct parametro paramhilo1;
struct parametro paramhilo2;

paramhilo1.msqid=id1;
paramhilo2.msqid=id2;

pthread_create(&henviar,NULL,&enviarmsg,&paramhilo1);
pthread_create(&hrecibir,NULL,&recibirmsg,&paramhilo2);

pthread_join(henviar,NULL);
pthread_join(hrecibir,NULL);

exit(1);

}
