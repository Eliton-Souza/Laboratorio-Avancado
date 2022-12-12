#include <stdlib.h>
#include <stdio.h>
#include "evento.h"

evento_t* criarEvento(void){

	evento_t* evento = (evento_t*) malloc(sizeof(evento_t));

	return evento;

}

void imprimirEvento(evento_t* evento){

	printf("%lf\t%d\t%d\n", evento -> tempo, evento -> alvo, evento -> tipo);

}