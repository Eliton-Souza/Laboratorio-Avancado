#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "lista.h"

typedef struct elemento Elemento;

struct elemento{

	void* info;
	Elemento* prox;
};

struct lista{

	int tamanho;
	Elemento* inicio;
	Elemento* final;
};

Elemento* criarElemento(void* info){

	Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
	elemento -> info = info;
	return elemento;
}


Lista* criarLista(void){

	Lista* lista = (Lista*) malloc(sizeof(Lista));

	lista -> inicio = lista -> final = NULL;
	lista -> tamanho = 0;
	return lista;
}


void lista_adicionar_ordenado(Lista* lista, void* info, Comparar comparar){

	Elemento* ant = NULL;
	Elemento* prox = lista -> inicio;

	while(prox != NULL && comparar(prox -> info, info)){

		ant = prox;
		prox = prox -> prox;
	}

	if(ant != NULL && prox != NULL){

		Elemento* elemento = criarElemento(info);

		ant -> prox = elemento;
		elemento -> prox = prox;
		lista -> tamanho++;
	}
	else if(ant == NULL){
		lista_adicionar_inicio(lista, info);

	}
	else{
		lista_adicionar_fim(lista, info);
	}

}


void lista_adicionar_fim(Lista* lista, void* info){

	Elemento* elemento = criarElemento(info);

	elemento -> prox = NULL;

	if(lista -> tamanho == 0) lista -> inicio = elemento;
	else lista -> final -> prox = elemento;

	lista -> final = elemento;
	lista -> tamanho++;
}

void lista_adicionar_inicio(Lista* lista, void* info){

	Elemento* elemento = criarElemento(info);
	elemento -> prox = lista -> inicio;

	if(lista -> tamanho == 0) lista -> final = elemento;

	lista -> inicio = elemento;
	lista -> tamanho++;
}


void listar_elementos(Lista* lista, Imprimir imprimir){

	if(lista -> tamanho > 0){

		Elemento* aux = lista -> inicio;

		while(aux != NULL){

			imprimir(aux -> info);
			aux = aux -> prox;
		}
	}else printf("Lista Vazia");
}