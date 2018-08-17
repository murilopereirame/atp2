#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

short continua(void);

void main(){
    double coefs1[20], coefs2[20], coefs3[20], coefsr[40];
    short p1 = 0, p2 = 0, p3 = 0;
    int operation = 0, grau = 0, i = 0;
    setlocale(LC_ALL,"");

    do {
		operation = menu();
		system("cls");
		system("Pause");

	    switch(operation)  {
	    //INTRODUZIR 1º POLINÔMIO
		case 1:
			printf("Introduzir o primeiro polinômio.\n\n");
			printf("Qual o grau do polinômio?\n");
			scanf("%d", &grau);
			if(grau > 0 && grau < 21){
                for(; i < grau; i++){
                    printf("\nIntroduza o coeficiente A%d :", i);
                    scanf("%d", &coefs1[i]);
                }
                p1 = 1;
                grau = 0;
                i = 0;
			}
			else
                printf("O grau n do polinômio deve se 0 < n < 21");

	        printf("\n");
	        system("Pause");
	        break;
	    //INTRODUZIR 2º POLINÔMIO
		case 2:
			printf("Introduzir o segundo polinômio.\n\n");
			printf("Qual o grau do polinômio?\n");
			scanf("%d", &grau);

			if(grau > 0 && grau < 21){
                for(; i < grau; i++){
                    printf("\nIntroduza o coeficiente A%d :", i);
                    scanf("%d", &coefs2[i]);
                }
                p2 = 1;
                grau = 0;
                i = 0;
			}
			else
                printf("O grau n do polinômio deve se 0 < n < 21");

	        printf("\n");
	        system("Pause");
	        break;
	    //INTRODUZIR 3º POLINÔMIO
		case 3:
			printf("Introduzir o terceiro polinômio.\n\n");
			printf("Qual o grau do polinômio?\n");
			scanf("%d", &grau);

			if(grau > 0 && grau < 21){
                for(; i < grau; i++){
                    printf("\nIntroduza o coeficiente A%d :", i);
                    scanf("%d", &coefs3[i]);
                }
                p2 = 1;
                grau = 0;
                i = 0;
            }
			else
                printf("O grau n do polinômio deve se 0 < n < 21");

	        printf("\n");
	        system("Pause");
	        break;
		//OPÇÃO PRIMOS DE MERSENE
		case 4:
			if(coefs1[4] == 0)
                printf("NULL!\n\n\n\n");


			printf("ENCONTRAR TODOS OS PRIMOS DE MERSENE NO INTERVALO [1, 30].\n\n");
			printf("\n");
			system("pause");
			break;
		//OPÇÃO DE NÚMEROS FELIZES
		case 5:
			printf("ENCONTRAR TODOS OS NÚMEROS FELIZES NO INTERVALO [4,1000].\n\n");
			printf("\n");
			system("pause");
			break;
		//OPÇÃO DE APROXIMAÇÃO FATORIAL
		case 6:
			printf("CALCULAR A APROXIMAÇÃO DO FATORIAL DE N.\n\n");
			printf("\n");
			system("pause");
			break;
        case 7:
			printf("CALCULAR A APROXIMAÇÃO DO FATORIAL DE N.\n\n");
			printf("\n");
			system("pause");
			break;
		//OPÇÃO SAIR
		case 0:
			printf("\nDesenvolvido por: Murilo Rocha Pereira & Gustavo Marciel Pinheiro Oliveira\nRA: 181250934 & 181253828\nCurso: Ciência da Computação\nSemestre: 1º\n");
			return 0;
		//OPÇÃO INVALIDA
		default:
			printf("Insira uma opção válida =].");
			printf("\n");
			system("pause");
			break;
		}

  } while ( continua() );

  printf("\nDesenvolvido por: Murilo Rocha Pereira\nRA: 181250934\nCurso: Ciência da Computação\nSemestre: 2º\n");
  system("pause");
  return 0;

}

//SHORT PARA VERIFICAR SE O USUÁRIO DESEJA REALIZAR UMA NOVA OPERAÇÃO
short continua(void) {
	char ch;

    do{
		system("cls");
       	printf("\n\nDeseja realizar outro operação? [S,N] : ");
		ch = getchar();
		ch = toupper(ch);
  	}
  	while( (ch != 'S') && (ch != 'N') );

  	if(ch == 'S')
	  return 1;
  	else
	  return 0;
}

//FUNÇÃO PARA CONSTRUIR O MENU E RETORNAR A OPÇÃO ESCOLHIDA
int menu(void) {
  int opcao;

  system("CLS");
  printf("\n\t=====Trabalho prático de programação - 01=====\n\n");
  printf("1. Introduzir polinômio 01 \n");
  printf("2. Introduzir polinômio 02 \n");
  printf("3. Introduzir polinômio 04 \n");
  printf("4. Somar polinômios\n");
  printf("5. Subtrair polinômios\n");
  printf("6. Multiplicar polinômios\n");
  printf("7. Dividir polinômios\n");
  printf("0. Sair");


  printf("\n\nEscolha uma opção dentre as listadas: ");
  scanf("%d", &opcao);

  return(opcao);
}

void pMSoma(int *p1, int *p2, int *p3, int *p4){
    int pr[40];
    int quant = 0, pc1=0, pc2=0, pc3=0, pc4=0, i = 0;
    printf("Quantos polinômios você deseja somar? (Máximo 4 & Mínimo 2): \n");
    scanf("%d", &quant);

    if(quant > 1 && quant <= 4){
        switch(quant)  {
        //INTRODUZIR 1º POLINÔMIO
            case 2:
                printf("Quais polinômios você deseja somar?\n");
                printf("1. Polinômio 1\n");
                printf("2. Polinômio 2\n");
                printf("3. Polinômio 3\n");
                printf("4. Polinômio resultante\n");
                scanf("%d %d", &pc1, &pc2);

                if((pc1 == 1 || pc2 == 1) && (pc1 == 1 || pc2 == 1))
                    for(; i < 20; i++)
                        p4[i] = p1[i] + p2[i];
                if((pc1 == 1 || pc2 == 1) && (pc1 == 2 || pc2 == 2))
                        p4[i] = p1[i] + p2[i];
                if((pc1 == 1 || pc2 == 1) && (pc1 == 3 || pc2 == 3))
                        p4[i] = p1[i] + p2[i];
                if((pc1 == 1 || pc2 == 1) && (pc1 == 4 || pc2 == 4))
                        p4[i] = p1[i] + p2[i];
                if((pc1 == 2 || pc2 == 2) && (pc1 == 2 || pc2 == 2))
                        p4[i] = p1[i] + p2[i];
                if((pc1 == 2 || pc2 == 2) && (pc1 == 3 || pc2 == 3))
                        p4[i] = p1[i] + p2[i];
                if((pc1 == 2 || pc2 == 2) && (pc1 == 4 || pc2 == 4))
                        p4[i] = p1[i] + p2[i];
                if((pc1 == 3 || pc2 == 3) && (pc1 == 3 || pc2 == 3))
                        p4[i] = p1[i] + p2[i];
                if((pc1 == 3 || pc2 == 3) && (pc1 == 4 || pc2 == 4))
                        p4[i] = p1[i] + p2[i];
                if((pc1 == 4 || pc2 == 4) && (pc1 == 4 || pc2 == 4))
                        p4[i] = p1[i] + p2[i];

                break;
            case 3:
                break;
            case 4:
                break;

        }
    }

}

