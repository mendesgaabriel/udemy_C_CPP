#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void imprimevetor(int vetor[TAM]){
	int i;
	printf("\n");
	for(i = 0; i < TAM; i++){
		printf("| %d", vetor[i]);
	}
}

void selection_sort(int vetor[TAM]){
	int posicaoMenorValor, aux, i, j;
	for(i = 0; i < TAM; i++){
		//recebe a posição inicial para o menor valor
		posicaoMenorValor = i;
		
		//analisa os elementos na frente
		for(j = i + 1; j < TAM; j++){
			
			//caso encontre um valor menor na frente dos analisados.
			if(vetor[j] < vetor[posicaoMenorValor]){
				posicaoMenorValor = j;
			}
		}
		
		//verifica se houve mudança e troca os valores.
		if(posicaoMenorValor != i){
			aux = vetor[i];
			vetor[i] = vetor[posicaoMenorValor];
			vetor[posicaoMenorValor] = aux;
		}
		imprimevetor(vetor); 
		
	}
}

int main(){
	int vetor[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	
	selection_sort(vetor);
	
	imprimevetor(vetor);
}
