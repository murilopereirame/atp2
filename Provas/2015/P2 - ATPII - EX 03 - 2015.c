#include <stdlib.h>
#include <stdio.h>
#define MAX 4

int main(){

    int minmax;

    //Inicia uma matriz genérica
    int A[MAX][MAX] = {
        {8,3,25,0},
        {7,28,256,-5},
        {75,253,-56,12},
        {89,-9,253,10}
    };

    printf("Dada a matriz: \n\n");

    //Imprime a matriz genérica
    imprimeMatriz(A, MAX);

    //Acha o MINMAX
    minMaxMatriz(A, MAX, &minmax);

    printf("\n\nO MINMAX eh: %d", minmax);

    return 0;
}

void imprimeMatriz(int **A, int N)
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("\t%d    ", A[i*N + j]);
        }
        printf("\n");
    }
}

void minMaxMatriz(int **A, int N, int *minMax){
    int mLinha = 0, mMatriz, first = 1;

    for(int i = 0; i < N; i++){
        first = 1;
        for(int j = 0; j < N; j++){
            if(first == 1){
                mLinha = A[i*N + j];
                mMatriz = mLinha;                
                first = 0;
            }                            
            if(mLinha < (int)*(A+i*N+j)){
                mLinha = (int)A[i*N + j];                
            }               
            if(j == (N - 1))
                if(mLinha < mMatriz)
                    mMatriz = mLinha;
        }                   
    }

    *minMax = mMatriz;
}