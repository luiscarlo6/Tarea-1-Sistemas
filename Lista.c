#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

lista * lista_crear(){
    lista *l = (lista*) malloc(sizeof(lista));
    if (l==NULL){
        return NULL;
    }
    l->tam = 0;
    return l;
};