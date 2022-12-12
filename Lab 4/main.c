#include <stdlib.h>
#include <stdio.h>
#include "broad.h"

int main(int argc, char** argv){

	Rede* rede = lerEntrada(argv[1]);

	Lista* eventos = criarLista();
	Evento* evento = criarEvento(1, (No*) rede -> grafo -> vetor[0] -> info, 1.0);

	lista_adicionar_fim(eventos, evento);

	iniciarSimulacao(eventos, rede);

	return 0;

}