#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Caja.h"

int main(int argc, char **argv)
{   
    char S[20] = "HOLA";
    lista *lis = lista_crear();
    printf("%s\n",S);
    caja *c = caja_crear(&S);
    char *ese = c->elem;
    printf("%s\n", ese);
    return 0;
}