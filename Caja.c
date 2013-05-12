#include <stdio.h>
#include <stdlib.h>
#include "Caja.h"

caja * caja_crear(void* e){

    caja *c = (caja*) malloc(sizeof(caja));
    if (c==NULL){
        return NULL;
    }
    
    c->elem = e;
    
    return c;
}

void caja_free(caja *c){
    free(c);
}