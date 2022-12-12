# Laboratório 4

Para testar o código é preciso compilar tudo e passar um .txt como argumento do executável, use os comandos seguintes:

gcc main.c broad.c rede.c grafo.c lista.c -o main -lm
./main arquivo.txt

Obs: usei a biblioteca matemática (math.h) do C. Então para compilar o código no Linux adicione "-lm" ao final da linha de comando do compilador. 