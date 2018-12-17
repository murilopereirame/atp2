#include <stdio.h>
#include <stdlib.h>
#define RC 4

typedef enum boleano {true = 1, false = 0} bool;
void imprimirMatriz(int **A, int N);
void ordenaMatriz(int **A, int N);
void qSort(int *A, int inicio, int fim);
void ordenaMatrizLinha(int **A, int N);
void copiaMatriz(int **A, int **B, int N);

void main(){    

    printf("A matriz antes da ordenacao:\n\n");

    //Inicia uma matriz genérica
    int A[RC][RC] = {
        {200,8,5,22},
        {150,10,9,2},
        {-1,0,54,23},
        {99,12,18,52}
    };

    //Copia da matriz generica
    int B[RC][RC] = {0};
    copiaMatriz(A,B,RC);

    //Imprime a matriz
    imprimirMatriz(A, RC);

    printf("\n\n");

    printf("Matriz apos ordenacao completa:\n\n");

    //Ordena e imprime a matriz completa
    ordenaMatriz(A, RC);
    imprimirMatriz(A, RC);

    printf("\n\n");

    printf("Matriz apos ordenacao por linha:\n\n");
    
    //Ordena matriz por linha e imprime
    ordenaMatrizLinha(B, RC);
    imprimirMatriz(B, RC);

    printf("\n\n");
    system("pause");
    return 0;
}

void copiaMatriz(int **A, int **B, int N){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            B[i*N + j] = A[i*N + j];
}

void ordenaMatriz(int **A, int N){
    //Inicia um vetor 1D e uma variavel auxiliar
    int aAux[N * N], aux = 0;

    //Copia a matriz pro vetor 1D
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            aAux[aux] = A[i*N + j];
            aux++;
        }
    }

    //Ordena o vetor 1D com QS
    qSort(aAux, 0, ((N*N) - 1));

    //Volta o array para a matriz
    aux = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            A[i*N + j] = aAux[aux];
            aux++;
        }
}

void ordenaMatrizLinha(int **A, int N){
    //Vetor 1D para copiar a linha
    int aAux[N];    

    for(int i = 0; i < N; i++){        
        //Copia a linha pro vetor
        for(int j = 0; j < N; j++)                    
            aAux[j] = A[i*N + j];
        //Ordena o vetor com QS                            
        qSort(aAux, 0, N-1);
        //Volta o vetor pra matriz
        for(int j = 0; j < N; j++)
            A[i*N + j] = aAux[j];                     
    }
}

void imprimirMatriz(int **A, int N){
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