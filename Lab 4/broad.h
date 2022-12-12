#include "rede.h"

typedef struct{

	int tipo;
	No* noAlvo;
	double tempo;

} Evento;

//Callback
bool compararTempos(void* infoA, void* infoB);

Evento* criarEvento(int tipo, No* noAlvo, double tempo);

void iniciarSimulacao(Lista* eventos, Rede* rede);

Rede* lerEntrada(char* nomeArquivo);