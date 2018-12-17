#include <stdlib.h>
#include <stdio.h>
#define MAX 4

void main(){

    //Declara uma matriz genérica
    int A[MAX][MAX] = {
        {3,1,0,6},
        {2,15,90,7},
        {51,89,2,-8},
        {-8,-9,-10,250}
    };

    printf("Matriz antes de ornernar linhas de forma crescente:\n\n");
    
    imprimeMatriz(A, MAX);

    printf("\n\nMatriz apos ordenacao de linhas de forma crescente:\n\n");

    ordenaMatrizLinha(A, MAX);
    imprimeMatriz(A, MAX);

    printf("\n\n");

    system("pause");

    return 0;
}

void ordenaMatrizLinha(int **A, int N){
    int aAux[N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            aAux[j] = A[i*N + j];

        qSort(aAux, 0, N-1);

        for(int j = 0; j < N; j++)
            A[i*N + j] = aAux[j];
    }        
}

void imprimeMatriz(int **A, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            printf("\t%d    ", A[i*N + j]);
        printf("\n");
    }
}

void qSort(int *A, int inicio, int fim){
    int aux = 0;
    int i = inicio, j = fim;
    int pivot = A[(inicio+fim)/2];    

    while(i <= j){
        for(;A[i] < pivot && i < fim; i++);			
		//Caso o elemento na posição a[j] for maior que o pivô, significa que ele está na posição "correta" (Depois do pivô)
		for(;A[j] > pivot && j > inicio; j--);			
		
		/*
		Caso I seja menor ou igual a J ocorre a troca de posições, já que para chegar nesta parte do código, os elementos não
		estavam na posição "correta"
		*/
		if(i <= j){
			aux = A[i];
			A[i] = A[j];
			A[j] = aux;
			j--;
			i++;	
		}			
	}
	
	//Com j < i e maior que o inicio do array, chama novamente a função para dividir e conquistar a metade da esquerda
	if(j > inicio)
		qSort(A, inicio, j);
	//Com j < i e i < que o limite do array, chama novamente a função para dividir e conquistar a metade da direita
	if(i < fim)
		qSort(A, i, fim);
}
