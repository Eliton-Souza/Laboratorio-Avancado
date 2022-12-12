#include "grafo.h"
#include <stdbool.h>

typedef struct{

	int id;
	double posicaoX;
	double posicaoY;
	bool pacoteEnviado;

} No;

typedef struct{

	double raioComunicacao;
	Grafo* grafo;

} Rede;


No* criarNo(void);

Rede* criarRede(int quantNos, double raioComunicacao);

void inserirNoEmRede(Rede* rede, No* no);

void atualizarVizinhos(Rede* rede);

double calcularDistanciaNos(No* noA, No* noB);

void imprimirRede(Rede* rede);