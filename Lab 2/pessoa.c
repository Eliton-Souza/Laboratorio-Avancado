#include <stdlib.h>
#include <stdio.h>
#include "pessoa.h"

Pessoa* criarPessoa(void){

	Pessoa* pessoa = (Pessoa*) malloc(sizeof(Pessoa));

	return pessoa;

}

void imprimirPessoa(Pessoa* pessoa){

	printf("- %s\t\t%lld\t\t%d\n", pessoa -> nome, pessoa -> cpf, pessoa -> idade);

}