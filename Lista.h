#include <stdio.h>
#include <stdlib.h>
#include "Caja.h"

#ifndef __LISTA_H__
#define __LISTA_H__

typedef struct{
	int tam;
	caja *primero;
	caja *ultimo;
}lista;

lista * lista_crear();

int lista_agregar(lista *l, void* e);

int lista_agregar_ordenado(lista *l, void* e, int incidencias);

int lista_free(lista *l);

void lista_imprimir(lista *l);

lista * lista_ordenar(lista *l);

int lista_tam(lista *l);

#endif
