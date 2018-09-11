#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void main(){	

	setlocale(LC_ALL,"");
	int p[9];
	p[0] = 5;
	p[1] = 10;
	p[2] = 3;
	p[3] = 2;
	p[4] = 4;
	p[5] = 7;
	p[6] = 9;
	p[7] = 8;
	p[8] = 9;
	
	printf("O comprimento do maior segmento crescente é %d\n", dComp(p, 10));
}

int dComp(int *p, int lenght){
	int aux = 1, m = 1;
	
	for(int i = 0; i < lenght; i++){
		if(aux > m)
			m = aux;
		if(p[i] > p[i - 1])
			aux++;
		else
			aux = 1;			
	}
	return m;
}
