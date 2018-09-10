#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<time.h> 

#define MAX 40
void qSort(int a[], int start, int end);
short continua(void);
short isNull(int *array);
int menu(void);
void main(){
	int array[MAX] = {0}, operation;
	char ch;
	setlocale(LC_ALL,"");	
	srand(time(0)); 
    do {
    	operation = menu();
		system("cls");
		system("Pause");

	    switch(operation)  {
	    	
	    //Introduzir array manualmente
		case 1:
			printf("Inserir array.\n\n");
			for(int i = 0; i < MAX; i++){
				printf("Insira o elemento %d: ", i);
				scanf("%d", &array[i]);
				printf("\n");
			}
			break;
		
		//Gerar array aleat�rio
		case 2:
			printf("Gerar array aleat�rio.\n\n");
			for(int i = 0; i < MAX; i++){
				array[i] = rand();
			}
			do{
				system("cls");
       			printf("\n\nDeseja imprimir o array? [S,N] : ");
				ch = getchar();
				ch = toupper(ch);
  			}
  			while( (ch != 'S') && (ch != 'N') );
			if(ch == 'S')
				for(int j = 0; j < MAX; j++)
					printf("%d ", array[j]);
			printf("\n");
			system("pause");
			break;
		
		//Executar fun��o QuickSort
		case 3:
			printf("Ordenar array por QuickSort.\n\n");
			if(isNull(array)){							
				qSort(array, 0, MAX - 1);
				do{
					system("cls");
       				printf("\n\nDeseja imprimir o array? [S,N] : ");
					ch = getchar();
					ch = toupper(ch);
  				}
  				while( (ch != 'S') && (ch != 'N') );

				if(ch == 'S')
					for(int j = 0; j < MAX; j++)
						printf("%d ", array[j]);
			}
			else
				printf("O array est� nulo!\n");    		
			printf("\n");
			system("pause");
			break;
		//OP��O SAIR
		case 0:
			printf("\nDesenvolvido por: Murilo Rocha Pereira\nRA: 181250934\nCurso: Ci�ncia da Computa��o\nSemestre: 2�\n");
			return 0;
		default:
			printf("Insira uma op��o v�lida =].");
			printf("\n");
			system("pause");
			break;
		}

  	} while ( continua() );  					
	printf("\nDesenvolvido por: Murilo Rocha Pereira\nRA: 181250934\nCurso: Ci�ncia da Computa��o\nSemestre: 2�\n");
	system("pause");
}

//SHORT PARA VERIFICAR SE O USU�RIO DESEJA REALIZAR UMA NOVA OPERA��O
short continua(void) {
	char ch;

    do{
		system("cls");
       	printf("\n\nDeseja realizar outro opera��o? [S,N] : ");
		ch = getchar();
		ch = toupper(ch);
  	}
  	while( (ch != 'S') && (ch != 'N') );

  	if(ch == 'S')
	  return 1;
  	else
	  return 0;
}

//FUN��O PARA CONSTRUIR O MENU E RETORNAR A OP��O ESCOLHIDA
int menu(void) {
  int opcao;

  system("CLS");
  printf("\n\t=====Trabalho pr�tico de programa��o - 02 || QuickSort || ATP II=====\n\n");
  printf("1. Introduzir array (Tamanho: 40)\n"); //OK
  printf("2. Gerar array random\n"); //OK
  printf("3. Ordenar array\n"); //OK  
  printf("0. Sair");


  printf("\n\nEscolha uma op��o dentre as listadas: ");
  scanf("%d", &opcao);

  return(opcao);
}

//Fun��o QuickSort
void qSort(int a[], int start, int end){
	int i = start, j = end;	
	int pivot = a[(start + end)/2];	
	int aux = 0;
	
	while(i <= j){
		for(;a[i] < pivot && i < end; i++);			
		for(;a[j] > pivot && j > start; j--);			
		if(i <= j){
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			j--;
			i++;	
		}			
	}
	
	if(j > start)
		qSort(a, start, j);
	if(i < end)
		qSort(a, i, end);
}

//Verificar se array n�o esta nulo
short isNull(int *array){
	for(int i =0; i < MAX; i++)
		if(array[i] != 0)
			return 1;
	return 0;
}
