  
#ifndef JUGADOR_H_
#define JUGADOR_H_

struct jugador;
struct armita;

struct jugador* jugadorNuevo();
void crearN(struct jugador*, const char*);
void finiticarN(struct jugador*);
void pikUpA(struct jugador*, struct armita*);
void piuN(struct jugador*);
void piupiupiuS(struct jugador*);
void piuManual1(struct jugador*);
void dropA(struct jugador*);

#endif