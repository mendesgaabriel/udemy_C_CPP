#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#include <stdbool.h>
void imprime_vetor(int vetor[TAM]){
		int cont;
		for(cont = 0; cont<TAM; cont++){
		printf("%d - ", vetor[cont]);
	}
}

int busca_simples(int vetor[TAM], int valorprocurado, int *posicao){
	int cont;
	bool valorencontrado;
	
	for(cont = 0; cont<TAM; cont++){
		if(vetor[cont] == valorprocurado){
			valorencontrado = true;
			*posicao = cont;
		}
	}
	
	if(valorencontrado){
		return 1;
	}
	else{
		return -1;
	}
}
void main(){
	
	int vetor[TAM] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int valorprocurado;
	int posicao;
	
	imprime_vetor(vetor);
	
	printf("\nDigite o valor a ser procurado: ");
	scanf("%d", &valorprocurado);
	
	if(busca_simples(vetor, valorprocurado, &posicao) == 1){
		printf("\nO valor foi encontrado, na posiçao: %d", posicao);
	}
	else{
		printf("\nO valor não foi encontrado");
		
	}
	
	
}
