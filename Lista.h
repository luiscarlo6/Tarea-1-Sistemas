#include <stdio.h>
#include <stdlib.h>
#include "Caja.h"

#ifndef __LISTA_H__
#define __LISTA_H__

typedef struct{
    int tam;
    caja *primero;
}lista;

lista * lista_crear();

int lista_agregar(lista *l, void* e);

int lista_ordenar(lista *l);

int lista_free(lista*l);

#endif