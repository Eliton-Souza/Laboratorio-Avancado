#include "lista.h"

typedef struct{

	void* info;
	Lista* vizinhos;

} Vertice;

typedef struct{

	int tamanho;
	int ocupacao;
	Vertice** vetor;

} Grafo;

// Callback para impressão 
typedef void (*Imprimir)(void*);

Grafo* criarGrafo(int tamanho);

void imprimirGrafo(Grafo* grafo, Imprimir imprimir);

void inserirAresta(Vertice* verticeA, Vertice* verticeB);

void inserirVertice(Grafo* grafo, void* info);

Vertice* criarVertice(void* info);