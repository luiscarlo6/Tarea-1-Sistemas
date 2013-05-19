#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Caja.h"
/**
 * Archivo : Caja.c
 * Implemente la Caja con apuntador a anterior y siguiente
 * Autor : Luiscarlo Rivera
 */

/**
 * Funcion caja_crear
 * Crea una caja que contiene un elemento
 * 
 * Parametro : void* e elemento que guardara
 * 
 * retorna, el apuntador a la caja, NULL si ocurre un error
 */
caja * caja_crear(void* e){

    if (e==NULL){
        return NULL;
    }

    caja *c = (caja*) malloc(sizeof(caja));

    if (c==NULL){
        return NULL;
    }

    c->elem = e;
    c->incidencias = 0;
    c->sig = NULL;
    c->ant = NULL;

    return c;
}

/**
 * Funcion caja_elemento
 * 
 * Funcion que retorna el apuntador al elemento que contiene la caja
 * 
 * Parametro : caja *c caja valida
 * 
 * retorna el elemento, NULL si la caja no es valida
 */
void* caja_elemento(caja *c){
    if (c!=NULL){
        return c->elem;
    }
    return NULL;
}

/**
 * Funcion caja_sig
 * 
 * Funcion que retorna el apuntador a la caja siguiente 
 * 
 * Parametro : caja *c caja valida
 * 
 * retorna la sguiente caja, NULL si la caja no es valida
 */
caja* caja_sig(caja *c){
    if (c!=NULL){
        return c->sig;
    }
    return NULL;
}

/**
 * Funcion caja_ant
 * 
 * Funcion que retorna el apuntador a la caja siguiente 
 * 
 * Parametro : caja *c caja valida
 * 
 * retorna la sguiente caja, NULL si la caja no es valida
 */
caja* caja_ant(caja *c){
    if (c!=NULL){
        return c->ant;
    }
    return NULL;
}

/**
 * Funcion caja_linkSig
 * 
 * Funcion que une dos cajas usando sus parametros anterior y siguiente
 * 
 * Parametros : caja *c caja que se considerara la anterior en una lista
 *              caja *sig caja que se considerara la siguiente en una lista
 * 
 * retorna 0 si se enlazan correctamente, -1 en caso contrario
 */
int caja_linkSig(caja *c,caja *sig){    
    if (c==NULL || sig==NULL){
        return -1;
    }

    c->sig = sig;
    sig->ant = c;
    return 0;
}


/**
 * Funcion caja_linkSig
 * 
 * Funcion que une dos cajas usando sus parametros anterior y siguiente
 * 
 * Parametros : caja *c caja que se considerara la siguiente en una lista
 *              caja *ant caja que se considerara la anterior en una lista
 * 
 * retorna 0 si se enlazan correctamente, -1 en caso contrario
 */
int caja_linkAnt(caja *c,caja *ant){
    if (c==NULL || ant==NULL){
        return -1;
    }

    c->ant = ant;
    ant->sig = c;
    return 0;
}

/**
 * Funcion incidencias
 * 
 * Funcion que devuelve el numero de incidencias del elemento de la caja
 * 
 * Parametros : caja *c una caja valida
 * 
 * retorna el numero de incidencias
 * retorna -1 si la caja no es valida
 */
int caja_incidencias(caja *c){
    if (c==NULL){
        return -1;
    }

    return c->incidencias;
}

/**
 * Funcion aumentarIncidencias
 * 
 * Aumenta en uno el numero de incidencias del elemento en la caja
 * 
 * Parametro : Caja *c una caja valida
 * 
 * Retorna 0 si se aumentaron las incidencias correctamente
 * -1 en caso contrario
 */
int aumentarIncidencias(caja *c){
    if (c==NULL){
        return -1;
    }

    c->incidencias++;
    return 0;
}

/**
 * Funcion compararCaja
 * 
 * Dice si los elementos de las cajas son iguales
 * 
 * Parametros : caja *c1, caja *c2 cajas validas
 * 
 * Retorna 1 si los elementos de las cajas son iguales
 * 0 en caso contrario
 * 
 */
int compararCaja(caja *c1, caja *c2){
    if (c1==NULL || c2==NULL){
        return 0;
    }

    if( strcmp( c1->elem, c2->elem ) == 0 ){
        return 1;
    }

    return 0;

}
/**
 * Funcion cambiarIncidencias
 * 
 * Cambia el numero de incidencias del elemento de una caja_ant
 * 
 * Parametros : caja *c una caja valida
 *              int i el numero de incidencias deseadas
 * 
 * Retorna 0 si cambio las incidencias, -1 en caso contrario
 */
int cambiarIncidencias(caja *c, int i){
    if (c==NULL){
        return -1;
    }

    c->incidencias = i;
    return 0;
}

/**
 * Procedimiento caja_free
 * 
 * Libera la memoria de la caja y el elemento de la caja
 * 
 * Parametros : caja *c caja valida
 */
void caja_free(caja *c){
    free(c->elem);
    free(c);
}
