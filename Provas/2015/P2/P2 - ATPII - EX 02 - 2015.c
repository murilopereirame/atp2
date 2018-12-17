#include <stdlib.h>
#include <stdio.h>
#define MAX 4

int main(){
    int Ma=0, Me=0, colMa=-1, colMe=-1, linMa=-1, linMe=-1;

    //Inicia matriz genérica
    int A[MAX][MAX] = {
        {2,3,8,7},
        {8,6,77,52},
        {520,512,256,10},
        {57,0,-2,56}
    };

    printf("Dada a matriz:\n\n");
    //Imprime a matriz genérica
    imprimeMatriz(A, MAX);
    //Encontra os valores
    memMatriz(A, MAX, &Ma, &Me, &colMa, &colMe, &linMa, &linMe);

    printf("\n\nO menor valor eh: %d\nColuna: %d\nLinha: %d\n\nO maior valor eh: %d\nColuna: %d\nLinha: %d", Me, colMe, linMe, Ma, colMa, linMa);

    return 0;
}

void imprimeMatriz(int **A, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            printf("\t%d    ", A[i*N + j]);
        printf("\n");
    }
}

void memMatriz(int **A, int N, int *Ma, int *Me, int *colMa, int *colMe, int *linMa, int *linMe){
    int mai=0, men=0, colB = -1, linB = -1, colS = -1, linS = -1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            //Compara o  valor na posição IxJ com o maior valor já encontrado
            //PS: CASTA INT, COLOCA (INT) SE NÃO O COMPILADOR INTERPRETA ERRADO!!
            if((int)A[i*N + j] > (int)*Ma){                           
                *Ma = A[i*N + j];
                *colMa = j;
                *linMa = i;                
            }      
            //Compara o  valor na posição IxJ com o menor valor já encontrado
            //PS: CASTA INT, COLOCA (INT) SE NÃO O COMPILADOR INTERPRETA ERRADO!!          
            else if((int)A[i*N + j] < (int)*Me)
            {
                *Me = A[i*N + j];
                *colMe = j;
                *linMe = i;
            }
        }
    }
}
