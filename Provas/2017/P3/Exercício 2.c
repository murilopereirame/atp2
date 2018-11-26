#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

typedef enum boleano{false=0,true=1}Boleano;

Boleano Busca_Binaria_Arquivo(FILE *fp, int chave);

void main(){

	setlocale(LC_ALL,"");
	
	//Abre o arquivo bin�rio
	FILE *fp = fopen("Numeros.bin", "rb+");
	
	int num = 0;
	//Pergunta pelo n�mero a ser procurado 
	printf("Qual n�mero deseja procurar: ");	 
	scanf("%d", &num);
	printf("\n");	 
	if(Busca_Binaria_Arquivo(fp, num))
		printf("O n�mero esta presente no conjunto!\n"); //Encontrou o n�mero
	else
		printf("O n�mero n�o esta presente no conjunto!\n"); //N�o encontrou o n�mero
		
	 system("pause");
}

Boleano Busca_Binaria_Arquivo(FILE *fp, int chave){
	//Inicializa as vari�veis
	int m = 0, e = 0, d = 0, count = 0, aux = 0;
	
	//Arquivo nulo, retorna 0
	if(fp == NULL){
		printf("Erro ao abrir arquivo!!\n");
		return 0;
	}
	
	//Conta o n�mero de linhas
	while(!feof(fp)){
		fread(&d, sizeof(int),1,fp);				
		count++;
	}
	
	//Volta pro come�o do arquivo
	rewind(fp); 	
	
	d = (count - 2) * 4;

	//Inicia a busca bin�ria
	while(e <= d){					
		rewind(fp);
		
		//Padr�o de 4 bytes pois s�o arquivos bin�rios de int
		//Encontra o meio
		m= (((e/4) + (d/4))/2) * 4;
		
		//Verifica se n�o est� no final do arquivo
		if ( !feof(fp) ){
			//Define a posi��o no meio do arquivo
			fseek(fp, m, SEEK_SET);
			
			//Associa o valor na posi��o M para a vari�vel auxiliar
			fread(&aux,sizeof(int),1,fp);			
			
			//Se aux == chave retorna que o n�mero pertence ao conjunto no arquivo
			if(aux == chave)
				return true;						
				
			//Se aux � menor do que a chave, sabemos que a chave, se estiver presente, esta a direita do centro
			if(aux < chave)
				e = m + 4;			
			else						
				d = m - 4;		//Se aux � maior do que a chave, sabemos que a chave, se estiver presente, esta a esquerda do centro
			
			//Sempre padr�es de 4 pois estamos utilizando 4 bytes = 1 int
		}					
	}
	return false;
}
