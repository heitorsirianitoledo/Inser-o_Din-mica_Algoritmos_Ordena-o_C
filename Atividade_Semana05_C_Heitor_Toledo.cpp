#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n,int *comparacoes, int *trocas){
	*comparacoes = 0;
	*trocas = 0;
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			(*comparacoes)++;
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				(*trocas)++;
			}
		}
	}
}

void selectionSort(int arr[], int n, int *comparacoes, int *trocas){
	*comparacoes = 0;
	*trocas = 0;
	int i,j,temp,min_idx;
	for(i=0;i<n-1;i++){
		min_idx = i;
		for(j=i+1;j < n;j++){
			(*comparacoes)++;
			if(arr[j] < arr[min_idx]){
				min_idx = j;
			}
		}
		temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
		(*trocas) ++;
	}
	
}

void insertionSort(int arr[],int n,int *comparacoes, int *trocas){
	*comparacoes = 0;
	*trocas = 0;
	int i,j,key;
	for(i=1;i < n; i++){
		key = arr[i];
		j = i - 1;
		(*comparacoes) ++;
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j = j - 1;
		}
		
		arr[j+1] = key;
		(*trocas) ++;
	}
}

void swap(int arr[],int a,int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int partition(int arr[], int low, int high, int *comparacoes, int *trocas){
	int pivot = arr[high];
	int i = (low - 1);
	for(int j = low; j < high; j++){
		(*comparacoes) ++;
		if(arr[j] < pivot){
			i++;
			swap(arr,i,j);
			(*trocas) ++;
		}
	}
	swap(arr,i+1,high);
	(*trocas) ++;
	return (i+1);
}

void quickSort(int arr[],int low, int high,int *comparacoes, int *trocas){
	if(low < high){
		int pi = partition(arr,low,high,comparacoes,trocas);
		quickSort(arr,low,pi - 1,comparacoes,trocas);
		quickSort(arr,pi + 1, high,comparacoes,trocas);
	}
}

void merge(int arr[], int l, int m, int r, int *comparacoes, int *trocas) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        (*comparacoes)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            (*trocas)++;
            i++;
        } else {
            arr[k] = R[j];
            (*trocas)++;
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        (*trocas)++;
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        (*trocas)++;
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int *comparacoes, int *trocas){
	if(l < r){
		int m = l + (r - l)/2;
		mergeSort(arr,l,m,comparacoes,trocas);
		mergeSort(arr,m+1,r,comparacoes,trocas);
		merge(arr,l,m,r,comparacoes,trocas);
	}
}

void printArray(int arr[], int n){
	for(int i = 0;i < n;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int opcao;
	int tamanho;
	int comparacoes;
	int trocas;
	int i = 0;
	int totalComparacoes = 0;
    int totalTrocas = 0;
	
	printf("Escolha o algoritmo a ser usado: \n");
	printf("1- Bubble Sort\n");
	printf("2- Selection Sort\n");
	printf("3- Insertion Sort\n");
	printf("4- Quick Sort\n");
	printf("5- Merge Sort\n");
	printf("Opcao: ");
	scanf("%d", &opcao);
	
	printf("Quantos valores deseja inserir? \n");
	scanf("%d", &tamanho);
	
	int vetor[tamanho];
	
	do{
		printf("Digite o valor: \n");
		scanf("%d", &vetor[i]);
		comparacoes = 0;
		trocas = 0;
		
		switch(opcao){
			case 1:
				bubbleSort(vetor,i+1,&comparacoes,&trocas);
				break;
				
			case 2:
				selectionSort(vetor,i+1,&comparacoes,&trocas);
				break;
			case 3:
				insertionSort(vetor,i+1,&comparacoes,&trocas);
				break;
			case 4:
				quickSort(vetor,0,i,&comparacoes,&trocas);
				break;
			case 5:
				mergeSort(vetor,0,i,&comparacoes,&trocas);
				break;
			default:
				printf("Opcao Invalida\n");
				return 0;
		}
		printf("Estrutura Atual: \n");
		printArray(vetor,i+1);
		
		printf("Comparacoes: %d\n", comparacoes);
		printf("Trocas: %d\n", trocas);
		totalComparacoes += comparacoes;
        totalTrocas += trocas;
		
		i++;
	} while(i < tamanho);
	
		printf("\nTotal de Comparacoes no final: %d\n", totalComparacoes);
		printf("Total de trocas no final: %d\n", totalTrocas);
	
	return 0;
	

}

