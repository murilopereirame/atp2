#include <stdio.h>
#include <stdlib.h>
#define RC 4

typedef enum boleano {true = 1, false = 0} bool;
bool matrizMagica(int **A, int N);

void main(){

    printf("A matriz:\n\n");

    //Inicia uma matriz genérica
    int A[RC][RC] = {
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1}
    };

    //Imprime a matriz
    for(int i = 0; i < RC; i++){
        for(int j = 0; j < RC; j++)
            printf("\t%d    ", A[i][j]);
        printf("\n");
    }

    printf("\n");

    //Verifica se é uma matriz mágica
    if(matrizMagica(A, RC))
        printf("E uma matriz magica!\n");
    else
        printf("Nao e uma matriz magica!!\n");

    system("pause");
    return 0;
}

bool matrizMagica(int **A, int N){

    //Inicia a variavel que irá armazenar a soma, uma auxiliar pra manter a soma e uma para checar se não é a primeira vez que a soma
    //sera conferida
    int soma = 0, aux = 0, r1 = 1;

    //Checar a soma das linhas
    for(int i = 0; i < N; i++){
        soma = 0;
        for(int j = 0; j < N; j++){
            soma += A[i*N + j];
        }

        //Caso a soma não seja igual a soma armazenada, retorna falso (Existe uma verificação de primeiro loop para evitar comparar soma == 0)
        if(!(aux == soma) && !r1)
            return false;           
        aux = soma;
        r1 = 0;
    }

    //Checar a soma das colunas
    for(int j = 0; j < N; j++){
        soma = 0;
        for(int i = 0; i < N; i++){
            soma += A[i*N + j];
        }
        if(!(aux == soma))                 
            return false;        
        aux = soma;
    }

    //Checar a soma da diagonal principal
    soma = 0;
    for(int i = (N - 1), j = 0; i >= 0 && j < N; i--, j++){        
        soma += A[i*N + j];          
    }
    if(!(aux == soma)){            
        return false;
    }            
    aux = soma;  

    //Checar a soma da diagonal secundaria
    soma = 0;
    for(int i = (N - 1), j = (N - 1); i >= 0 && j >= 0; i--, j--){        
        soma += A[i*N + j];         
    }
    if(!(aux == soma)){        
        return false;
    }            
    aux = soma;        

    //Se passou nas verificações anteriores, bingo
    return true;
}