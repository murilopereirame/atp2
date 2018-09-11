#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

void main(){

	 setlocale(LC_ALL,"");
	 int g1 = 0, g2 = 0, g3 = 0;	 	 
	 printf("\nInsira o grau do polinômio 1: ");
	 scanf("%d", &g1);
	 printf("\nInsira o grau do polinômio 2: ");
	 scanf("%d", &g2);
	 
	 printf("\n\n");
	 
	 g3 = g1 + g2;
	 
	 int p3[g3], p1[g1], p2[g2];	 	 	 
	 
	 for(int i = 0; i <= g1; i++){
	 	p1[i] = 0;
	 	printf("Insira o coeficiente %d do polinômio 1: ", i);
	 	scanf("%d", &p1[i]);
	 	printf("\n");
	 }
	 printf("\n\n");
	 for(int i = 0; i <= g2; i++){
	 	p2[i] = 0;
	 	printf("Insira o coeficiente %d do polinômio 1: ", i);
	 	scanf("%d", &p2[i]);
	 	printf("\n");
	 }
	 for(int i = 0; i <= g3; i++){
	 	p3[i] = 0;
	 }
	 
	 prodPol(p1, p2, p3, g1, g2);
	 
	 for(int i=0; i <= g3; i++)	 {
	 	printf("%d", p3[i]);
	 	printf("\n");
	 }
}

void prodPol(int *p1, int *p2, int *p3, int g1, int g2){

	int a = 0, b = 0;
	
	if(g1 > g2){
		a = g1;
		b = g2;
	}
	else{
		a = g2;
		b = g1;
	}
	
	for(int i = 0; i <= a; i++){
		for(int j = 0; j <= b; j++){
			if(g1 > g2)
				p3[j+i] = p3[j+i] + (p1[i] * p2[j]);
			else
				p3[j+i] = p3[j+i] + (p1[j] * p2[i]);			
		}
	}
}
