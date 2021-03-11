#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int balas;
} armita;

struct armita* nuevaArma(){
    return malloc(sizeof(armita));
}

void crear(armita* arma){
    arma->balas = 25;
}

void finiticar(armita* arma){
    free(arma);
}

void recargar(armita* arma){
    arma->balas = 25;
    printf("Recargada para matar.\n");
}

void piu(armita* arma){
    printf("¡PA!\n");
    arma->balas--;
}

void piupiupiu(armita* arma){
    printf("¡RA TATATTATATATATATATATATATATTATA COMAN PLOMO!\n");
    arma->balas--;
    arma->balas--;
    arma->balas--;
}

void piuManual(armita* arma){
    for (int i = 0; i < arma->balas; i++)
    {
        printf("POW \n");
        arma->balas--;        
    }
}