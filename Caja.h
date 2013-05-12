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

int caja_linkSiguiente(caja *c,caja *sig);

int caja_linkAnt(caja *c,caja *sig);

void aumentarIncidencias(caja *c);

void caja_free(caja *c);
#endif