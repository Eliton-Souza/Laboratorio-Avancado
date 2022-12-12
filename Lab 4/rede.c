#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "rede.h"

No* criarNo(void){

	No* no = (No*) malloc(sizeof(No));
	return no;
}

Rede* criarRede(int quantNos, double raioComunicacao){

	Rede* rede = (Rede*) malloc(sizeof(Rede));

	rede -> raioComunicacao = raioComunicacao;
	rede -> grafo = criarGrafo(quantNos);

	return rede;
}

void inserirNoEmRede(Rede* rede, No* no){

	inserirVertice(rede -> grafo, no);
}

void atualizarVizinhos(Rede* rede){

	for(int i = 0; i < rede -> grafo -> ocupacao; i++){

		for(int j = i + 1; j < rede -> grafo -> ocupacao; j++){

			No* noA = (No*) (rede -> grafo -> vetor[i] -> info);
			No* noB = (No*) (rede -> grafo -> vetor[j] -> info);

			double distancia = calcularDistanciaNos(noA, noB);

			if(distancia < rede -> raioComunicacao){

				inserirAresta(rede -> grafo -> vetor[i], rede -> grafo -> vetor[j]);
			}
		}
	}
}

double calcularDistanciaNos(No* noA, No* noB){

	return sqrt(pow(noA -> posicaoX - noB -> posicaoX, 2) + pow(noA -> posicaoY - noB -> posicaoY, 2));
}

void imprimirNo(No* no){

	printf("%d ", no -> id);
}

void imprimirNoCallback(void* info){

	No* no = (No*) info;
	imprimirNo(no);
}

void imprimirRede(Rede* rede){

	printf("\nREDE: TAMANHO = %d/%d, RAIO = %.1lf\n", rede -> grafo -> ocupacao, rede -> grafo -> tamanho, rede -> raioComunicacao);
	imprimirGrafo(rede -> grafo, imprimirNoCallback);
}