#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void imprimeVetor(int vetor[TAM]){
	int i;
	printf("\n");
	for(i=0; i < TAM; i++){
		printf("|%d| ", vetor[i]);
	}
}

void bubble_sort(int vetor[TAM]){
	
	//auxiliares
	int x, y, aux;
	
	//valor da esquerda sendo analisado
	for(x = 0; x < TAM; x++){
		//valor da esquerda sendo analisado
		for(y = x + 1; y < TAM; y++){
			
			//conferindo se é preciso fazer a troca.
			if(vetor[x]  > vetor[y]){
				aux = vetor[x];
				vetor[x] = vetor[y];
				vetor[y] = aux;
			}
		}
	}
	
}
int main(){
	int vetor[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	
	imprimeVetor(vetor);
	
	bubble_sort(vetor);
	
	imprimeVetor(vetor);
}
