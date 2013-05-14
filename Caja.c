#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Caja.h"

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

void* caja_elemento(caja *c){
    if (c!=NULL){
        return c->elem;
    }
    return NULL;
}

caja* caja_sig(caja *c){
    if (c!=NULL){
        return c->sig;
    }
    return NULL;
}

caja* caja_ant(caja *c){
    if (c!=NULL){
        return c->ant;
    }
    return NULL;
}

int caja_linkSig(caja *c,caja *sig){
    
    if (c==NULL || sig==NULL){
        return -1;
    }
    
    c->sig = sig;
    sig->ant = c;
    return 0;
}

int caja_linkAnt(caja *c,caja *ant){
    if (c==NULL || ant==NULL){
        return -1;
    }
    
    c->ant = ant;
    ant->sig = c;
    return 0;
}

int caja_incidencias(caja *c){
    if (c==NULL){
        return -1;
    }
    
    return c->incidencias;
}

int aumentarIncidencias(caja *c){
    if (c==NULL){
        return -1;
    }
    
    c->incidencias++;
    return 0;
}

int compararCaja(caja *c1, caja *c2){
    if (c1==NULL || c2==NULL){
        return 0;
    }
    
    if( strcmp( c1->elem, c2->elem ) == 0 ){
        return 1;
    }
    
    return 0;
    
}

void caja_free(caja *c){
    free(c->elem);
    free(c);
}