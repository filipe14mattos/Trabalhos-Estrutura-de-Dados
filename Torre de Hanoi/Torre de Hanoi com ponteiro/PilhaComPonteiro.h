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

//Checa se a possi��o da pilha esta vazia
int pilhaVazia (Tpilha *p);

//Checa se a pilha esta cheia


//checa se a pilha nao tem espa�o, tendo espa�o preenche com o dado inserido
int empilhar (Tpilha *p, int numero);

// retira elementos da pilha
int desempilhar (Tpilha *p);

// retorna o elemento do topo
int elemTopo (Tpilha *p);
//Essa fun�ao pega a pilha de origem e a pilha de destino que o usuario digitou, achando uma op��o
//e chamado a checagem se � possivel empilhar o dado da pilha de origem na pilha de destino
void moverdisco(Tpilha *Pa, Tpilha *Pb, 
				Tpilha *Pc, int Po, int Pd);
//Essa fun��o checa se o topo da pilha � igual a vazio ou se o valor do topo atual e menor doque
//o valor a ser substituido. Caso essa verifica�ao seja possivel o valor apontado e empilhado na 
//pilha selecionada e desempilhado da sua pilha de origem.
void chekpino(struct TipoPilha Pa, struct TipoPilha Pb, struct TipoPilha Pc, int Po, int Pd);
//Essa fun��o e usada para printar a pilha fazendo o auxiliar receber o valor do topo imprimir na
//tela e ir para o valor anterior ao printado das pilha.
void printar(struct TipoPilha *p);