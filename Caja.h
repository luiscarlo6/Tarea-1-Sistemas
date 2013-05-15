#include <stdio.h>
#include <stdlib.h>

#ifndef __CAJA_H__
#define __CAJA_H__

typedef struct Caja{
	void* elem;
	int incidencias;
	struct Caja *sig;
	struct Caja *ant;
}caja;

caja* caja_crear(void* e);

caja* caja_sig(caja *c);

caja* caja_ant(caja *c);

int caja_incidencias(caja *c);

void* caja_elemento(caja *c);

int caja_linkSig(caja *c,caja *sig);

int caja_linkAnt(caja *c,caja *ant);

int cambiarIncidencias(caja *c, int i);

int aumentarIncidencias(caja *c);

int compararCaja(caja *c1, caja *c2);

void caja_free(caja *c);

#endif
