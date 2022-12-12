#include <stdio.h>
#include "rede.h"

int main(int argc, char** argv){

	FILE* arquivo = fopen(argv[1], "r");

	int quantNos; double raioComunicacao;

	fscanf(arquivo, "%d\t%lf\n", &quantNos, &raioComunicacao);

	Rede* rede = criarRede(quantNos, raioComunicacao); No* no = criarNo();

	while(fscanf(arquivo, "%d\t%lf\t%lf\n", &no -> id, &no -> posicaoX, &no -> posicaoY) != EOF){

		inserirNoEmRede(rede, no);

		no = criarNo();

	}

	atualizarVizinhos(rede);

	imprimirRede(rede);

	return 0;

}