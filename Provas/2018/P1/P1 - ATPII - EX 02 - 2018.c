#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

void main(){

	 setlocale(LC_ALL,"");
	 int qi = 0;
	 int Pb[5] = {1,2,3,4,5};
	 int Pa[6] = {1,2,3,4,5,6};
	 int Pc[11] = {0};
	 
	 Inter(Pa, Pb, 6, 5, Pc, &qi);
	 
	 for(int i = 0; i < 11; i++)
	 	printf("%d ", Pc[i]);
	
	printf("\nQuantidade de elementos na intersecção: %d", qi);
	 
}

void Inter (const int *Pa, const int *Pb, int M, int N, int *Inter, int *Qi){
	int j = 0;
	if(M > N){
		for(int i = 0; i < M; i++){
			for(int k = 0; k < N; k++){
				if(Pa[i] == Pb[k]){
					Inter[j] =  Pa[i];						
					j++;
					*Qi += 1;
				}					
			}
		}	
	}		
	else{
		for(int i = 0; i < N; i++){
			for(int k = 0; k < M; k++){
				if(Pb[i] == Pa[k]){
					Inter[j] =  Pa[i];	
					j++;
					*Qi += 1;
				}					
			}
		}	
	}		
}
