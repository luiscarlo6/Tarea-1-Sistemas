#include <stdio.h>
#include <stdlib.h>
#include "Caja.h"

/**
 * Archivo : Lista.h
 * Define una lista doblemente enlazada con apuntador
 * al primer y ultimo elemento
 * Autor : Luiscarlo Rivera
 */

#ifndef __LISTA_H__
#define __LISTA_H__

/**
 * Estructura de cabeza de lista
 * 
 * elementos :  
 *     
 *                            contiene el primer elemento
 *              caja *ultimo apuntador a la caja que
 *                           contiene el ultimo elemento
 */
typedef struct{
    /**
     * int tam tamaño dela lista
     */
    int tam;
    /**
     * caja *primero apuntador a la caja que
     * contiene el primer elemento
     */
    caja *primero;
    /**
     * caja *primero apuntador a la caja que
     * contiene el ultimo elemento
     */
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
