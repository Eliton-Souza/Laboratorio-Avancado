#include <stdlib.h>
#include <stdio.h>

#define HEX 0x04034b50

struct zip_file_hdr{

	int signature;
	short version;
	short flags;
	short compression;
	short mod_time;
	short mod_date;
	int crc;
	int compressed_size;
	int uncompressed_size;
	short name_length;
	short extra_field_length;

} __attribute__ ((packed));

typedef struct zip_file_hdr ZipFileHdr;

int main(int argc, char** argv){

	FILE* zipFile = fopen(argv[1], "rb");

	ZipFileHdr* fileHdr = (ZipFileHdr*) malloc(sizeof(ZipFileHdr));

	int cont = 1;

	while((fread(fileHdr, sizeof(ZipFileHdr), 1, zipFile) != EOF) && (fileHdr -> signature == HEX)){

		printf("Arquivo %d ..\n", cont);

		size_t tamanho = (fileHdr -> name_length + 1) * sizeof(char);

		char* nome = (char*) malloc(tamanho);

		fread(nome, tamanho, 1, zipFile);

		nome[fileHdr -> name_length] = '\0';

		printf("  --> Nome do Arquivo: %s\n", nome);
		printf("  --> Tamanho Compactado: %d\n", fileHdr -> compressed_size);
		printf("  --> Tamanho Descompactado: %d\n", fileHdr -> uncompressed_size);

		free(nome);

		fseek(zipFile, (sizeof(ZipFileHdr) + fileHdr -> name_length + fileHdr -> extra_field_length + fileHdr -> compressed_size) * cont, SEEK_SET);

		cont++;
	}

	free(fileHdr); fclose(zipFile);

	return 0;
}