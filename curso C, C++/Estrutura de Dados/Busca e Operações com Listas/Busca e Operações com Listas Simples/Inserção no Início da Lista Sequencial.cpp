#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>

using namespace std;

struct pessoa{
	string nome;
	int rg;
};


void limpaTela(){
	system("CLS");
}

void imprimeSequencial(pessoa *ponteiroSequencial, int tamanhoDaLista){
	int cont;
	for(cont = 0; cont < tamanhoDaLista; cont++){
		cout << cont << " - " << ponteiroSequencial[cont].nome << "," << ponteiroSequencial[cont].rg << "\n";
	}
}

void adcComecoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, string nome, int rg){
	
	//se a lista for vazia, cria uma lista nova.
	if(*tamanhoDaLista == 0){
		pessoa *novaListaSequencial = new pessoa[1];
		
		//insere o primeiro NOVO elemento
	novaListaSequencial[0].nome = nome;
	novaListaSequencial[0].rg = rg;
	
	//atualiza o ponteiro para a lista nova
	ponteiroSequencial = novaListaSequencial;
		
	}else{
		
		//caso a lista já tenha membros
	pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista + 1];
	
	//insere o primeiro NOVO elemento
	novaListaSequencial[0].nome = nome;
	novaListaSequencial[0].rg = rg;
	
	//passa os elementos do vetor antigo para o novo
	int cont;
	for(cont = 0; cont < *tamanhoDaLista; cont++){
		novaListaSequencial[cont + 1].nome = ponteiroSequencial[cont].nome;
		novaListaSequencial[cont + 1].rg = ponteiroSequencial[cont].rg;
	}
	
	//atualiza o ponteiro para a lista nova
	ponteiroSequencial = novaListaSequencial;
		
	}
	
		//aumenta o tamanho da lista
	*tamanhoDaLista = *tamanhoDaLista + 1;
	
	
}
int main(){
	
	//Variáveis;
	int funcaoDesejada = 1;
	
	//ponteiro para lista sequencial
	pessoa *ponteiroSequencial;
	
	//tamanho da lista
	int tamanhoDaLista = 0;
	
	/*EXEMPLO
	pessoa *exemploListaSequencial = new pessoa[2];
	
	//dois registros de exemplo
	exemploListaSequencial[0].nome = "John";
	exemploListaSequencial[0].rg = 123;
	exemploListaSequencial[1].nome = "Maicon";
	exemploListaSequencial[1].rg = 321; 
	
	//faz o ponteiro principal apontar para o novo vetor
	ponteiroSequencial = exemploListaSequencial; */
	
	
	while(funcaoDesejada < 10 && funcaoDesejada > 0){
		imprimeSequencial(ponteiroSequencial, tamanhoDaLista);
	printf("***** Operacoes ***** \n");
	printf("\n1 - Insercao de um node no inicio da lista");
	printf("\n2 - Insercao de um node no fim da lista");
	printf("\n3 - Insercao de um node na posicao N");
	printf("\n4 - Retirar um node no inicio da lista");
	printf("\n5 - Retirar um node no fim da lista");
	printf("\n6 - Retirar um node na posicao N");
	printf("\n7 - Procurar um node com o campo RG");
	printf("\n8 - Imprimir a lista");
	printf("\n9 - Sair do sistema");
	printf("\nEscolha um número e presione ENTER: \n");
	scanf("%d", &funcaoDesejada);
	
	limpaTela();
	
	//variáveis usadas na operação
	string nome;
	int rg;
	
	switch(funcaoDesejada){
		case 1:
			printf("Funcao escolhida: 1 - Insercao de um node no inicio da lista ");
			cout << "\nDigite um nome: ";
			cin >> nome;
			cout << "\nDigite um RG: ";
			cin >> rg;
			
			adcComecoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
			
			
			break;
		case 2:
			printf("Funcao escolhida: 2 ");
			break;
		case 3:
			printf("Funcao escolhida: 3 ");
			break;
		case 4:
			printf("Funcao escolhida: 4 ");
			break;
		case 5:
			printf("Funcao escolhida: 5 ");
			break;
		case 6:
			printf("Funcao escolhida: 6 ");
			break;
		case 7:
			printf("Funcao escolhida: 7 ");
			break;
		case 8:
			printf("Funcao escolhida: 8 ");
			break;
		case 9:
			printf("Funcao escolhida: 9 ");
			break;
	}
	}
	
}
