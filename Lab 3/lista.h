typedef struct lista Lista;

// Callbacks
typedef void (*Imprimir)(void*);
typedef short (*Comparar)(void*, void*);

// Função que retorna nova lista
Lista* criarLista(void);

void lista_adicionar_ordenado(Lista* lista, void* info, Comparar comparar);

void lista_adicionar_fim(Lista* lista, void* info);

void lista_adicionar_inicio(Lista* lista, void* info);

void listar_elementos(Lista* lista, Imprimir imprimir);