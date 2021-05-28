#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/mman.h>
#define permisos 0644

#define Semaforo_tam1 100
#define Semafoto_tam2 100

void *sendMsg(void*);
void *recvMsg(void*);

sem_t *s1, *Sem_Leer1, *emaforo_EScribir2, *Semafoto_leer2;

int main(void){
    pthread_t threadSend, threadRecv;
    int shm1, shm2, flg = O_CREAT;
    
    unsigned int value = 0;
    emaforo_EScribir2 = sem_open("emaforo_EScribir2", flg, permisos, value);
    if(emaforo_EScribir2 == SEM_FAILED)
    {
        perror("emaforo_EScribir2 open: ");
        exit(1);
    }
    Semafoto_leer2 = sem_open("Semafoto_leer2", flg, permisos, value);
    if(Semafoto_leer2 == SEM_FAILED)
    {
        perror("Semafoto_leer2 open: ");
        exit(1);
    }

    s1 = sem_open("s1", 0);
    if(s1 == SEM_FAILED)
    {
        perror("s1 open: ");
        exit(1);
    }
    Sem_Leer1 = sem_open("Sem_Leer1", flg,permisos,0);
    if(Sem_Leer1 == SEM_FAILED)
    {
        perror("Sem_Leer1 open: ");
        exit(1);
    }

    shm2 = shm_open("SharedMemory2", O_CREAT | O_RDWR, 0600);
    if(shm2 == -1)
    {
        perror("shm2 create: ");
        exit(1);
    }
    fprintf(stdout, "Se creó memoria compartida 2 con el  descriptor : [%d} \n", shm2);
    if(-1 == ftruncate(shm2, Semafoto_tam2))
    {
        perror("ftruncate2: ");
        exit(1);
    }

    shm1 = shm_open("SharedMemory1", O_RDONLY, 0600);
    if(shm1 == -1)
    {
        perror("shm1 read: ");
    }
    fprintf(stdout, "Se abrió memoria compartida 1 con el descriptor : {%d} \n", shm1);

    pthread_create(&threadSend, NULL, &sendMsg, shm2);
    pthread_create(&threadRecv, NULL, &recvMsg, shm1);

    pthread_join(threadSend,NULL);
    pthread_join(threadRecv,NULL);

    return 0;
}

void *sendMsg(void *shmD){
    int len;
    char buf[Semafoto_tam2];
    char *ptr;
    void *pMap;

    pMap = mmap(NULL, Semafoto_tam2, PROT_WRITE, MAP_SHARED, shmD, 0);
    if(pMap == MAP_FAILED)
    {
        perror("mmapS2: ");
        exit(1);
    }

    while(fgets(buf, sizeof buf, stdin) != NULL){
        len = strlen(buf);
        if(buf[len-1] == '\n') buf[len-1] = '\0';

        if(sem_post(emaforo_EScribir2) == -1){
            perror("emaforo_EScribir2 post: ");
            exit(1);
        }
        ptr = (char*)pMap;
        memcpy(ptr, buf, sizeof(buf));

        if(sem_wait(Sem_Leer1) == -1)
        {
            perror("Sem_Leer1 wait: ");
            exit(1);
        }
    }
    if(munmap(ptr, Semafoto_tam2) == -1)
    {
        perror("unmapS2: ");
        exit(1);
    }

    if(sem_close(emaforo_EScribir2) == -1)
    {
        perror("emaforo_EScribir2 close: ");
        exit(1);
    }
    if(sem_unlink(emaforo_EScribir2) == -1)
    {
        perror("emaforo_EScribir2 unlink: ");
        exit(1);
    }
    if(sem_close(Semafoto_leer2) == -1)
    {
        perror("Semafoto_leer2 close: ");
        exit(1);
    }
    if(sem_unlink(Semafoto_leer2) == -1)
    {
        perror("Semafoto_leer2 unlink: ");
        exit(1);
    }

    if(close(shmD == -1))
    {
        perror("closeS2: ");
        exit(1);
    }
    if(shm_unlink("SharedMemory2") == -1)
    {
        perror("unlinkS2: ");
        exit(1);
    }

    return 0;
}
void *recvMsg(void *shmD)
{
    char *ptr;
    void *pMap = mmap(NULL, Semaforo_tam1, PROT_READ, MAP_SHARED, shmD, 0);
    if(pMap == MAP_FAILED)
    {
        perror("mmapR2: ");
        exit(1);
    }
    ptr = (char*)pMap;

    for(;;)
    {
        if(sem_wait(s1) == -1){
            perror("s1 wait: ");
            exit(1);
        }

        fprintf(stdout, "[Mazo]: %s\n",ptr);


        if(sem_post(Semafoto_leer2) == -1)
        {
            perror("Semafoto_leer2 post: ");
            exit(1);
        }
    }
            if(munmap(ptr, Semaforo_tam1) == -1)
        {
            perror("unmapR2: ");
            exit(1);
        }
    return 0;

    //HOla cornejo, hola migue,HOla kenta, sirvo de ejemplo :3 by sernita
}