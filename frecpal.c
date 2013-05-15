#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Caja.h"

int main(int argc, char **argv)
{   
    char p1[20] = "aceituna";
    char p2[20] = "perico";
    char p3[20] = "aguacate";
    char p4[20] = "caraota";
    printf("%s y %s declarados\n",p1,p2);
    caja *caja1 = caja_crear(&p1);
    caja *caja2 = caja_crear(&p2);

    lista *l = lista_crear();
    printf("\n%d\n",lista_tam(l));
    if (l==NULL){
        return -1;
    }
    //lista_agregar(l, NULL);
    lista_agregar(l, p1);
    printf("\n%d\n",lista_tam(l));
    lista_agregar(l, &p1);
    lista_agregar(l, &p1);
    lista_agregar(l, &p1);
    lista_agregar(l, &p1);
    lista_agregar(l, &p1);
    lista_agregar(l, &p1);
    lista_agregar(l, &p1);
    lista_agregar(l, &p1);
    lista_agregar(l, &p1);
    lista_agregar(l, &p2);
    lista_agregar(l, &p2);
    lista_agregar(l, &p2);
    lista_agregar(l, &p2);
    lista_agregar(l, &p2);
    printf("\n%d\n",lista_tam(l));
    lista_agregar(l, &p3);
    printf("\n%d\n",lista_tam(l));
    lista_agregar(l, &p3);
    lista_agregar(l, &p4);
    printf("\n%d\n",lista_tam(l));
    
    lista_imprimir(l);
}

