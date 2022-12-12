#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

Grafo* criarGrafo(int tamanho){

	Grafo* grafo = (Grafo*) malloc(sizeof(Grafo));

	grafo -> tamanho = tamanho; grafo -> ocupacao = 0;
	grafo -> vetor = (Vertice**) malloc(tamanho * sizeof(Vertice*));

	return grafo;
}

void imprimirGrafo(Grafo* grafo, Imprimir imprimir){

	for(int i = 0; i < grafo -> ocupacao; i++){

		printf("\nNO %d: ", i);

		listar_elementos(grafo -> vetor[i] -> vizinhos, imprimir);

	}
	printf("\n");
}

void inserirAresta(Vertice* verticeA, Vertice* verticeB){

	lista_adicionar_inicio(verticeA -> vizinhos, verticeB -> info);
	lista_adicionar_inicio(verticeB -> vizinhos, verticeA -> info);
}

void inserirVertice(Grafo* grafo, void* info){

	if(grafo -> ocupacao < grafo -> tamanho){

		Vertice* vertice = criarVertice(info);

		grafo -> vetor[grafo -> ocupacao] = vertice;
		grafo -> ocupacao++;
	}
}

Vertice* criarVertice(void* info){

	Vertice* vertice = (Vertice*) malloc(sizeof(Vertice));

	vertice -> info = info;
	vertice -> vizinhos = criarLista();

	return vertice;
}