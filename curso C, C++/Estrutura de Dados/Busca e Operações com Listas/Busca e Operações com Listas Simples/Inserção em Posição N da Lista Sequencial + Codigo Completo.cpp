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

void adcFimSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, string nome, int rg){
	//cria uma lista com um tamanho maior
	pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista + 1];
	
	//passa os elementos do vetor antigo para o novo
	int cont;
	for(cont = 0; cont < *tamanhoDaLista; cont++){
		novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
		novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
	}
	
	//posiciona o último elemento
	novaListaSequencial[*tamanhoDaLista].nome = nome;
	novaListaSequencial[*tamanhoDaLista].rg = rg;
	
	//atualiza o ponteiro para a lista nova
	ponteiroSequencial = novaListaSequencial;
	
	//aumenta o tamanho da lista
	*tamanhoDaLista = *tamanhoDaLista + 1;
	
}

void adcPosicaoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, string nome, int rg, int posicao){
	//cria uma lista com um tamanho maior
	pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista + 1];
	
	//passa os elementos do vetor antigo para o novo
	int cont;
	for(cont = 0; cont < posicao; cont++){
		novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
		novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
	}
	
	//adiciona o novo registro na posicao correta
	novaListaSequencial[posicao].nome = nome;
	novaListaSequencial[posicao].rg = rg;
	
	//coloca o resto dos valores antigos
	for(cont = posicao + 1; cont < *tamanhoDaLista + 1; cont++){
		novaListaSequencial[cont].nome = ponteiroSequencial[cont - 1].nome;
		novaListaSequencial[cont].rg = ponteiroSequencial[cont - 1].rg;
	}
	
	//atualiza o ponteiro para a lista nova
	ponteiroSequencial = novaListaSequencial;
	
	//aumenta o tamanho da lista
	*tamanhoDaLista = *tamanhoDaLista + 1;
	
	
}

void removeInicioSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista){
	
	//cria um vetor com uma posição a menos
	pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista - 1];
	
	//passa os elementos do vetor antigo para o novo
	int cont;
	for(cont = 1; cont < *tamanhoDaLista; cont++){
		novaListaSequencial[cont - 1].nome = ponteiroSequencial[cont].nome;
		novaListaSequencial[cont - 1].rg = ponteiroSequencial[cont].rg;
	 	}
	 
	 //atualiza o ponteiro para a lista nova
	ponteiroSequencial = novaListaSequencial;
	
	//aumenta o tamanho da lista
	*tamanhoDaLista = *tamanhoDaLista - 1;
}

void removeFimSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista){
	
	//cria um vetor com uma posição a menos
	pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista - 1];
	
	//passa os elementos do vetor antigo para o novo, menos o último
	int cont;
	for(cont = 0; cont < *tamanhoDaLista - 1; cont++){
		novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
		novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
	 	}
	
	//atualiza o ponteiro para a lista nova
	ponteiroSequencial = novaListaSequencial;
	
	//aumenta o tamanho da lista
	*tamanhoDaLista = *tamanhoDaLista - 1;
	
}

void removePosicaoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, int posicao){
	
	//cria um vetor com uma posição a menos
	pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista - 1];
	
	//passa os valores de acordo com o contador
	int cont;
	for(cont = 0; cont < *tamanhoDaLista - 1; cont++){
		
		if(cont < posicao){
				//se estiver antes da posição, passa normalmente
		novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
		novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
		}else{
				//se estiver antes da posição, passa normalmente
		novaListaSequencial[cont].nome = ponteiroSequencial[cont + 1].nome;
		novaListaSequencial[cont].rg = ponteiroSequencial[cont + 1].rg;
		}
	}
	
	//atualiza o ponteiro para a lista nova
	ponteiroSequencial = novaListaSequencial;
	
	//aumenta o tamanho da lista
	*tamanhoDaLista = *tamanhoDaLista - 1;
}

string retornaNomeSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, int rg){
	
	string nome = "Não encontrado";
	
	//busca pelo nome com o RG digitado
	int cont;
	for(cont = 0; cont < *tamanhoDaLista; cont++){
		if(ponteiroSequencial[cont].rg == rg){
			
			nome = ponteiroSequencial[cont].nome;
			
		}
	}
	
	return nome;
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
	
	
	while(funcaoDesejada < 9 && funcaoDesejada > 0){
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
	int rg, posicao;
	
	switch(funcaoDesejada){
		case 1:
			printf("Funcao escolhida: 1 - Insercao de um node no inicio da lista\n");
			cout << "Digite um nome: ";
			cin >> nome;
			cout << "Digite um RG: ";
			cin >> rg;
			
			adcComecoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
			
			
			break;
		case 2:
			printf("Funcao escolhida: 2 - Insercao de um node no fim da lista\n");
			cout << "Digite um nome: ";
			cin >> nome;
			cout << "Digite um RG: ";
			cin >> rg;
			
			//se a lista for vazia, usamos a função de criar no início
			if(tamanhoDaLista == 0){
				adcComecoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
			}else{
				adcFimSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
			}
			
			break;
		case 3:
			printf("Funcao escolhida: 3 - Insercao de um node na posicao N\n");
			
			cout << "Digite uma posição: ";
			cin >> posicao;
			
			cout << "Digite um nome: ";
			cin >> nome;
			
			cout << "Digite um RG: ";
			cin >> rg;
			
			if(posicao == 0){
				//se estiver adicionando no começo
				adcComecoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
			}else if(posicao == tamanhoDaLista){
				//quando quer adicionar ao fim
				adcFimSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
			}else{
				//adiciona numa posicao específica
				adcPosicaoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg, posicao);
			}
			
	
			break;
		case 4:
			printf("Funcao escolhida: 4 - Retirar um node no inicio da lista\n");
			//se a lsita for vazia
			if(tamanhoDaLista == 0){
				cout << "Lista vazia.\n";
			}else{
				removeInicioSequencial(ponteiroSequencial, &tamanhoDaLista);
			}
			break;
		case 5:
			printf("Funcao escolhida: 5 - Retirar um node no fim da lista\n");
			
			//se a lista for vazia
			if(tamanhoDaLista == 0){
				cout << "Lista vazia.\n";
			}else{
				removeFimSequencial(ponteiroSequencial, &tamanhoDaLista);
			}
			
			break;
		case 6:
			printf("Funcao escolhida: 6 - Retirar um node na posicao N\n");
			
			//se a lista for vazia
			if(tamanhoDaLista == 0){
				cout << "Lista vazia.\n";
			}else{
				cout << "Digite uma posição: ";
				cin >> posicao;
			}
			
			if(posicao == 0){
				removeInicioSequencial(ponteiroSequencial, &tamanhoDaLista);
			}else if(posicao == tamanhoDaLista - 1){
				removeFimSequencial(ponteiroSequencial, &tamanhoDaLista);
			}else{
					//Remove do posicao desejada da lista
                        removePosicaoSequencial(ponteiroSequencial, &tamanhoDaLista, posicao);
                    }
 
			
			break;
		case 7:
			printf("Funcao escolhida: 7 - Procurar um node com o campo RG\n");
			
			//se a lista for vazia
			if(tamanhoDaLista == 0){
				cout << "Lista vazia.\n";
			}else{
				cout << "Digite uma RG: ";
				cin >> rg;
				
			cout << "\nNome do RG: " << rg << ": " << retornaNomeSequencial(ponteiroSequencial, &tamanhoDaLista, rg) <<"\n";
			}
			
 
			
			break;
		case 8:
			printf("Funcao escolhida: 8 - Imprimir a listan\n");
			imprimeSequencial(ponteiroSequencial, tamanhoDaLista);
			break;
		case 9:
			printf("Funcao escolhida: 9 - Sair do sistema ");
			break;
	}
	}
	
}
