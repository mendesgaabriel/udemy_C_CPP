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

int busca_binaria(int vetor[TAM], int valorprocurado, int *posicao){
	int esquerda = 0;        //limite da esquerda
	int direita = TAM - 1;   //limite da direita
	int meio;                //meio, onde fica o cursor
	
	while(esquerda <= direita){
	    //encontra o meio da análise
	meio = (esquerda + direita) / 2;
	
		//quando o valor do meio é encontrado
	if(valorprocurado == vetor[meio]){
		*posicao = meio;
		return 1;
	}
	
	//ajustando os limites laterais
	if(vetor[meio] < valorprocurado){
		esquerda = meio +1;
	}
	
	else{
		direita = meio - 1;
	}
	
			}
		}

	
void main(){
	
	int vetor[TAM] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int valorprocurado;
	int posicao;
	
	imprime_vetor(vetor);
	
	printf("\nDigite o valor a ser procurado: ");
	scanf("%d", &valorprocurado);
	
	if(busca_binaria(vetor, valorprocurado, &posicao) == 1){
		printf("\nO valor foi encontrado, na posiçao: %d", posicao);
	}
	else{
		printf("\nO valor não foi encontrado");
		
	}
	
	
}
