#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

void main(){

	 setlocale(LC_ALL,"");
	 int A[6] = {10,20,30,40,50,60};
	 ReverterDadosIntervalo(A, 6, 1, 3);
	 
	 for(int i = 0; i < 6; i++)
	 	printf("%d ", A[i]);
}

void ReverterDadosIntervalo(int *A, int N, int Inf, int Sup){	
	for(; Sup >= Inf; Inf++){
		int aux = 0;
		aux = A[Inf];				
		A[Inf] = A[Sup];
		A[Sup] = aux;
		Sup--;
	}
}
