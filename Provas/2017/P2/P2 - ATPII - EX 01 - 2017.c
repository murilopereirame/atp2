
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define RC 4

typedef enum boleano {false=0, true=1} bool;
bool vMatrizPermutacao(int N,int **A);

void main(){
	setlocale(LC_ALL,"");

    printf("\tA matriz:\n\n");
    
    //Inicializa uma matriz generica
    int A[RC][RC] = {
		{1,0,0,0},
		{0,1,0,0},
		{0,0,0,1},
		{0,0,1,0}
	};

    //Imprime a matriz
    for(int i = 0; i < RC; i++){
        for(int j = 0; j < RC; j++)
            printf("\t%d  ", A[i][j]);
        printf("\n");
    }

    printf("\n");

    //Checa se é uma matriz de permutação
    if(vMatrizPermutacao(RC, A))
        printf("\tE matriz de permutacao!\n");
    else
        printf("\tNao e matriz de permutacao!!!\n");
    
    system("pause");
    return 0;
}

bool vMatrizPermutacao(int N, int **A){    
    
    //Váriavel auxiliar para contar quantos
    //1 tem em cada linha/coluna
    int lOne = 0;

    //Conta quantos 1 tem em cada linha
    for(int i = 0; i < N; i++){    		
        
        //Reinicia a variavel auxiliar
		lOne = 0;          
        for(int j = 0; j < N; j++){       			         	                        
            //Caso o o valor na posição IxJ seja 1, acrescenta 1 na contagem
            if(A[i*N + j] == 1)
            	lOne++;										       	            	
        }
        //Caso haja menos de 1 ou mais de 1 valores != de 0, a matriz não é de permutação
        //Retorna falso
       	if(lOne != 1)        	
        	return false;			
    }    
    
    //Conta quantos 1 tem em cada coluna
    for(int j = 0; j < N; j++){    

        //Reinicia a variável auxiliar
		lOne = 0;    
        for(int i = 0; i < N; i++){   
            //Caso o valor na posição JxI seja 1, acrescenta 1 na contagem     	
            if(A[i*N + j] == 1)
            	lOne++;					                
        }
        //Caso haja menos/mais de 1 valores != de 0, a matriz não é de permutação
        //Retorna falso
        if(lOne != 1)        	
        	return false;			
    }

    //Retorna verdadeiro caso tenha passado por todos os "fors" sem interrupção
    return true;
} 
