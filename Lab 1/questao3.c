#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "evento.h"

void imprimirEventoCallback(void* info){

	evento_t* evento = (evento_t*) info;
	imprimirEvento(evento);

}

short compararCallback(void* infoA, void* infoB){

	evento_t* eventoA = (evento_t*) infoA;
	evento_t* eventoB = (evento_t*) infoB;

	return (eventoA -> tempo) < (eventoB -> tempo);

}

int main(int argc, char* argv[]){

	FILE* arquivo = fopen(argv[1], "r");
	Lista* lista = criarLista(); evento_t* evento = criarEvento();

	while((fscanf(arquivo, "%lf\t%d\t%d\n", &evento -> tempo, &evento -> alvo, &evento -> tipo) != EOF)){

		lista_eventos_adicionar_ordenado(lista, evento, compararCallback);

		evento = criarEvento();

	}

	lista_eventos_listar(lista, imprimirEventoCallback);

	fclose(arquivo);

	return 0;
}