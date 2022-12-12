#include <stdlib.h>
#include <stdio.h>
#include "broad.h"

// Função callback
bool compararTempos(void* infoA, void* infoB){

	return ((Evento*) infoA) -> tempo < ((Evento*) infoB) -> tempo;
}

Evento* criarEvento(int tipo, No* noAlvo, double tempo){

	Evento* evento = (Evento*) malloc(sizeof(Evento));

	evento -> noAlvo = noAlvo;
	evento -> tipo = tipo;
	evento -> tempo = tempo;

	return evento;
}

// Simula o broadcasting
void iniciarSimulacao(Lista* eventos, Rede* rede){

	while(!lista_vazia(eventos)){

		Evento* eventoAtual = (Evento*) lista_remover_inicio(eventos);

		printf("[%3.6f] No %d recebeu pacote.\n", eventoAtual -> tempo, eventoAtual -> noAlvo -> id);

		if(!eventoAtual -> noAlvo -> pacoteEnviado){

			Lista* vizinhos = rede -> grafo -> vetor[eventoAtual -> noAlvo -> id] -> vizinhos;

			while(!lista_vazia(vizinhos)){

				No* vizinho = (No*) lista_remover_inicio(vizinhos);

				printf("\t--> Repassando pacote para o no %d ...\n", vizinho -> id);

				double tempo = eventoAtual -> tempo + (0.1 + vizinho -> id * 0.01);

				Evento* novoEvento = criarEvento(1, vizinho, tempo);

				lista_adicionar_ordenado(eventos, novoEvento, compararTempos);

			}

			eventoAtual -> noAlvo -> pacoteEnviado = true;
		}
	}
}

Rede* lerEntrada(char* nomeArquivo){

	FILE* arquivo = fopen(nomeArquivo, "r");

	int quantNos; double raioComunicacao;

	fscanf(arquivo, "%d\t%lf\n", &quantNos, &raioComunicacao);

	Rede* rede = criarRede(quantNos, raioComunicacao); No* no = criarNo();

	while(fscanf(arquivo, "%d\t%lf\t%lf\n", &no -> id, &no -> posicaoX, &no -> posicaoY) != EOF){

		no -> pacoteEnviado = false;
		inserirNoEmRede(rede, no);
		no = criarNo();
	}

	atualizarVizinhos(rede);

	return rede;
}
