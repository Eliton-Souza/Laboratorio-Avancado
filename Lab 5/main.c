#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manipula.h"

int main(int argc, char** argv){

	int tamanho = atoi(argv[1]);
	char* chars = argv[2];

	for(int i = 1; i <= tamanho; i++){

		char* string = (char*) malloc((i + 1) * sizeof(char));
		string[0] = '\0';

		gerar_palavra(0, i, string, chars);
		free(string);
	}
	return 0;
}