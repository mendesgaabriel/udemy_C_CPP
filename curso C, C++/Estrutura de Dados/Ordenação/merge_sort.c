#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void imprimeVetor(int vetor[]){
	printf("\n");
	int i;
	for(i = 0; i < TAM; i++){
		printf("|%d| ", vetor[i]);
	}
}

//uni os dois subarrays (1 com a primeira metade e 1 com a segunda metade) que foram criados.
void merge(int vetor[TAM], int indiceEsquerdo,int meio, int indiceDireito){
	
	int n1 = meio - indiceEsquerdo + 1; //tamanho do primeiro vetor auxiliar
	int n2 = indiceDireito - meio;      //tamanho do segundo vetor auxiliar
	
	//cria dois Arrays temporários
	int vetorEsquerdo[n1], vetorDireito[n2];
	
	//passa os elementos do vetor principal para o primeiro vetor auxiliar (vetorEsquerda)
	int i, j, k; //auxiliares contadoras
	for(i = 0; i < n1; i++){
		vetorEsquerdo[i] = vetor[indiceEsquerdo + i];
	}
	
	//passa os elementos do vetor principal para o segundo vetor auxiliar (vetorDireito)
	for(j = 0; j < n2; j++){
		vetorDireito[j] = vetor[meio + 1 + j];
	}
	
	//reseta as variáveis
	i = 0, j = 0;
	
	k = indiceEsquerdo;
	
	while(i < n1 && j < n2){
		
		//caso o valor na esquerda seja meenor
		if(vetorEsquerdo[i] <= vetorDireito[j]){
			
			//passa para o meu vetor principal o valor menor
			vetor[k] = vetorEsquerdo[i];
			
			//incrementa o auxiliar para passar  a análise para os próximos valores do vetor auxiliar
			i++;
			
		}else{
			//passa para o meu vetor principal o menor valor
			vetor[k] = vetorDireito[j];
			
			//incrementa o auxiliar para passar  a análise para os próximos valores do vetor auxiliar
			j++;
			
		}
		
		//aumenta o indice de posicionamento no vetor
		k++;
		
	}
	
	//se faltarem alguns elementos do array ESQUERDO, passa eles para o array principal
	while(i < n1){
		vetor[k] = vetorEsquerdo[i];
		i++;
		k++;
	}
	
	//se faltarem alguns elementos do array DIREITO, passa eles para o array principal
	while(j < n2){
		vetor[k] = vetorDireito[j];
		j++;
		k++;
	}
	
	
	
}

//função prncipal
void merge_sort(int vetor[TAM], int indiceEsquerdo, int indiceDireito){
	
	if(indiceEsquerdo < indiceDireito){
		//encontra o meio
		int meio = indiceEsquerdo + (indiceDireito - indiceEsquerdo) / 2;
		
		//da metade para trás
		merge_sort(vetor, indiceEsquerdo, meio);
		
		//da metade para frente
		merge_sort(vetor, meio+1, indiceDireito);
		
		
		//visualizando o processo
		imprimeVetor(vetor);
		
		//uni os dois subarrays (1 com a primeira metade e 1 com a segunda metade) que foram criados.
		merge(vetor, indiceEsquerdo, meio, indiceDireito);
		
	}
}

int main(){
	int vetor[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	
	imprimeVetor(vetor);
	
	merge_sort(vetor, 0, TAM - 1);
	
	imprimeVetor(vetor);
}
