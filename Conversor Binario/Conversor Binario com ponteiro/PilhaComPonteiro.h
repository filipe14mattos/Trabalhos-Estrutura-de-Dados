#include <stdlib.h>
#include <stdio.h>

typedef struct TipoElemento{
	int valor;
	struct TipoElemento *acima, *abaixo;
}TElemento;

typedef struct TipoPilha{
	TElemento *topo, *base;
}Tpilha;

//Cria uma pilha alocando dinamicamente a quantidade de dados que seram inseridos
void inicPilha(Tpilha *p);

//Checa se a possição da pilha esta vazia
int pilhaVazia (Tpilha *p);

//Checa se a pilha esta cheia


//checa se a pilha nao tem espaço, tendo espaço preenche com o dado inserido
int empilhar (Tpilha *p, int numero);

// retira elementos da pilha
int desempilhar (Tpilha *p);

// retorna o elemento do topo
int elemTopo (Tpilha *p);

void moverdisco(Tpilha *Pa, Tpilha *Pb, 
				Tpilha *Pc, int Po, int Pd, int *resultado);

void chekpino(struct TipoPilha Pa, struct TipoPilha Pb, struct TipoPilha Pc, int Po, int Pd);