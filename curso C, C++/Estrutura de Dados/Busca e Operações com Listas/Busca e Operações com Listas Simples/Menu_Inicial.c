#include <stdio.h>
#include <stdlib.h>


void limpaTela(){
	system("CLS");
	
}
int main(){
	
	//Variáveis;
	int funcaoDesejada = 1;
	
	while(funcaoDesejada < 10 && funcaoDesejada > 0){
	printf("***** Operacoes ***** \n");
	printf("\n1 - Insercao de um node no inicio da lista");
	printf("\n2 - Insercao de um node no fim da lista");
	printf("\n3 - Insercao de um node na posicao N");
	printf("\n4 - Retirar um node no inicio da lista");
	printf("\n5 - Retirar um node no fim da lista");
	printf("\n6 - Retirar um node na posicao N");
	printf("\n7 - Procurar um node com o campo RG");
	printf("\n8 - Imprimir a lista");
	printf("\n9 - Sair do sistema");
	printf("\nEscolha um número e presione ENTER: \n");
	scanf("%d", &funcaoDesejada);
	
	limpaTela();
	
	switch(funcaoDesejada){
		case 1:
			printf("Funcao escolhida: 1 ");
			break;
		case 2:
			printf("Funcao escolhida: 2 ");
			break;
		case 3:
			printf("Funcao escolhida: 3 ");
			break;
		case 4:
			printf("Funcao escolhida: 4 ");
			break;
		case 5:
			printf("Funcao escolhida: 5 ");
			break;
		case 6:
			printf("Funcao escolhida: 6 ");
			break;
		case 7:
			printf("Funcao escolhida: 7 ");
			break;
		case 8:
			printf("Funcao escolhida: 8 ");
			break;
		case 9:
			printf("Funcao escolhida: 9 ");
			break;
	}
	}
	
}
