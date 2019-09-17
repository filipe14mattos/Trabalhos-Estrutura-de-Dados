#include <stdio.h>
#include <stdlib.h>
#include "PilhaComPonteiro.h"

void inicPilha (struct TipoPilha *p){
	p->topo = NULL;
	p->base = NULL;
}

int pilhaVazia(struct TipoPilha *p){
	if(p->topo == NULL){
		return 1;
	}else{
		return 0;
	}
}

//push
int empilhar(struct TipoPilha *p, int numero){
	TElemento *novo = (TElemento *)malloc(sizeof(TElemento));
	novo->valor = numero;
	if(pilhaVazia(p)){
		p->topo = novo;
		p->base = novo;
		p->topo->abaixo = NULL;
	}else{
		p->topo->acima = novo;
		novo->abaixo = p->topo;
		p->topo = novo;
	}
	return p->topo->valor;
}
//pop
int desempilhar (struct TipoPilha *p){
	TElemento *aux = NULL;
	int valor;
	if(!pilhaVazia(p)){
		aux = p->topo;
		p->topo = p->topo->abaixo;
		if(p->topo == NULL){
			p->base = NULL;
		}else{
			p->topo->acima = NULL;		
		}
	}
	valor = aux->valor;
	free(aux);
	return valor;
}

int elemTopo(struct TipoPilha *p){
	int valor = -9999;
	if(pilhaVazia(p)){
		printf("Ocorreu UNDERFLOW na Pilha\n");
		exit(1);
	}else{
		valor = p->topo->valor;
	}
	return valor;
}

void checkpino(struct TipoPilha *Pa, struct TipoPilha *Pb, 
              struct TipoPilha *Pc, int Po, int Pd){
	if(Po == 1 && Pd ==2){
		if(Pb->topo == NULL || Pa->topo->valor<Pb->topo->valor){
			empilhar(Pb,Pa->topo->valor);
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}
		//colocar pilha A desempilhando na pilha B
		//checando se esta vazia e se o pino a ser colocado
		//e menor do que o que ja esta la.
	}else if(Po == 1 && Pd == 3){
		if(Pc->topo == NULL || Pa->topo->valor<Pc->topo->valor){
			empilhar(Pc,Pa->topo->valor);
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}
		//colocar pilha A desempilhando na pilha C
		//checando se esta vazia e se o pino a ser colocado
		//e menor do que o que ja esta la.
	}else if(Po == 2 && Pd == 1){
		if(Pa->topo == NULL || Pb->topo->valor<Pa->topo->valor){
			empilhar(Pa,Pb->topo->valor);
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}
		//colocar pilha B desempilhando na pilha A
		//checando se esta vazia e se o pino a ser colocado
		//e menor do que o que ja esta la.
	}else if(Po == 2 && Pd == 3){
		if(Pc->topo == NULL || Pb->topo->valor<Pc->topo->valor){
			empilhar(Pc,Pb->topo->valor);
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}	
		//colocar pilha B desempilhando na pilha C
		//checando se esta vazia e se o pino a ser colocado
		//e menor do que o que ja esta la.
	}else if(Po == 3 && Pd == 1){
		if(Pa->topo == NULL || Pc->topo->valor<Pa->topo->valor){
			empilhar(Pa,Pc->topo->valor);
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}		
		//colocar pilha C desempilhando na pilha A
		//checando se esta vazia e se o pino a ser colocado
		//e menor do que o que ja esta la.
	}else if(Po == 3 && Pd == 2){
		if(Pb->topo == NULL || Pc->topo->valor<Pb->topo->valor){
			empilhar(Pb,Pc->topo->valor);
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}		
		//colocar pilha C desempilhando na pilha B
		//checando se esta vazia e se o pino a ser colocado
		//e menor do que o que ja esta la.
	}
}

void moverdisco(Tpilha *Pa, Tpilha *Pb, 
				Tpilha *Pc, int Po, int Pd, int *resultado){
	if(Po == 1 && Pd ==2){
		checkpino(Pa,Pb,Pc,Po,Pd);
		//colocar pilha A desempilhando na pilha B
		//checando se esta vazia e se o pino a ser colocado
		//e menor do que o que ja esta la.
	}else if(Po == 1 && Pd == 3){
		checkpino(Pa,Pb,Pc,Po,Pd);
		//colocar pilha A desempilhando na pilha C
		//checando se esta vazia e se o pino a ser colocado
		//e menor do que o que ja esta la.
	}else if(Po == 2 && Pd == 1){
		checkpino(Pa,Pb,Pc,Po,Pd);
		//colocar pilha B desempilhando na pilha A
		//checando se esta vazia e se o pino a ser colocado
		//e menor do que o que ja esta la.
	}else if(Po == 2 && Pd == 3){
		checkpino(Pa,Pb,Pc,Po,Pd);	
		//colocar pilha B desempilhando na pilha C
		//checando se esta vazia e se o pino a ser colocado
		//e menor do que o que ja esta la.
	}else if(Po == 3 && Pd == 1){
		checkpino(Pa,Pb,Pc,Po,Pd);
		//colocar pilha C desempilhando na pilha A
		//checando se esta vazia e se o pino a ser colocado
		//e menor do que o que ja esta la.
	}else if(Po == 3 && Pd == 2){
		checkpino(Pa,Pb,Pc,Po,Pd);
		//colocar pilha C desempilhando na pilha B
		//checando se esta vazia e se o pino a ser colocado
		//e menor do que o que ja esta la.
	}
}