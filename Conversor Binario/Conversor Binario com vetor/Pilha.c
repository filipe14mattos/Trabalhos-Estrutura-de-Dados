#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

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