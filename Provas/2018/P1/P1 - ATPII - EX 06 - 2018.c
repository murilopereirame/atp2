#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

void main(){

	 setlocale(LC_ALL,"");
	 int A[6] = {10,20,30,40,50,60};
	 
	 RotacionarArrayKVezes(A, 6, 5);
	 
	 for(int i = 0; i < 6; i++)
	 	printf("%d ", A[i]);
}

void RotacionarArrayKVezes(int *A, int N, int K){
	for(int i = 0; i < K; i++){
		int pos = N-1;		
		int last = A[pos];
		for(;  pos > 0; pos--){
			A[pos] = A[pos - 1];
		}		
		A[pos] = last;	
	}	
}
