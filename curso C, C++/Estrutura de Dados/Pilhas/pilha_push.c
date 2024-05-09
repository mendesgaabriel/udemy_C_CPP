#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void imprime_vetor(int vetor[TAM]){

	int cont; //vari�vel aux
	printf("\n");
	
	for(cont = 0; cont <TAM; cont++){
		printf("%d - ", vetor[cont]);
	}
}

void pilha_push(int pilha[TAM], int valor, int *topo){
	//caso n�o possa colocar mais valores
	if(*topo == TAM - 1){
		printf("Pilha cheia!");		
	}
	else{
		*topo = *topo + 1;
		pilha[*topo] = valor;
	}
	
}
void main(){
	int pilha[TAM] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int topo = -1;    //topo da pilha
	
	imprime_vetor(pilha);
	
	pilha_push(pilha, 5, &topo);
	pilha_push(pilha, 7, &topo);
	
	
	
	imprime_vetor(pilha);
	}
