#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

void main(){

	 setlocale(LC_ALL,"");
	 int A[7] = {1,3,5,6,2,4,8};
	 int pos1, pos2, pos3;
	 TresElem(A, 7, 13, &pos1, &pos2, &pos3);
	 
	 printf("\nPosição 1 >> %d", pos1);
	 printf("\nPosição 2 >> %d", pos2);
	 printf("\nPosição 3 >> %d", pos3);
	 
	 printf("\nSoma >> %d", 13);
}

void TresElem(const int *A, int N, int S, int *Pos1, int *Pos2, int *Pos3){	
	for(int i = 0; i < N; i++){
		for(int j = i +1; j < N; j++){
			for(int k = j + 1; k < N; k++){
				if((A[i] + A[j] + A[k]) == S){
					*Pos1 = i;
					*Pos2 = j;
					*Pos3 = k;
				}
			}
		}
	}
}
