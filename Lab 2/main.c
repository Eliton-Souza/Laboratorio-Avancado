#include <stdlib.h>
#include <stdio.h>
#include "hash.h"
#include "pessoa.h"

int funcaoHash(void* info, int tamanho){

	Pessoa* pessoa = (Pessoa*) info;
	return pessoa -> cpf % tamanho;

}

void imprimirPessoaCallback(void* info){

	Pessoa* pessoa = (Pessoa*) info;
	imprimirPessoa(pessoa);
}

int main(int argc, char* argv[]){

	int tamanho = atoi(argv[1]);

	FILE* arquivo = fopen(argv[2], "r");
	TabelaHash* tabelaHash = criarTabelaHash(tamanho, funcaoHash); Pessoa* pessoa = criarPessoa();

	while(fscanf(arquivo, "%50[^\t]\t%lld\t%d\n", &pessoa -> nome, &pessoa -> cpf, &pessoa -> idade) != EOF){

		inserirTabelaHash(tabelaHash, pessoa);
		pessoa = criarPessoa();
	}

	imprimirTabelaHash(tabelaHash, imprimirPessoaCallback);
	fclose(arquivo);

	return 0;
}