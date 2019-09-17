#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Pilha.h"

int main(){
	int num, tam;
	tam = log2 + 1;
    Tpilha *pilha = criarPilha(tam);
    printf("\nDigite o numero a ser convertido: \n");
    scanf("%i", &num);
    while(num>=0){
    	while(num > 0){
			empilhar(pilha,(num%2));
			num/=2;
		}
		while(!pilhaVazia(pilha)){
			printf("%d", desempilhar(pilha));
		}
    printf("\nDigite o numero a ser convertido: \n");
    scanf("%i", &num);		
	}	
    return 0;
}