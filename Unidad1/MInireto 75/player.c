#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "arma.h"

typedef struct
{
    char* nombre;
    struct armita* arma;
} jugador;

jugador* jugadorNuevo(){
    return malloc(sizeof(jugador*));
}

void crearN(jugador* j, const char* nombre){
    j->nombre = malloc((strlen(nombre)+1)*sizeof(char));
    strcpy(j->nombre,nombre);
    j->arma = NULL;
}

void finiticarN(jugador* j){
    free(j->nombre);
    printf("Jugador muerto\n");
}

void pikUpA(jugador* j, struct armita* g){
    j->arma = g;
    printf("Arma recogida\n");
}

void piuN(jugador* j){
    if (j->arma)
    {
        piu(j->arma);
    }
    else{
        printf("No tiene arma\n");
        exit(1);
    }
}

void piupiupiuS(jugador* j){
    if (j->arma)
    {
        piupiupiu(j->arma);
    }
    else{
        printf("No tiene arma\n");
        exit(1);
    }
}

void piuManual1(jugador* j){
    if (j->arma)
    {
        piuManual(j->arma);
    }
    else{
        printf("No tiene arma\n");
        exit(1);
    }
}

void dropA(jugador* j){
    j->arma = NULL;
    printf("Arma tirada\n");
}
