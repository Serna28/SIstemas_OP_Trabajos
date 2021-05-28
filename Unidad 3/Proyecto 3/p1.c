#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/mman.h>
#define permisos 0644

#define Semaforo_tam1 200
#define Semafoto_tam2 200

void *sendMsg(void*);
void *recvMsg(void*);

sem_t *s1, *Sem_Leer1, *emaforo_EScribir2, *Semafoto_leer2;

int main(void)
{

    int shm1, shm2, flg = O_CREAT;
    pthread_t threadSend, threadRecv;
    unsigned int value = 0;
    s1 = sem_open("s1", flg, permisos, value);
    if(s1 == SEM_FAILED){
        perror("s1 open: ");
        exit(1);
    }
    Sem_Leer1 = sem_open("Sem_Leer1", flg, permisos, value);
    if(Sem_Leer1 == SEM_FAILED){
        perror("Sem_Leer1 open: ");
        exit(1);
    }

    emaforo_EScribir2 = sem_open("emaforo_EScribir2", 0);
    if(emaforo_EScribir2 == SEM_FAILED){
        perror("emaforo_EScribir2 open: ");
        exit(1);
    }
    Semafoto_leer2 = sem_open("Semafoto_leer2", 0);
    if(Semafoto_leer2 == SEM_FAILED){
        perror("Semafoto_leer2 open: ");
        exit(1);
    }

    shm1 = shm_open("SharedMemory1", O_CREAT | O_RDWR, 0600);
    if(shm1 == -1){
        perror("shm1 create: ");
        exit(1);
    }
    fprintf(stdout, "Se creó el espacio de memoria compartida 1 con el descriptor: {%d} \n", shm1);
    if(-1 == ftruncate(shm1, Semaforo_tam1)){
        perror("ftruncate1: ");
        exit(1);
    }

    shm2 = shm_open("SharedMemory2", O_RDONLY, 0600);
    if(shm2 == -1){
        perror("shm2 read: ");
    }
    fprintf(stdout, "Se abrió memoria compartida 2 con el descriptor : {%d} \n", shm2);

    pthread_create(&threadSend, NULL, &sendMsg, &shm1);
    pthread_create(&threadRecv, NULL, &recvMsg, &shm2);

    pthread_join(threadSend,NULL);
    pthread_join(threadRecv,NULL);

    return 0;
}

void *sendMsg(void *shmD)
{
    int len;
    char buf[Semaforo_tam1];
    char *ptr;
    void *pMap;
    
    pMap = mmap(NULL, Semaforo_tam1, PROT_WRITE, MAP_SHARED, *(int *)shmD, 0);
    if(pMap == MAP_FAILED)
    {
        perror("mmapS1: ");
        exit(1);
    }
    ptr = (char*)pMap;

    while(fgets(buf, sizeof buf, stdin) != NULL)
    {
        len = strlen(buf);
        if(buf[len-1] == '\n') buf[len-1] = '\0';
        memcpy(ptr, buf, sizeof(buf));

        if(sem_post(s1) == -1){
            perror("s1 post: ");
            exit(1);
        }
        
        if(sem_wait(Semafoto_leer2) == -1){
            perror("Semafoto_leer2 wait: ");
            exit(1);
        }
    }

    
    if(munmap(ptr, Semaforo_tam1) == -1)
    {
        perror("unmapS1: ");
         exit(1);
    }   

    if(sem_close(s1) == -1){
        perror("s1 close: ");
        exit(1);
    }
    if(sem_unlink(s1) == -1){
        perror("s1 unlink: ");
        exit(1);
    }
    if(sem_close(Sem_Leer1) == -1){
        perror("Sem_Leer1 close: ");
        exit(1);
    }
    if(sem_unlink(Sem_Leer1) == -1){
        perror("Sem_Leer1 unlink: ");
        exit(1);
    }

    if(close(shmD == -1)){
        perror("closeS1: ");
        exit(1);
    }
    if(shm_unlink("SharedMemory1") == -1){
        perror("unlinkS1: ");
        exit(1);
    }

    return 0;
}
void *recvMsg(void *shmD){
    char *ptr;

void *pMap = mmap(NULL, Semafoto_tam2, PROT_READ, MAP_SHARED, *(int *)shmD, 0);
        if(pMap == MAP_FAILED)
        {
            perror("mmapR1: ");
            exit(1);
        }
    ptr = (char*)pMap;
    for(;;)
    {

        if(sem_wait(emaforo_EScribir2) == -1)
        {
            perror("emaforo_EScribir2Semafoto_leer2 wait: ");
            exit(1);
        }

        fprintf(stdout, "[Sernita]: %s\n",ptr);


        if(sem_post(Sem_Leer1) == -1){
            perror("Sem_Leer1 post: ");
            exit(1);
        }
    }
    if(munmap(ptr, Semafoto_tam2) == -1){
    perror("unmapR1: ");
    exit(1);
        }
    return 0;
}