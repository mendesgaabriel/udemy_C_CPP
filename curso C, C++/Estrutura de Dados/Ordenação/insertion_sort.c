#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void imprimeVetor(int vetor[TAM]){
	int i;
	printf("\n");
	for(i = 0; i < TAM; i++){
		printf("%d | ", vetor[i]);
	}
}

void insertion_sort(int vetor[TAM]){
	int i, j, atual;
	for(i = 1; i < TAM; i++){
		//elemento atual em análise.
		atual = vetor[i];
		
		//elemento anterior ao analisado
		j = i - 1;
		
		while(j >= 0 && atual < vetor[j]){
			//posiciona os elementos uma posição para frente
			vetor[j + 1] = vetor[j];
			
			//faz o J andar para trás.
			j = j - 1;
		}
		
		//agora que o espaço foi aberto, colocamos o 'atual' (menor número) na posição correta
		vetor[j + 1] = atual;
		
		//atualizando vetor a cada momento, para melhor visualização
		imprimeVetor(vetor);
	}
	
}

int main(){
	int vetor[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	
	insertion_sort(vetor);
	
	imprimeVetor(vetor);
	
	
}
