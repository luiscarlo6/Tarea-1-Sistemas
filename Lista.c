#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
/**
 * archivo Lista.c
 * Implementacion de una lista
 * doblemente enlazada
 *  
 * Autor : Luiscarlo Rivera
 */


/**
 * Funcion lista_crear
 * Parametros : sin parametros
 * solicita memoria para una cabeza de lista
 * retorna el apuntador a la cabeza si la
 * solicitud de memoria fue exitosa, retorna NULL 
 * si no lo fue
 */
lista * lista_crear(){
    lista *l = (lista*) malloc(sizeof(lista));
    if (l==NULL){
        return NULL;
    }
    l->tam = 0;
    l->primero = NULL;
    return l;
};

/**
 * Funcion lista_agregar
 * parametros : lista *l cabeza de lista
 *              void *e  elemento a agregar en la lista
 * 
 * agrega el elemento 'e' a la lista, si ya existe
 * el elemento en la lista, se incrementa su numero
 * de incidencias en uno
 * 
 * retorna 0 si la operacion se realizo correctamente
 * retorna -1 si ocurre un error
 */
int lista_agregar(lista *l, void* e){
    if (l==NULL || e==NULL){
        return -1;
    }

    caja *c = caja_crear(e);

    if(c==NULL){
        return -1;
    }

    if(l->tam==0){
        l->primero = c;
        l->ultimo = c;
        l->tam++;
        aumentarIncidencias(c);
        return 0;
    }

    int i = 0;
    caja *aux = l->primero;
    while (i!=l->tam){
        int iguales = compararCaja(c,aux);
        if (iguales==1){
            aumentarIncidencias(aux);
            caja_free(c);
            return 0;
        }
        aux = caja_sig(aux);
        i++;
    }

    caja_linkSig(l->ultimo,c);
    l->ultimo = c;
    aumentarIncidencias(c);
    l->tam++;
    return 0;
}

/**
 * procedimiento lista_imprimir
 * 
 * parametros lista *l cabeza de lista
 * 
 * imprime todos los elementos de la lista e
 * si esta no existe o no tiene elementos
 * no imprime nada 
 */
void lista_imprimir(lista *l){
    if (l==NULL){
        return;
    }
    
    int i = 0;
    caja *c = l->primero;
    while (i!=l->tam){
        char *s = c->elem;
        printf("%s %d\n",s,caja_incidencias(c));
        c = caja_sig(c);
        i++;
    }
}

/**
 * Funcion lista_tam
 * 
 * Parametros : lista *l cabeza de lista
 * 
 * devuelve el numero de elementos almacenado en la lista
 * si la lista no existe retorna -1
 */
int lista_tam(lista *l){
    if (l!=NULL){
        return l->tam;
    }
    return -1;
}

/**
 * Funcion lista_agregar_ordenado
 * 
 * Parametros : lista *l cabeza de lista
 *              void *e elemento a agregar
 *               int incidencias numero de incidencias del elemento
 * 
 * agrega ordenadamente el elemento 'e' a la lista usando como
 * referencia el numero de incidencias dado
 * 
 * retorna 0 si se agrego correctamente -1 en caso contrario
 */
int lista_agregar_ordenado(lista *l, void* e, int incidencias){
    if (l==NULL){
        return -1;
    }
    caja *c = caja_crear(e);
    cambiarIncidencias(c,incidencias);
    if(c==NULL){
        return -1;
    }

    if(l->tam==0){
        l->primero = c;
        l->ultimo = c;
        l->tam++;
        return 0;
    }

    int i = 0;
    caja *aux = l->primero;
    int incidenciasC = caja_incidencias(c);

    while (i!=l->tam){
        int incidenciasAux = caja_incidencias(aux);
        if (incidenciasAux<incidenciasC){
            if (i == 0){
                    l->primero = c;
            }
            caja *ant = caja_ant(aux);
            caja_linkSig(c,aux);
            caja_linkSig(ant,c);
            l->tam++;
            break;
        }
        aux = caja_sig(aux);
        i++;
    }

    if (i==(l->tam)){
        caja_linkSig(l->ultimo,c);
        l->ultimo = c;
        l->tam++;
        return 0;
    }
    return -1;
}

/**
 * Funcion lista_ordenar
 * 
 * Parametros : lista *l cabeza de lista
 * 
 * Ordena la lista l
 * 
 * retorna una cabeza de lista que apunta a la lista ordenada
 * NULL si no se pudo realizar la operacion
 */
lista * lista_ordenar(lista *l){
    if (l==NULL){
        return NULL;
    }
    lista *ord = lista_crear();
    if (ord == NULL){
        return NULL;
    }
    int i = 0;
    caja *aux = l->primero;
    while (i!=l->tam){
        if (aux==NULL){
            return NULL;
        }
        lista_agregar_ordenado(ord,caja_elemento(aux),caja_incidencias(aux));
        aux = caja_sig(aux);
        i++;
    }
    return ord;
}

/**
 * Funcion lista_free
 * 
 * Parametros : lista *l
 * 
 * libera la memoria de la lista y de las cajas que usa
 */
int lista_free(lista *l){
    if (l==NULL){
            return -1;
    }

    int i = 0;
    caja *c = l->primero;
    caja *aux;
    while (i!=l->tam){
        aux = caja_sig(c);
        caja_free(c);
        c= aux;
        i++;
    }
    free(l);
    return 0;
}

