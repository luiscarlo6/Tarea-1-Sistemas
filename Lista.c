#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

lista * lista_crear(){
    lista *l = (lista*) malloc(sizeof(lista));
    if (l==NULL){
        return NULL;
    }
    l->tam = 0;
    l->primero = NULL;
    return l;
};

int lista_agregar(lista *l, void* e){
    if (l==NULL || e==NULL){
        return -1;
    }
    
    if(l->tam==0){
        caja *c;
    }
}

int lista_ordenar(lista *l);

int lista_free(lista*l);
