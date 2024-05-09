#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#define TAM 10
//função para verificar tamanho da pilha, inserida em imprime_vetor;
int pilha_tamanho(int topo){
	return topo + 1; //retornando o tamanho da pilha. logo que topo = -1, necessário add 1 para saber o valor.
	printf(" Tamanho da pilha: %d", pilha_tamanho(topo));
}

//conferindo último elemento da pilha
int pilha_get(int pilha[TAM], int *topo){
	if(*topo == -1){
		printf("Último elemento vazio.");
		return 0;
	}else{
		return pilha[*topo];
	}
}

//imprimindo pilha
void imprime_vetor(int vetor[TAM], int topo){

	int cont; //variável aux
	printf("\n");
	
	for(cont = 0; cont <TAM; cont++){
		printf("%d - ", vetor[cont]);
	}
	
	printf("Topo: %d Tamanho da pilha: %d", topo, pilha_tamanho(topo));
}

//verificando se pilha está vazia.
bool pilha_vazia(int topo){
	if(topo == -1){
		return true;
	}
	else{
		return false;
	}
}

//checando caso pilha esteja cheia.
bool pilha_cheia(int topo){
	if(topo == TAM - 1){
		return true;
	}else{
		return false;
	}
}

//inserindo valores na pilha.
void pilha_push(int pilha[TAM], int valor, int *topo){
	//caso não possa colocar mais valores
	if(pilha_cheia(*topo)){
		printf(" Pilha cheia!"); 
	}else{
		*topo = *topo + 1;
		pilha[*topo] = valor;
	}
	
	
}

//removendo valores da pilha.
void pilha_pop(int pilha[TAM], int *topo){
	if(pilha_vazia(*topo)){
		printf(" A pilha está vazia!");
	}
	else{
		printf(" Valor removido: %d", pilha[*topo]);
		pilha[*topo] = 0;
		*topo = *topo - 1;
	}
	
	
}

//criando uma pilha e limpando.
void pilha_construtor(int pilha[TAM], int *topo){
 	//coloca o topo negativo para indicar uma pilha vazia
 	*topo = -1;
 	
 	int cont;
 	//zerando conteúdos da pilha. also: pilha[TAM] = {0, 0, 0, ... até 10 valores.}
 	for(cont = 0; cont < TAM; cont++){
 		pilha[cont] = 0;
	 }
 }
void main(){
	setlocale(LC_ALL, "");
	int pilha[TAM];
	int topo;   //topo da pilha
	
	pilha_construtor(pilha, &topo);
	
	imprime_vetor(pilha, topo);
	
	pilha_push(pilha, 5, &topo);
	imprime_vetor(pilha, topo);
	printf(" Último elemento da pilha: %d ", pilha_get(pilha, &topo));
	
	
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	
	imprime_vetor(pilha, topo);
	

	
	pilha_pop(pilha, &topo);
	imprime_vetor(pilha, topo);
	
	
	
	}
