#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "hash.h"

typedef struct{

	Lista* lista;
	int indice;
}Linha;

struct tabelaHash{

	int tamanho;
	Hash_Funcao hash_funcao;
	Linha** vetTabela;
};

void imprimirTabelaHash(TabelaHash* tabelaHash, Imprimir imprimir){

	for(int i = 0; i < tabelaHash -> tamanho; i++){

		Linha* linha = tabelaHash -> vetTabela[i];

		printf("POSICAO %d DA TABELA HASH:", i);

		if(linha != NULL){
			printf("\n"); imprimir_lista(linha -> lista, imprimir);
		}
		else{
			printf(" NULL\n");
		}
	}
}

TabelaHash* criarTabelaHash(int tamanho, Hash_Funcao hash_funcao){

	TabelaHash* tabelaHash = (TabelaHash*) malloc(sizeof(TabelaHash));

	tabelaHash -> hash_funcao = hash_funcao;
	tabelaHash -> vetTabela = (Linha**) malloc(tamanho * sizeof(Linha*));
	tabelaHash -> tamanho = tamanho;

	memset(tabelaHash -> vetTabela, '\0', tamanho * sizeof(Linha*));

	return tabelaHash;
}

void inserirTabelaHash(TabelaHash* tabelaHash, void* info){

	int indice = tabelaHash -> hash_funcao(info, tabelaHash -> tamanho);

	Linha* linha = tabelaHash -> vetTabela[indice];

	if(linha == NULL){

		linha = (Linha*) malloc(sizeof(Linha));

		linha -> lista = criarLista();
		linha -> indice = indice;

		tabelaHash -> vetTabela[indice] = linha;
	}
	lista_adicionar_inicio(linha -> lista, info);
}