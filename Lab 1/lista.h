typedef struct lista Lista;

// Callbacks
typedef void (*Imprimir)(void*);
typedef short (*Comparar)(void*, void*);

// Função que retorna nova lista
Lista* criarLista(void);

void lista_eventos_adicionar_ordenado(Lista* lista, void* info, Comparar comparar);

void lista_eventos_adicionar_fim(Lista* lista, void* info);

void lista_eventos_adicionar_inicio(Lista* lista, void* info);

void lista_eventos_listar(Lista* lista, Imprimir imprimir);