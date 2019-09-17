#include <stdlib.h>
#include <stdio.h>

typedef struct pilha{
	int tam, topo;
	int *dado;
}Tpilha;

//Cria uma pilha alocando dinamicamente a quantidade de dados que seram inseridos
Tpilha *criarPilha(int tam);

//Checa se a possição da pilha esta vazia
int pilhaVazia (Tpilha *p);

//Checa se a pilha esta cheia
int pilhaCheia (Tpilha *p);

//checa se a pilha nao tem espaço, tendo espaço preenche com o dado inserido
int empilhar (Tpilha *p, int dado);

// retira elementos da pilha
int desempilhar (Tpilha *p);

// retorna o elemento do topo
int elemTopo (Tpilha *p);