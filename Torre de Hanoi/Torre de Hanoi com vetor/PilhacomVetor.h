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

//Essa função é usada para mover os discos de um pino de origem para o pino de destino 
void moverdisco(Tpilha *Pa, Tpilha *Pb, 
				Tpilha *Pc, int Po, int Pd);
//Essa função e usada para printar a pilha fazendo o auxiliar receber o valor do topo imprimir na
//tela e ir para o valor anterior ao printado das pilha.
void printar(Tpilha *p);