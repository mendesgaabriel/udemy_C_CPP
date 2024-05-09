#include <stdio.h>
#include <stdlib.h>
#define TAM 3

//aloca um vetor do tamanho pedido
int* alocaVetor(int tam){
	//cria um ponteiro auxiliar
	int *v;
	
	//aloca memória para o novo vetor
	v = (int *) malloc(tam * sizeof(int));
	return v;
}

//imprime a lista sequencial
void imprimeSequencial(int *vetor, int tamanhoDaListaSequencial){
	int cont;
	for(cont = 0; cont < tamanhoDaListaSequencial; cont++){
		printf("\nValor %d: %d ", cont, vetor[cont]);
	}
}

int main(){
	
	//variáveis
	int tamanhoDaLista;
	int vetor[TAM] = {1, 2, 3};
	
	//exibindo valores:
	int cont;
	for(cont = 0; cont < TAM; cont++){
		printf("\nValor %d: %d ", cont, vetor[cont]);
	}
	
	
	imprimeSequencial(vetor, 3);
	
	for(cont = 0; cont < TAM; cont++){
		printf("\nEscreva um valor: ");
		scanf("%d", &vetor[cont]);
	}
	
	imprimeSequencial(vetor, 3);
	
	//pedindo tamanho do vetor
	printf("\nDigite o tamanho do vetor: ");
	scanf("%d", &tamanhoDaLista);
	
	//ponteiro para o novo vetor
	int *vetorLidoNaHora;
	
	//passa o espaço da memória que foi criado para o vetor
	vetorLidoNaHora = alocaVetor(tamanhoDaLista);	
	
	//lendo novos valores
	for(cont = 0; cont < tamanhoDaLista; cont++){
		printf("\nEscreva um valor: ");
		scanf("%d", &vetorLidoNaHora[cont]);
	}
	
	imprimeSequencial(vetorLidoNaHora, tamanhoDaLista);

	
	
}
