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

	if (i==(l->tam)){
		caja_linkSig(l->ultimo,c);
		l->ultimo = c;
		aumentarIncidencias(c);
		l->tam++;
		return 0;
	}
	return -1;
}

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

int lista_tam(lista *l){
	if (l!=NULL){
		return l->tam;
	}
	return -1;
}

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

lista * lista_ordenar(lista *l){
	lista *ord = lista_crear();
	int i = 0;
	caja *aux = l->primero;
	while (i!=l->tam){
		lista_agregar_ordenado(ord,caja_elemento(aux),caja_incidencias(aux));
		aux = caja_sig(aux);
		i++;
	}
	return ord;
}

int lista_free(lista*l){
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
	return 0;
}

