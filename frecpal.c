#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Caja.h"

int main(int argc, char **argv)
{   
    char p1[20] = "aceituna";
    char p2[20] = "perico";
    printf("%s y %s declarados\n",p1,p2);
    caja *caja1 = caja_crear(&p1);
    caja *caja2 = caja_crear(&p2);
    aumentarIncidencias(caja1);
    char *s1 = caja1->elem;
    char *s2 = caja2->elem;
    printf("%s y %s en las cajas, con incidencias %d y %d\n",
           s1,
           s2,
           caja1->incidencias,
           caja2->incidencias);
    
    int err = caja_linkSig(caja1,caja2);
    if (err==-1){
        printf("LA CAGASTE\n");
    }
    s1 = caja1->elem;
    caja *cajatemp = caja_sig(caja1);
    s2 = cajatemp->elem;
    printf("el siguiente de %s es %s\n",s1,s2);
    
    
    
    err = caja_linkSig(caja2,caja1);
    if (err==-1){
        printf("LA CAGASTE\n");
    }
    s1 = caja_elemento(caja2);
    cajatemp = caja_sig(caja2);
    s2 = cajatemp->elem;
    printf("el siguiente de %s es %s\n",s1,s2);
    
    int iguales = compararCaja(caja1,caja2);
    printf("las cajas contienen el mismo elemento %d\n",iguales);
    return 0;
    
    
}
