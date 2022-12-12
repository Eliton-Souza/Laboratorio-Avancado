// Tipo Pessoa

typedef struct{

	char nome[50];
	long long int cpf;
	int idade;

} Pessoa;

// Função que aloca e retorna uma nova pessoa
Pessoa* criarPessoa(void);

// Função que imprime uma pessoa
void imprimirPessoa(Pessoa* pessoa);