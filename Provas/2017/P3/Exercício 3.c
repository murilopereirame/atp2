#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

void Conta_Char_Alfa(char *Str1, int *Arranjo);

void main(){

	 setlocale(LC_ALL,"");
	 
	 //Inicia nosso arranjo
	 int arranjo[26] = {0};
	 
	 //Chama a fun��o
	 Conta_Char_Alfa("Numeros.text", arranjo);
	 
	 //Imprime o arranjo
	 for(int i = 0; i < 26; i++){
	 	//Convete a integer pra char
	 	char charex = (char)(i + 65);
	 	printf("%c: %d\n", charex, arranjo[i]);
	 }
	 
	 system("pause");
}

void Conta_Char_Alfa(char *Str1, int *Arranjo){
	
	//Faz o ponteiro pro arquivo
	FILE *fp = fopen(Str1, "r");
	
	//Verifica se o arquivo n�o � nulo
	if(fp == NULL){	
		printf("N�o foi poss�vel abrir o arquivo!\n");
		return;
	}
	
	//Percorre o arquivo
	char ch;
	while((ch = getc(fp)) != EOF){
		//Verifica se n�o ta pulando linha
		if(ch != '\n'){			
			//Coloca tudo em caixa alta
			char aux = toupper(ch);
			
			//Pega o valor do char
			int charValor = (int)aux;
			
			//Verifica se � uma caractere do alfabeto
			if(charValor > 64 && charValor < 91){			
			
				//Obtem o valor atual na posi��o N - 65 (65 pq � o in�cio do alfabeto)
				//Ent�o A = 65, ta na posi��o 65 - 65 = 0
				int qnt = Arranjo[charValor - 65];
				
				//Adiciona um a quantidade
				qnt++;
				
				//Atualiza a quantidade no arranjo
				Arranjo[charValor - 65] = qnt;
			}
		}
	}
	
	return;
}

