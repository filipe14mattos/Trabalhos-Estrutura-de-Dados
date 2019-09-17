#include <stdio.h>
#include <stdlib.h>
#include "PilhacomVetor.h"

void menu(int *Po, int *Pd){
	printf("=====TORRE DE HANOI=====\n");
	printf("\nInforme o pino de origem: ");
	scanf("%i",Po);
	printf("\nInforme o pino de destino: ");
	scanf("%i",Pd);
}

int main(){
	int i, discos, aux, movimentos = 0;
	int PinoOrigem, PinoDestino;
	Tpilha *pilhaA, *pilhaB, *pilhaC;
	printf("Digite o numero de discos que quer jogar: ");
	scanf("%i", &discos);
	pilhaA = criarPilha(discos);
	pilhaB = criarPilha(discos);
	pilhaC = criarPilha(discos);
	aux = discos;
	for(i=0;i<aux;i++){
		empilhar(pilhaA,discos);
		discos--;
	}
	printf(" Pino 1: \n");
	printar(pilhaA);
	do{
		menu(&PinoOrigem,&PinoDestino);
		moverdisco(pilhaA,pilhaB,pilhaC,PinoOrigem,PinoDestino);
		movimentos++;
		printf(" Pino 1: \n");
		printar(pilhaA);
		printf(" Pino 2: \n");
		printar(pilhaB);
		printf(" Pino 3: \n");
		printar(pilhaC);
	}while(!(pilhaVazia(pilhaA) && pilhaVazia(pilhaB)));
	printf("\n===========Parabens voce ganhou!!===========\n");
	printf("Voce realizou: %i movimentos!!\n", movimentos);
	printf(" Pino 1: \n");
	printar(pilhaA);
	printf(" Pino 2: \n");
	printar(pilhaB);
	printf(" Pino 3: \n");
	printar(pilhaC);
	return 0;
}