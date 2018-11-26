#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

typedef enum boleano{false=0,true=1}Boleano;

Boleano Busca_Binaria_Arquivo(FILE *fp, int chave);

void main(){

	setlocale(LC_ALL,"");
	
	//Abre o arquivo binário
	FILE *fp = fopen("Numeros.bin", "rb+");
	
	int num = 0;
	//Pergunta pelo número a ser procurado 
	printf("Qual número deseja procurar: ");	 
	scanf("%d", &num);
	printf("\n");	 
	if(Busca_Binaria_Arquivo(fp, num))
		printf("O número esta presente no conjunto!\n"); //Encontrou o número
	else
		printf("O número não esta presente no conjunto!\n"); //Não encontrou o número
		
	 system("pause");
}

Boleano Busca_Binaria_Arquivo(FILE *fp, int chave){
	//Inicializa as variáveis
	int m = 0, e = 0, d = 0, count = 0, aux = 0;
	
	//Arquivo nulo, retorna 0
	if(fp == NULL){
		printf("Erro ao abrir arquivo!!\n");
		return 0;
	}
	
	//Conta o número de linhas
	while(!feof(fp)){
		fread(&d, sizeof(int),1,fp);				
		count++;
	}
	
	//Volta pro começo do arquivo
	rewind(fp); 	
	
	d = (count - 2) * 4;

	//Inicia a busca binária
	while(e <= d){					
		rewind(fp);
		
		//Padrão de 4 bytes pois são arquivos binários de int
		//Encontra o meio
		m= (((e/4) + (d/4))/2) * 4;
		
		//Verifica se não está no final do arquivo
		if ( !feof(fp) ){
			//Define a posição no meio do arquivo
			fseek(fp, m, SEEK_SET);
			
			//Associa o valor na posição M para a variável auxiliar
			fread(&aux,sizeof(int),1,fp);			
			
			//Se aux == chave retorna que o número pertence ao conjunto no arquivo
			if(aux == chave)
				return true;						
				
			//Se aux é menor do que a chave, sabemos que a chave, se estiver presente, esta a direita do centro
			if(aux < chave)
				e = m + 4;			
			else						
				d = m - 4;		//Se aux é maior do que a chave, sabemos que a chave, se estiver presente, esta a esquerda do centro
			
			//Sempre padrões de 4 pois estamos utilizando 4 bytes = 1 int
		}					
	}
	return false;
}
