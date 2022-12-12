typedef struct tabelaHash TabelaHash;

// Callbacks
typedef int (*Hash_Funcao)(void*, int);
typedef void (*Imprimir)(void*);

// Imprime todas as linhas da tabela
void imprimirTabelaHash(TabelaHash* hash, Imprimir imprimir);

// Retorna uma nova tabela hash
TabelaHash* criarTabelaHash(int tamanho, Hash_Funcao funcaoHash);

// Insere novo elemento na tabela
void inserirTabelaHash(TabelaHash* tabelaHash, void* info);
