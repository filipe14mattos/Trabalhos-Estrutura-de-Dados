#include <stdio.h>
#include <stdlib.h>
#include "PilhaComPonteiro.h"

void menu(int *Po, int *Pd){
	printf("=====TORRE DE HANOI=====\n");
	printf("\nInforme o pino de origem: ");
	scanf("%i",Po);
	printf("\nInforme o pino de destino: ");
	scanf("%i",Pd);
}

int main(){
	int i, discos = 5 , movimentos = 0;
	int PinoOrigem, PinoDestino, resultado = 1;
	Tpilha pilhaA;
	inicPilha(&pilhaA);
	Tpilha pilhaB;
	inicPilha(&pilhaB);
	Tpilha pilhaC;
	inicPilha(&pilhaC);
	for(i=0;i<5;i++){
		empilhar(&pilhaA,discos);
		discos--;
	}
	menu(&PinoOrigem,&PinoDestino);
	while(resultado!=0){
	moverdisco(&pilhaA,&pilhaB,&pilhaC,PinoOrigem,PinoDestino);
	movimentos++;
	printf(" Pino 1: \n");
	printar(&pilhaA);
	printf(" Pino 2: \n");
	printar(&pilhaB);
	printf(" Pino 3: \n");
	printar(&pilhaC);
	if(pilhaVazia(&pilhaA) && pilhaVazia(&pilhaB)){
		printf("\n===========Parabens voce ganhou!!===========\n");
		printf("Voce realizou: %i movimentos!!\n", movimentos);
		printf(" Pino 1: \n");
		printar(&pilhaA);
		printf(" Pino 2: \n");
		printar(&pilhaB);
		printf(" Pino 3: \n");
		printar(&pilhaC);
		resultado = 0;
		break;
		}
		menu(&PinoOrigem,&PinoDestino);
	}
	return 0;
}