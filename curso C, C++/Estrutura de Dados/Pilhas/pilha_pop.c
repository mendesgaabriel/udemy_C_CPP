#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void imprime_vetor(int vetor[TAM], int topo){

	int cont; //variável aux
	printf("\n");
	
	for(cont = 0; cont <TAM; cont++){
		printf("%d - ", vetor[cont]);
	}
	
	printf("Topo: %d", topo);
}

void pilha_push(int pilha[TAM], int valor, int *topo){
	//caso não possa colocar mais valores
	if(*topo == TAM - 1){
		printf("Pilha cheia!");		 
	}
	else{
		*topo = *topo + 1;
		pilha[*topo] = valor;
	}
	
}

void pilha_pop(int pilha[TAM], int *topo){
	if(*topo == -1){
		printf("Pilha vazia!");
	}
	else{
		printf("Valor removido: %d", pilha[*topo]);
		pilha[*topo] = 0;
		*topo = *topo - 1;
	}
	
	
}
void main(){
	int pilha[TAM] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int topo = -1;   //topo da pilha
	
	imprime_vetor(pilha, topo);
	
	pilha_push(pilha, 5, &topo);
	imprime_vetor(pilha, topo);
	
	pilha_push(pilha, 7, &topo);
	imprime_vetor(pilha, topo);
	
	pilha_pop(pilha, &topo);
	imprime_vetor(pilha, topo);
	
	
	
	}
