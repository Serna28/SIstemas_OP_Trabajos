#ifndef ARMA_H_
#define ARMA_H_

struct armita;

struct armita* nuevaArma();

void crear(struct armita*);
void finiticar(struct armita*);
void piu(struct armita*);
void piupiupiu(struct armita*);
void piuManual(struct armita*);

#endif