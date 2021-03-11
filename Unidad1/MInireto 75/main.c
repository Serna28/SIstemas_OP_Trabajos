#include <stdio.h>
#include <stdlib.h>
#include "arma.h"
#include "player.h"

int main(int argc, char const *argv[])
{
    struct armita* arma = nuevaArma();
    crear(arma);
    
    struct jugador* yo = jugadorNuevo();
    crearN(yo,"Sernadestructo de fuego ");

    pikUpA(yo,arma);
    
    piupiupiuS(yo);
    piuN(yo);
    piuManual1(yo);

    dropA(yo);

    finiticarN(yo);

    return 0;
}