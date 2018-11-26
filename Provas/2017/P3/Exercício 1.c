#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL,"");
	order_file("Numeros.bin");
	system("pause");
	return 0;
}

void order_file(const char *file){	
	FILE *ptr_file;	
	
	//Abre um arquivo já existente com permissão de leitura e escrita
	ptr_file=fopen(file,"rb+");
	
	//Caso o ponteiro seja null, emite um erro
	if (!ptr_file)
	{
		printf("\nErro ao abrir arquivo!\n");
		return 1;
	}
	
	int count = 0;
	int aux = 0;
	
	//Conta o número de linhas do arquivo	
	while(!feof(ptr_file)){
		fread(&aux, sizeof(int), 1, ptr_file);		
		count++;
	}
	
	//Volta para o início
	rewind(ptr_file);		
	
	int a, b;
	int pos = 0;	
	
	for(int i = 1; i < count-1; i++){
		
		//Inicializa a posição (Inútil?)
		pos = 0;		
		for(int j = 0; j < count - 1 - i; j++){	
			//Armazena a posição atual do arquivo para fazer substituições em caso de a > b
			pos = ftell(ptr_file);			
			
			//Le a linha na posição pos e armazena em a;			
			fread(&a,sizeof(int),1,ptr_file);		
			
			//Le a linha na posição pos+1 e armazena em b;
			fread(&b,sizeof(int),1,ptr_file);			
			
						
			if(a > b){											
				//se a > b, volta o arquivo para a linha pos (onde esta localizado o A)
				fseek(ptr_file, pos, SEEK_SET);			
				
				//Escreve B por cima de A
				fwrite(&b, sizeof(int), 1, ptr_file);
				
				//Armazena a posição de B antes de escrever A por cima;
				pos = ftell(ptr_file);
				
				//Escreve A no lugar de B;
				fwrite(&a, sizeof(int), 1, ptr_file);				
				
				//Volta uma posição para comparar com pos+2
				fseek(ptr_file, pos, SEEK_SET);
			}
		}
		
		//Volta para o início do arquivo
		rewind(ptr_file);
	}	
	
	for (int i = 0; i < count-1; i++)
	{
		fread(&aux,sizeof(int),1,ptr_file);		
		printf("%d\n",aux);
	}				
	
	fclose(ptr_file);	
	
	return;		
}

