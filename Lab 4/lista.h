#include <stdbool.h>

typedef struct lista Lista;

// Callbacks
typedef void (*Imprimir)(void*);
typedef bool (*Comparar)(void*, void*);

// Função que retorna nova lista
Lista* criarLista(void);

void lista_adicionar_ordenado(Lista* lista, void* info, Comparar comparar);

void lista_adicionar_fim(Lista* lista, void* info);

void lista_adicionar_inicio(Lista* lista, void* info);

void listar_elementos(Lista* lista, Imprimir imprimir);

bool lista_vazia(Lista* lista);

void* lista_remover_inicio(Lista* lista);