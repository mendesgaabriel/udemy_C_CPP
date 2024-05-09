#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#define TAM 10

void imprime_vetor(int vetor[TAM], int tamanho){
	int cont;
	
	printf("\n");
	
	for(cont = 0; cont < TAM; cont++){
		printf("%d - ", vetor[cont]);	
	}
}

void fila_construtor(int *frente, int *tras){
	*frente = 0;
	*tras = -1;
	
	int cont;
}

bool fila_vazia(int frente, int tras){
	if(frente > tras){
		return true;
	}else{
		return false;
	}
}

bool fila_cheia(int tras){
	if(tras == TAM - 1){
		return true;
	}else{
		return false;
	}
}

void fila_enfileirar(int fila[TAM], int valor, int *tras){
	
	/*no caso do meu programa em específico, a fila PODE nunca estar cheia.
	pois criei um for na main específico para o TAM. sendo assim, irá ler até TAM. */
	if(fila_cheia(*tras)){
		printf("\nFila cheia!");
	}else{
		*tras = *tras + 1; //aumentar + 1 em 'tras', "alguém chegando na fila."
		fila[*tras] = valor; //recebendo valor, adicionando elemento na fila. - valor=5;
	}
	
}

void fila_desenfileirar(int fila[TAM], int *frente, int tras){
	if(fila_vazia(*frente, tras)){
		printf("Impossível desenfileirar uma lista vazia.");
	}else{
		printf(" | O valor %d foi removido.", fila[*frente]);
	fila[*frente] = 0; //substituindo valor removido por 0.
	*frente = *frente + 1; //impossível fazer *frente++, linguagem C não aceita ++ com ponteiros.
	}
	
}

int fila_tamanho(int tras, int frente){
	return (tras-frente) + 1;
}
void main(){
	int frente, tras;
	int fila[TAM] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int valor;
	
	fila_construtor(&frente, &tras);
	
	//'for' caso queira inserir valores atráves do scanf.
	/*
	int cont;
	for(cont = 0; cont < TAM; cont++){
		printf("Digite um valor: ");
		scanf("%d", &valor);
		fila_enfileirar(fila, valor, &tras);
	} */
	
	fila_enfileirar(fila, 1, &tras); // 0
	fila_enfileirar(fila, 2, &tras); // 1
	fila_enfileirar(fila, 3, &tras); // 2
	fila_enfileirar(fila, 4, &tras); // 3
	
	fila_desenfileirar(fila, &frente, tras);/* "valor 1 foi removido." lógica: o primeiro a entrar na fila, é o primeiro a sair.
	first in, first out. (FIFO) */
	fila_desenfileirar(fila, &frente, tras);
	fila_desenfileirar(fila, &frente, tras);
	
	fila_enfileirar(fila, 5, &tras); // 4
	fila_enfileirar(fila, 6, &tras); // 5
	fila_enfileirar(fila, 7, &tras); // 6
	fila_enfileirar(fila, 8, &tras); // 7
	fila_enfileirar(fila, 9, &tras); // 8
	fila_enfileirar(fila, 10, &tras); // 9
	fila_enfileirar(fila, 11, &tras); // 10
	

	imprime_vetor(fila, fila_tamanho(tras, frente));

	
	}
