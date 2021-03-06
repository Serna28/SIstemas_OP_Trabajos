#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>
#include <errno.h>
#include <sys/types.h>
#define PERMISOS 0644 

struct msgbuf
{
    long mtype;
    char msg[200];
};

struct parametro
{
    int msqid;
};
void *recibirmsg(void *parametro)
{
    struct msgbuf buf;
    struct parametro *isa = (struct parametro*) parametro;
    int holder;
    for(;;)
    {
        if (msgrcv(isa->msqid, &buf, sizeof(buf.msg),0,0) == -1)
        {
            perror("error en REcibirmensaje");
            exit(8);
        }
        printf("Sernita Says:  %s \n", buf.msg);
        holder = strcmp(buf.msg,"pitufo");
        if (holder==0)
        {
            break;
        }
        
    }
    printf("FIn conexion");

    exit(8);
}
void *enviarmsg(void *parametro)
{
    struct msgbuf buf;
    struct parametro *isa = (struct parametro*) parametro;
    int lenght;

    printf("Estado: Listo para enviar o recibir mensajes \n");
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
            perror("error en msgsnd");
        }       
    }

      if (msgctl(isa->msqid,IPC_RMID,NULL) == -1)
        {
            perror("error en ENviarmensaje");
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

if((key1 = ftok("cola1.txt", 'B')) == -1){
    perror("Error en FTOK");
    exit(1);
}

if ((id1 = msgget(key1,PERMISOS | IPC_CREAT)) == -1){
    perror("msgget");
    exit(1);
    
}

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

pthread_create(&henviar,NULL,&enviarmsg,&paramhilo2);
pthread_create(&hrecibir,NULL,&recibirmsg,&paramhilo1);

pthread_join(henviar,NULL);
pthread_join(hrecibir,NULL);

exit(1);

}