#include <stdio.h>
#include <stdlib.h>
#include "PilhaComPonteiro.h"

int main(){
	Tpilha pilha;
	inicPilha(&pilha);
    int num;
    printf("\nDigite o numero a ser convertido: \n");
    scanf("%i", &num);
    while(num>=0){
    	while(num > 0){
			empilhar(&pilha,(num%2));
			num/=2;
		}
		while(!pilhaVazia(&pilha)){
			printf("%d", desempilhar(&pilha));
		}
		printf("\nDigite o numero a ser convertido: \n");
    	scanf("%i", &num);
	}
    return 0;
}