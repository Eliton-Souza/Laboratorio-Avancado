typedef struct{

	double tempo;
	int alvo;
	int tipo;

} evento_t;

// Função que aloca e retorna um novo evento
evento_t* criarEvento(void);

// Função que imprime um evento
void imprimirEvento(evento_t* evento);