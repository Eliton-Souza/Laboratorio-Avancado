#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manipula.h"

void concatenar(char** dest, char src){

	int fim = strlen(*dest);

	(*dest)[fim] = src;
	(*dest)[fim + 1] = '\0';
}

void gerar_palavra(int posicao, int tamanho, char* string, char* chars){

	if(posicao < tamanho){

		for(int i = 0; i < strlen(chars); i++){

			char* local = (char*) malloc((tamanho + 1) * sizeof(char));

			strcpy(local, string);
			concatenar(&local, chars[i]);
			gerar_palavra(posicao + 1, tamanho, local, chars);
		}
	}
	else{
		printf("%s\n", string);
	}
}