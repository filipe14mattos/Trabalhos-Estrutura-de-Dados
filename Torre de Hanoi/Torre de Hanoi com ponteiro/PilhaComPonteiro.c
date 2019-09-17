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
//Essa função checa se o topo da pilha é igual a vazio ou se o valor do topo atual e menor doque
//o valor a ser substituido. Caso essa verificaçao seja possivel o valor apontado e empilhado na 
//pilha selecionada e desempilhado da sua pilha de origem.
void checkPino(struct TipoPilha *Pa, struct TipoPilha *Pb, 
              struct TipoPilha *Pc, int Po, int Pd){
	if(Po == 1 && Pd ==2){
		if((Pb->topo == NULL) || (Pa->topo->valor<Pb->topo->valor)){
			empilhar(Pb,Pa->topo->valor);
			desempilhar(Pa);
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}
	}else if(Po == 1 && Pd == 3){
		if((Pc->topo == NULL) || (Pa->topo->valor<Pc->topo->valor)){
			empilhar(Pc,Pa->topo->valor);
			desempilhar(Pa);
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}
	}else if(Po == 2 && Pd == 1){
		if((Pa->topo == NULL) || (Pb->topo->valor<Pa->topo->valor)){
			empilhar(Pa,Pb->topo->valor);
			desempilhar(Pb);
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}
	}else if(Po == 2 && Pd == 3){
		if((Pc->topo == NULL) || (Pb->topo->valor<Pc->topo->valor)){
			empilhar(Pc,Pb->topo->valor);
			desempilhar(Pb);
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}	
	}else if(Po == 3 && Pd == 1){
		if((Pa->topo == NULL) || (Pc->topo->valor<Pa->topo->valor)){
			empilhar(Pa,Pc->topo->valor);
			desempilhar(Pc);
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}		
	}else if(Po == 3 && Pd == 2){
		if((Pb->topo == NULL) || (Pc->topo->valor<Pb->topo->valor)){
			empilhar(Pb,Pc->topo->valor);
			desempilhar(Pc);
		}else{
			printf("\nMovimento nao permitido!\n");
			printf("\nTente novamente!\n");
		}
	}
}
//Essa funçao pega a pilha de origem e a pilha de destino que o usuario digitou, achando uma opção
//e chamado a checagem se é possivel empilhar o dado da pilha de origem na pilha de destino
void moverdisco(Tpilha *Pa, Tpilha *Pb, 
				Tpilha *Pc, int Po, int Pd){
	if(Po == 1 && Pd ==2){
		checkPino(Pa,Pb,Pc,Po,Pd);
	}else if(Po == 1 && Pd == 3){
		checkPino(Pa,Pb,Pc,Po,Pd);
	}else if(Po == 2 && Pd == 1){
		checkPino(Pa,Pb,Pc,Po,Pd);
	}else if(Po == 2 && Pd == 3){
		checkPino(Pa,Pb,Pc,Po,Pd);	
	}else if(Po == 3 && Pd == 1){
		checkPino(Pa,Pb,Pc,Po,Pd);
	}else if(Po == 3 && Pd == 2){
		checkPino(Pa,Pb,Pc,Po,Pd);
	}
}

//Essa função e usada para printar a pilha fazendo o auxiliar receber o valor do topo imprimir na
//tela e ir para o valor anterior ao printado das pilha.
void printar(struct TipoPilha *p){
	TElemento *aux = p->topo;
	while(aux != NULL){
		printf("\t|%i|\n", aux->valor);
		aux = aux->abaixo;
	}
}