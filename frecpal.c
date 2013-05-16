#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "Lista.h"
#include "Caja.h"
#define STR_LENGTH 20
#define ZERO 0 

lista* procesarArchivo(char *nombreArchivo){
    FILE * entrada = fopen(nombreArchivo, "r");
    if (entrada==NULL){
        printf("El archivo \"%s\" no existe o no puede ser abierto\n",
                nombreArchivo);
        return NULL;
    }
    char aux[STR_LENGTH];
    lista *l = lista_crear();
    if (l==NULL){
    printf("Error, no hay suficiente memoria\n"); 
    return NULL;
    }
    fscanf(entrada,"%s",aux);
    while(feof(entrada)==ZERO){
        char *palabra = (char*) malloc(sizeof(char)*(strlen(aux)+1));
        strcpy(palabra,aux);
        lista_agregar(l,palabra);
        fscanf(entrada,"%s",aux);
    }
    if (fclose(entrada)!=0){
        printf("Error con el archivo \"%s\" \n",nombreArchivo);
        return NULL;
    }
    return l;
}

int main(int argc, char *argv[])
{
    if (argc != 2){
        printf("Argumentos insuficientes, por favor ejecute: ");
        printf("%s <NombreArchivo>\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    lista *palabras = procesarArchivo(argv[1]);
    if (palabras==NULL){
        exit(EXIT_FAILURE);
    }
    lista *ordenada = lista_ordenar(palabras);

    lista_imprimir(ordenada);
}

