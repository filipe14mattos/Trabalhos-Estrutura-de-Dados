#include <stdio.h>
#include <stdlib.h>
#include "PilhacomVetor.h"

Tpilha * criarPilha (int tam){
	Tpilha *pilha = (Tpilha*)malloc(sizeof(Tpilha));
	pilha->tam = tam;
	pilha->topo = -1;
	pilha->dado = (int *)malloc(sizeof(int) * tam);
	return pilha;
}

int pilhaVazia(Tpilha *p){
	if(p->topo == -1){
		return 1;
	}else{
		return 0;
	}
}


int pilhaCheia(Tpilha *p){
	if(p->topo == p->tam -1){
		return 1;
	}else{
		return 0;
	}
}
//push
int empilhar(Tpilha *p, int dado){
	if(pilhaCheia(p)){
		printf("Ocorreu um OVERFLOW na Pilha");
		exit (1);
	}else{
		p->topo++;
		return (p->dado[p->topo] = dado);
	}
}
//pop
int desempilhar (Tpilha *p){
	if(pilhaVazia(p)){
		printf("Ocorreu UNDERFLOW na Pilha!\n");
		exit(1);
	}else{
		
		return (p->dado[p->topo --]);
	}
}

int elemTopo(Tpilha *p){
	if(pilhaVazia(p)){
		printf("Ocorreu UNDERFLOW na Pilha\n");
		exit(1);
	}else{
		return (p->dado[p->topo]);
	}
}

//Essa funçao pega a pilha de origem e a pilha de destino que o usuario digitou, achando uma opção
//e chamado a checagem se é possivel empilhar o dado da pilha de origem na pilha de destino
void moverdisco(Tpilha *Pa, Tpilha *Pb, 
				Tpilha *Pc, int Po, int Pd){
	if(Po == 1 && Pd ==2){
		if((Pb->topo == -1) || (Pa->dado[Pa->topo]<Pb->dado[Pb->topo])){
			empilhar(Pb,Pa->dado[Pa->topo]);
			desempilhar(Pa);
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}
	}else if(Po == 1 && Pd == 3){
		if((Pc->topo == -1) || (Pa->dado[Pa->topo]<Pc->dado[Pc->topo])){
			empilhar(Pc,desempilhar(Pa));
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}
	}else if(Po == 2 && Pd == 1){
		if((Pa->topo == -1) || (Pb->dado[Pb->topo]<Pa->dado[Pa->topo])){
			empilhar(Pa,desempilhar(Pb));
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}
	}else if(Po == 2 && Pd == 3){
		if((Pc->topo == -1) || (Pb->dado[Pb->topo]<Pc->dado[Pc->topo])){
			empilhar(Pc,desempilhar(Pb));
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}	
	
	}else if(Po == 3 && Pd == 1){
		if((Pa->topo == -1) || (Pc->dado[Pc->topo]<Pa->dado[Pa->topo])){
			empilhar(Pa,desempilhar(Pc));
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}
	}else if(Po == 3 && Pd == 2){
		if((Pb->topo == -1) || (Pc->dado[Pc->topo]<Pb->dado[Pc->topo])){
			empilhar(Pb,desempilhar(Pc));
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}
	}
}
//Essa função e usada para printar a pilha fazendo o auxiliar receber o valor do topo imprimir na
//tela e ir para o valor anterior ao printado das pilha.
void printar(Tpilha *p){
	int i;
	for(i=p->topo;i>=0;i--){
		printf("\t|%i|\n", p->dado[i]);
	}
}