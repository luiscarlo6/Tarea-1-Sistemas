#include <stdio.h>
#include <stdlib.h>

/**
 * archivo Caja.h
 * define una Caja para guardar un elemento
 * con apuntador a una caja siguiente y anterior *  
 * Autor : Luiscarlo Rivera
 */

#ifndef __CAJA_H__
#define __CAJA_H__

/**
 * estructura que define una caja para
 * una lista doblemente enlazada
 */
typedef struct Caja{
    /**
     *void* elem elemento que guarda la caja
     */
    void* elem; 
    /**
     *int incidencias numero de veces que esta el elemento en la caja
     */
    int incidencias;
    /**
     *struct Caja *sig apuntador a la Caja siguiente
     */
    struct Caja *sig;
    /**
     *struct Caja *ant apuntador a la Caja siguiente
     */
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
