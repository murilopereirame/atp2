#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

short continua(void);
void pMChange(float *p, float *pr, int lenght);
short checkNull(float *p1, float *p2, float *p3);
void pMSoma(float *p1, float *p2, float *p3, float *p4);
void pMSub(float *p1, float *p2, float *p3, float *p4);
void pMMulti(float *p1, float *p2, float *p3, float *p4, float conK);
void pMInsert(float *p1, float *p2, float *p3);
void pMSolve(float *p1, float *p2, float *p3, float *p4);
void pMPrint(float *p1, float *p2, float *p3, float *p4);
void pMDerive(float *p1, float *p2, float *p3, float *p4);
void pMIntegrate(float *p1, float *p2, float *p3, float *p4);
void ppMMulti(float *p1, float *p2, float *p3, float *p4);
short pMExc(float *p, float *p2, int l1, int l2);

void main(){
    float coefs1[20] = {0}, coefs2[20] = {0}, coefs3[20] = {0}, coefsr[40] = {0};    
    int operation = 0, grau = 0, i = 0, opt = 0;
    float k = 0, x=0;
    setlocale(LC_ALL,"");	
    do {
		operation = menu();
		system("cls");
		system("Pause");

	    switch(operation)  {
	    //INTRODUZIR POLIN�MIOS
		case 1:
			printf("Introduzir o primeiro polin�mio.\n\n");
			pMInsert(coefs1, coefs2, coefs3);
	        printf("\n");
	        system("Pause");
	        break;
	    //SOMAR POLIN�MIOS
		case 2:			                
			printf("Somar polin�mios.\n\n");
			if(checkNull(coefs1, coefs2, coefs3))
				pMSoma(coefs1, coefs2, coefs3, coefsr);
	        printf("\n");
	        system("Pause");
	        break;
	    //SUBTRAIR POLIN�MIOS
		case 3:			
			printf("Subtrair polin�mios.\n\n");
			if(checkNull(coefs1, coefs2, coefs3))
				pMSub(coefs1, coefs2, coefs3, coefsr);
	        printf("\n");
	        system("Pause");
	        break;
		//MULTIPLICAR POLIN�MIOS
		case 4:			                
			printf("Multiplicar polin�mio por uma constante K pertencente aos Reais.\n\n");
			printf("Insira a constante K: ");
			scanf("%f", &k);
			if(checkNull(coefs1, coefs2, coefs3))
				pMMulti(coefs1, coefs2, coefs3, coefsr, k);
			printf("\n");
			system("pause");			
			break;		
		//INTEGRAR POLIN�MIOS
		case 5:
			printf("Integrar polin�mios.\n\n");
			if(checkNull(coefs1, coefs2, coefs3))
				pMIntegrate(coefs1, coefs2, coefs3, coefsr);
			printf("\n");
			system("pause");
			break;		
		//DERIVAR POLIN�MIOS
		case 6:
			printf("Derivar polin�mios.\n\n");
			if(checkNull(coefs1, coefs2, coefs3)){
				pMDerive(coefs1, coefs2, coefs3, coefsr);
			}			
			printf("\n");
			system("pause");
			break;
		//RESOLVER POLIN�MIOS
        case 7:
			printf("Resolver polin�mios.\n\n");						
			if(checkNull(coefs1, coefs2, coefs3)){
				pMSolve(coefs1, coefs2, coefs3, coefsr);
			}						
			printf("\n");
			system("pause");
			break;
		//IMPRIMIR POLIN�MIOS
		case 8:
			printf("Imprimir polin�mios.\n\n");									
			if(checkNull(coefs1, coefs2, coefs3))
				pMPrint(coefs1, coefs2, coefs3, coefsr);
			printf("\n");
			system("pause");
			break;
		//DETERMINAR GRAU DE POLIN�MIOS
		case 9:
			printf("Determinar grau de polin�mios.\n\n");						
			if(checkNull(coefs1, coefs2, coefs3)){
				pMDetG(coefs1, coefs2, coefs3, coefsr);
			}							
			printf("\n");
			system("pause");
			break;
		//MULTIPLICAR DOIS POLIN�MIOS
		case 10:
			printf("Multiplicar dois polin�mios.\n\n");						
			if(checkNull(coefs1, coefs2, coefs3)){
				ppMMulti(coefs1, coefs2, coefs3, coefsr);
			}							
			printf("\n");
			system("pause");
			break;
		//OP��O SAIR
		case 0:
			printf("\nDesenvolvido por: Murilo Rocha Pereira & Marcos Atilio\nRA: 181250934 & 161255671\nCurso: Ci�ncia da Computa��o\nSemestre: 2�\n");
			return 0;			
		//OP��O INVALIDA
		default:
			printf("Insira uma op��o v�lida =].");
			printf("\n");
			system("pause");
			break;
		}

  } while ( continua() );

  printf("\nDesenvolvido por: Murilo Rocha Pereira & Marcos Atilio\nRA: 181250934 & 161255671\nCurso: Ci�ncia da Computa��o\nSemestre: 2�\n");
  system("pause");
  return 0;

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
  printf("\n\t=====Trabalho pr�tico de programa��o - 01 || ATP II=====\n\n");
  printf("1. Introduzir polin�mios\n"); //OK
  printf("2. Somar polin�mios\n"); //OK
  printf("3. Subtrair polin�mios\n"); //OK
  printf("4. Multiplicar K por polin�mios\n"); //OK
  printf("5. Integrar polin�mios\n"); //OK
  printf("6. Derivar polin�mios\n"); //OK
  printf("7. Resolver polin�mios\n"); //OK
  printf("8. Imprimir polin�mios\n"); //OK
  printf("9. Determinar grau de polin�mios\n"); //OK
  printf("10. Multiplicar 2 polin�mios\n"); //NOT OK
  printf("0. Sair");


  printf("\n\nEscolha uma op��o dentre as listadas: ");
  scanf("%d", &opcao);

  return(opcao);
}

//Integrar polin�mios
void pMIntegrate(float *p1, float *p2, float *p3, float *p4){
	int opt = 0;
	int i = 19;
	float pr[40] = {0};
	char ch;
	printf("Qual polin�mio deseja integrar?\n");
	printf("1. Polin�mio 1 f(x)\n");
	printf("2. Polin�mio 2 g(x)\n");
	printf("3. Polin�mio 3 h(x)\n");
	printf("4. Polin�mio resultante r(x)\n");
	printf("0. Voltar\n");
	printf("Op��o: ");
	scanf("%d", &opt);
	printf("\n");
	
	switch(opt){
		case 1:
			for(; i >=0; i--){
				pr[i+1] = p1[i]/(double)(i+1);								
			}
			pr[0] = 0.0;
			printf("O polin�mio f(x) integrado fica: ");
			i = 19;
			for(; i >= 0; i--){				
				if(pr[i] != 0)	
					if(pr[i] > 0)					
						printf("%.2fX^%d + ", pr[i], i);
					else
						printf("(%.2fX^%d) + ", pr[i], i);
			}
			printf(" C");
			break;
		case 2:
			for(; i >=0; i--){
				pr[i+1] = p2[i]/(double)(i+1.0);				
			}
			pr[0] = 0.0;
			printf("O polin�mio g(x) integrado fica: ");
			i = 19;
			for(; i >= 0; i--){				
				if(pr[i] != 0)	
					if(pr[i] > 0)					
						printf("%.2fX^%d + ", pr[i], i);
					else
						printf("(%.2fX^%d) + ", pr[i], i);
			}
			printf(" + C");
			break;
		case 3:
			for(; i >=0; i--){
				pr[i+1] = p3[i]/(double)(i+1.0);				
			}
			pr[0] = 0.0;
			printf("O polin�mio h(x) integrado fica: ");
			i = 19;
			for(; i >= 0; i--){				
				if(pr[i] != 0)	
					if(pr[i] > 0)					
						printf("%.2fX^%d + ", pr[i], i);
					else
						printf("(%.2fX^%d) + ", pr[i], i);
			}
			printf(" + C");
			break;
		case 4:
			if(p4[39] != 0)
				printf("\nN�o � poss�vel integrar este polin�mio pois ele extrapola o limite pr� estabelecido!");
			else{
				i = 39;
				for(; i >=0; i--){
					pr[i+1] = p4[i]/(i+1.0);				
				}
				pr[0] = 0.0;
				printf("O polin�mio r(x) integrado fica: ");
				i = 39;
				for(; i >= 0; i--){				
					if(pr[i] != 0)	
						if(pr[i] > 0)					
							printf("%.2fX^%d + ", pr[i], i);
						else
							printf("(%.2fX^%d) + ", pr[i], i);
				}
				printf(" + C");				
			}			
			break;
		case 0:
			return 0;
	}
	printf("\n");
	system("pause");
	do{					
		system("cls");
		printf("\n\nDeseja integrar mais algum polin�mio? [S,N] : ");
		ch = getchar();
		ch = toupper(ch);
	}
	while( (ch != 'S') && (ch != 'N') );	
	
	if(ch == 'S')
		pMIntegrate(p1, p2, p3, p4);
}

//Derivar polin�mios
void pMDerive(float *p1, float *p2, float *p3, float *p4){
	int opt = 0, yn = 0;
	int i = 0;
	float pr[40] = {0}, pr1[20] = {0};
	char ch;
	printf("Qual polin�mio deseja derivar?\n");
	printf("1. Polin�mio 1 f(x)\n");
	printf("2. Polin�mio 2 g(x)\n");
	printf("3. Polin�mio 3 h(x)\n");
	printf("4. Polin�mio resultante r(x)\n");
	printf("0. Voltar\n");
	printf("Op��o: ");
	scanf("%d", &opt);
	printf("\n");
	
	switch(opt){
		case 1:
			for(; i < 19; i++){
				pr1[i] = p1[i + 1] * (i + 1);
			}
			pr1[19] == 0.0;
			printf("O polin�mio f(x) derivado fica: ");
			for(; i >= 0; i--){				
				if(pr1[i] != 0)	
					if(pr1[i] > 0)					
						printf("%.2fX^%d + ", pr1[i], i);
					else
						printf("(%.2fX^%d) + ", pr1[i], i);
			}
			printf("0");
			printf("\nDeseja armazenar o novo polin�mio? (1.Sim / 2.N�o)\n");
			printf("Op��o: ");
			scanf("%d", &yn);
			if(yn == 1)
				pMChange(p1, pr1, 20);
			break;
		case 2:
			for(; i < 19; i++){
				pr1[i] = p2[i + 1] * i + 1;
			}
			pr1[19] == 0.0;
			printf("O polin�mio g(x) derivado fica: ");
			for(; i >= 0; i--){				
				if(pr1[i] != 0)	
					if(pr1[i] > 0)					
						printf("%.2fX^%d + ", pr1[i], i);
					else
						printf("(%.2fX^%d) + ", pr1[i], i);
			}
			printf("0");
			printf("\nDeseja armazenar o novo polin�mio? (1.Sim / 2.N�o)\n");
			printf("Op��o: ");
			scanf("%d", &yn);
			if(yn == 1)
				pMChange(p2, pr1, 20);
			break;
		case 3:
			for(; i < 19; i++){
				pr1[i] = p3[i + 1] * i + 1;
			}
			pr1[19] == 0.0;
			printf("O polin�mio h(x) derivado fica: ");
			for(; i >= 0; i--){				
				if(pr1[i] != 0)	
					if(pr1[i] > 0)					
						printf("%.2fX^%d + ", pr1[i], i);
					else
						printf("(%.2fX^%d) + ", pr1[i], i);
			}
			printf("0");
			printf("\nDeseja armazenar o novo polin�mio? (1.Sim / 2.N�o)\n");
			printf("Op��o: ");
			scanf("%d", &yn);
			if(yn == 1)
				pMChange(p3, pr1, 20);
			break;
		case 4:
			for(; i < 38; i++){
				pr1[i] = p4[i + 1] * i + 1;
			}
			pr1[39] == 0.0;
			printf("O polin�mio r(x) derivado fica: ");
			for(; i >= 0; i--){				
				if(pr1[i] != 0)	
					if(pr1[i] > 0)					
						printf("%.2fX^%d + ", pr1[i], i);
					else
						printf("(%.2fX^%d) + ", pr1[i], i);
			}
			printf("0");
			printf("\nDeseja armazenar o novo polin�mio? (1.Sim / 2.N�o)\n");
			printf("Op��o: ");
			scanf("%d", &yn);
			if(yn == 1)
				pMChange(p4, pr, 40);
			break;
		case 0:
			return 0;
	}
	printf("\n");
	system("pause");
	do{					
		system("cls");
		printf("\n\nDeseja derivar mais algum polin�mio? [S,N] : ");
		ch = getchar();
		ch = toupper(ch);
	}
	while( (ch != 'S') && (ch != 'N') );	
	
	if(ch == 'S')
		pMDerive(p1, p2, p3, p4);
}

//Imprimir polin�mio
void pMPrint(float *p1, float *p2, float *p3, float *p4){
	int opt = 0;
	int i = 0;
	char ch;
	printf("Qual polin�mio deseja imprimir?\n");
	printf("1. Polin�mio 1 f(x)\n");
	printf("2. Polin�mio 2 g(x)\n");
	printf("3. Polin�mio 3 h(x)\n");
	printf("4. Polin�mio resultante r(x)\n");
	printf("0. Voltar\n");
	printf("Op��o: ");
	scanf("%d", &opt);
	printf("\n");
	
	switch (opt){
		case 1:
			i = 19;
			printf("Polin�mio 1 f(x): ");
			for(; i >= 0; i--){				
				if(p1[i] != 0)	
					if(p1[i] > 0)					
						printf("%.2fX^%d + ", p1[i], i);
					else
						printf("(%.2fX^%d) + ", p1[i], i);
			}
			printf("0");
			break;
		case 2:
			i = 19;
			printf("Polin�mio 2 g(x): ");
			for(; i >= 0; i--){				
				if(p2[i] != 0)	
					if(p2[i] > 0)					
						printf("%.2fX^%d + ", p2[i], i);
					else
						printf("(%.2fX^%d) + ", p2[i], i);
			}
			printf("0");
			break;
		case 3:
			i = 19;
			printf("Polin�mio 3 h(x): ");
			for(; i >= 0; i--){				
				if(p3[i] != 0)	
					if(p3[i] > 0)					
						printf("%.2fX^%d + ", p3[i], i);
					else
						printf("(%.2fX^%d) + ", p3[i], i);
			}
			printf("0");
			break;
		case 4:
			i = 39;
			printf("Polin�mio resultante r(x): ");
			for(; i >= 0; i--){				
				if(p4[i] != 0)	
					if(p4[i] > 0)					
						printf("%.2fX^%d + ", p4[i], i);
					else
						printf("(%.2fX^%d) + ", p4[i], i);
			}
			printf("0");
			break;
		case 0:
			return 0;
	}
	
	printf("\n");
	system("pause");
	do{					
		system("cls");
		printf("\n\nDeseja imprimir mais algum polin�mio? [S,N] : ");
		ch = getchar();
		ch = toupper(ch);
	}
	while( (ch != 'S') && (ch != 'N') );	
	
	if(ch == 'S')
		pMPrint(p1, p2, p3, p4);	
}

//Determinar grau do polin�mio
void pMDetG(float *p1, float *p2, float *p3, float *p4){
	int i = 0, grau = 0, opt = 0;
	int r = 0;
	short ok = 0;
	char ch;
	printf("Qual polin�mio deseja saber o grau?\n");
	printf("1. Polin�mio 1 f(x)\n");
	printf("2. Polin�mio 2 g(x)\n");
	printf("3. Polin�mio 3 h(x)\n");
	printf("4. Polin�mio resultante r(x)\n");
	printf("0. Voltar\n");
	printf("Op��o: ");
	scanf("%d", &opt);	
	switch(opt)  {	    
		case 1:
			for(; i < 20; i++)
			if(p1[i] != 0)
				grau = i;			
			break;
		case 2:
			for(; i < 20; i++)
			if(p2[i] != 0)
				grau = i;			
			break;
		case 3:
			for(; i < 20; i++)
			if(p3[i] != 0)
				grau = i;			
			break;
		case 4:			
			while(r < 40){
				if(p4[r] != 0){
					ok =1;
					break;	
				}			
				r++;
			}				
			if(ok)
				for(; i < 40; i++)
					if(p4[i] != 0)
						grau = i;			
			else
				printf("O polin�mio resultante est� nulo!\n");
			break;
		case 0:
			return 0;
			break;
	}			
	printf("O grau do %d� polin�mio �: %d\n", opt, grau);
	
	system("pause");
	do{					
		system("cls");
		printf("\n\nDeseja determinar o grau de mais algum polin�mio? [S,N] : ");
		ch = getchar();
		ch = toupper(ch);
	}
	while( (ch != 'S') && (ch != 'N') );	
	
	if(ch == 'S')
		pMDetG(p1, p2, p3, p4);
}

//Resolver polin�mio para X arbitrario
void pMSolve(float *p1, float *p2, float *p3, float *p4){
	int i = 0, opt = 0;
	int r = 0;
	short ok = 0;
	float resultado = 0, x = 0;	
	char ch;
	printf("Insira X pertencente aos Reais:");
	scanf("%f", &x);
	printf("\n\n");
	printf("Qual polin�mio deseja solucionar?\n");
	printf("1. Polin�mio 1 f(x)\n");
	printf("2. Polin�mio 2 g(x)\n");
	printf("3. Polin�mio 3 h(x)\n");
	printf("4. Polin�mio resultante r(x)\n");
	printf("0. Voltar\n");
	printf("Op��o: ");
	scanf("%d", &opt);
	printf("\n");
	
	switch (opt){
		case 1:
			printf("O resultado do polin�mio ");	
			for(; i < 20; i++){
				resultado += (p1[i] * x);
				if(p1[i] != 0)
				printf("%.2f*(%.2f)^%d + ", p1[i], x, i);
			}
			printf("0");
			printf(" �: %.2f", resultado);
			break;	
		case 2:
			printf("O resultado do polin�mio ");	
			for(; i < 20; i++){
				resultado += (p2[i] * x);
				if(p2[i] != 0)
					printf("%.2f*(%.2f)^%d + ", p2[i], x, i);
			}
			printf("0");
			printf(" �: %.2f", resultado);
			break;
		case 3:
			printf("O resultado do polin�mio ");	
			for(; i < 20; i++){
				resultado += (p3[i] * x);
				if(p3[i] != 0)
					printf("%.2f*(%.2f)^%d + ", p3[i], x, i);
			}	
			printf("0");
			printf(" �: %.2f", resultado);
			break;		
		case 4:			
			while(r < 40){
				if(p4[r] != 0){
					ok =1;
					break;	
				}			
				r++;
			}				
			if(ok){
				printf("O resultado do polin�mio ");	
				for(; i < 40; i++){
					resultado += (p4[i] * x);
					if(p4[i] != 0)
						printf("%.2f*(%.2f)^%d + ", p4[i], x, i);
				}
				printf("0");
				printf(" �: %.2f", resultado);
			}					
			else
				printf("O polin�mio resultante est� nulo!");
			break;	
		case 0:
			return 0;
	}	
	
	printf("\n");
	system("pause");
	do{					
		system("cls");
		printf("\n\nDeseja solucionar mais algum polin�mio? [S,N] : ");
		ch = getchar();
		ch = toupper(ch);
	}
	while( (ch != 'S') && (ch != 'N') );	
	
	if(ch == 'S')
		pMSolve(p1, p2, p3, p4);
}

//Inserir polin�mios
void pMInsert(float *p1, float *p2, float *p3){
	int option = -1, i = 0, grau = 0;
	char ch;
	printf("Qual polin�mio deseja inserir?\n");
	printf("1. Polin�mio 1 (f)\n");
	printf("2. Polin�mio 2 (g)\n");
	printf("3. Polin�mio 3 (h)\n");
	printf("0. Voltar\n");
	printf("Op��o: ");
	scanf("%d", &option);
	
	switch(option)  {
		case 1:
			printf("Qual o grau do polin�mio?\n");
			scanf("%d", &grau);
			if(grau > 0 && grau < 21){
	            for(; i <= grau; i++){
	                printf("\nIntroduza o coeficiente A%d :", i);
	         	    scanf("%f", &p1[i]);
	            }            
	            grau = 0;
	            i = 0;
			}
			else{
				printf("O grau n do polin�mio deve se 0 < n < 21");			
			}            	
			break;
		case 2:
			printf("Qual o grau do polin�mio?\n");
			scanf("%d", &grau);
	
			if(grau > 0 && grau < 21){
	            for(; i <= grau; i++){
	                printf("\nIntroduza o coeficiente A%d :", i);
	                scanf("%f", &p2[i]);                
	            }                
	            grau = 0;
	            i = 0;
			}
			else{
				pMInsert(p1, p2, p3);
				printf("O grau n do polin�mio deve se 0 < n < 21");
			}            	
			break;
		case 3:
			printf("Qual o grau do polin�mio?\n");
			scanf("%d", &grau);
	
			if(grau > 0 && grau < 21){
	            for(; i <= grau; i++){
	                printf("\nIntroduza o coeficiente A%d :", i);
	                scanf("%f", &p3[i]);                
	            }                
	            grau = 0;
	            i = 0;
			}
			else{
				pMInsert(p1, p2, p3);
				printf("O grau n do polin�mio deve se 0 < n < 21");
			}            
			break;
		case 0:		
			return 0;
	}
	printf("\n");
	system("pause");
	do{					
		system("cls");
		printf("\n\nPolin�mio introduzido com sucesso! Deseja introduzir mais algum polin�mio? [S,N] : ");
		ch = getchar();
		ch = toupper(ch);
	}
	while( (ch != 'S') && (ch != 'N') );	
	
	if(ch == 'S')
		pMInsert(p1, p2, p3);
}

//Somar polin�mios
void pMSoma(float *p1, float *p2, float *p3, float *p4){
    static float pr[40]= {0};
    char ch;
    int quant = 0, pc1=0, i = 39, j = 0;
	
	printf("Qual polin�mio voc� deseja somar?\n");
    printf("1. Polin�mio 1 f(x)\n");
	printf("2. Polin�mio 2 g(x)\n");
    printf("3. Polin�mio 3 h(x)\n");
    printf("4. Polin�mio resultante r(x)\n");
    printf("0. Voltar\n");
    printf("Op��o: ");
    scanf("%d", &pc1);                
				
	switch(pc1){
		case 1:
			for(; j < 20; j++){
				pr[j] += p1[j];					
			}
			j = 0;
			break;				
		case 2:
			for(; j < 20; j++){
				pr[j] += p2[j];
			}
			j = 0;	
			break;				
		case 3:
			for(; j < 20; j++){
				pr[j] += p3[j];
			}
			j = 0;	
			break;					
		case 4:
			for(; j < 40; j++){
				pr[j] += p4[j];
			}
			j = 0;	
			break;
		case 0:
			return 0;
	}
	
	pMChange(p4, pr, 40);
	
	printf("\n");
	system("pause");
	do{					
		system("cls");
		printf("\n\nDeseja somar mais algum polin�mio? [S,N] : ");
		ch = getchar();
		ch = toupper(ch);
	}
	while( (ch != 'S') && (ch != 'N') );	
		
	if(ch == 'S')
		pMSoma(p1, p2, p3, p4);
	else{
		printf("\n");
		printf("Polin�mio resultante: ");
		for(; i >= 0; i--){
			if(pr[i] !=0)
				if(pr[i] > 0)
					printf("%.2fX^%d + ", pr[i], i);
				else
					printf("(%.2fX^%d) + ", pr[i], i);
		}
		printf("0");	
		//Limpar polin�mio resultante
		for(i=39; i > -1; i--){
			pr[i] = 0;
		}
	}				

}

//Multiplicar dois polin�mios
void ppMMulti(float *p1, float *p2, float *p3, float *p4){
    float pr[40]= {0};
    static float pa[40] = {0};
    char ch;
    int quant = 0, pc1=0, i = 39, j = 0, k = 19;
    int first = 1;
	
	printf("Qual polin�mio voc� deseja multiplicar?\n");
    printf("1. Polin�mio 1 f(x)\n");
	printf("2. Polin�mio 2 g(x)\n");
    printf("3. Polin�mio 3 h(x)\n");
    printf("4. Polin�mio resultante r(x)\n");
    printf("0. Voltar\n");
    printf("Op��o: ");
    scanf("%d", &pc1);                
	
	while(first){
		for(i = 19; i > -1; i--){
			if(pa[i] != 0){
				first = 0;
				break;	
			}		
		}	
		if(pa[0] == 0)
			break;		
	}	
	if(first){
		switch(pc1)  {			
			case 1:
				for(; j < 20; j++){
					pa[j] = pa[j]  + p1[j];					
				}
				j = 0;						
				break;
			case 2:
				for(; j < 20; j++){
					pa[j] = pa[j] + p2[j];
				}
				j = 0;
				break;							
			case 3:
				for(; j < 20; j++){
					pa[j] = pa[j]  + p3[j];
				}
				j = 0;
				break;				
			case 4:
				for(; j < 40; j++){
					pa[j] += p4[j];
				}
				j = 0;	
				break;
			case 0:
				return 0;
		}
		pMChange(p4, pr, 40);
		first--;		
		ppMMulti(p1, p2, p3, p4);
	}			
	else{
		switch(pc1){
			case 1:
				if(pMExc(pa, p1, 40, 20))
				{
					for(k = 19; k > -1; k--){
						for(j = 19; j > -1; j--){
							pr[k + j] =  pr[k + j] + (p1[j] * pa[k]);					
						}	
					}							
				}
				else{
					printf("O polin�mio excede o limite (40)\n");
					return 0;
				}					
				break;				
			case 2:
				if(pMExc(pa, p2, 40, 20))
				{
					for(k = 19; k > -1; k--){
						for(j = 19; j > -1; j--){
							pr[k + j] =  pr[k + j] + (p2[j] * pa[k]);					
						}	
					}							
				}
				else{
					printf("O polin�mio excede o limite (40)\n");
					return 0;
				}				
				break;				
			case 3:
				if(pMExc(pa, p3, 40, 20))
				{
					for(k = 19; k > -1; k--){
						for(j = 19; j > -1; j--){
							pr[k + j] =  pr[k + j] + (p3[j] * pa[k]);					
						}	
					}							
				}
				else{
					printf("O polin�mio excede o limite (40)\n");
					return 0;
				}				
				break;					
			case 4:
				if(pMExc(pa, p4, 40, 20))
				{
					for(k = 19; k > -1; k--){
						for(j = 19; j > -1; j--){
							pr[k + j] =  pr[k + j] + (p4[j] * pa[k]);					
						}	
					}							
				}
				else{
					printf("O polin�mio excede o limite (40)\n");
					return 0;
				}				
				break;
			case 0:
				return 0;
		}
		
		pMChange(p4, pr, 40);
		
		printf("\n");
		system("pause");
		do{					
			system("cls");
			printf("\n\nDeseja multiplicar mais algum polin�mio? [S,N] : ");
			ch = getchar();
			ch = toupper(ch);
		}
		while( (ch != 'S') && (ch != 'N') );	
			
		if(ch == 'S')
			ppMMulti(p1, p2, p3, p4);
		else{
			printf("\n");
			printf("Polin�mio resultante: ");
			for(i = 39; i > -1; i--){				
				if(pr[i] !=0)
					if(pr[i] > 0)
						printf("%.2fX^%d + ", pr[i], i);
					else
						if(pr[i] != 0)
							printf("(%.2fX^%d) + ", pr[i], i);
			}
			printf("0");
			
			//Limpar polin�mio auxiliar	
			for(i=39; i > -1; i--){
				pa[i] = 0;
			}
		}			
	}		

}

//Multiplica��o de polin�mios por K
void pMMulti(float *p1, float *p2, float *p3, float *p4, float conK){
	static float pr[40] = {0};
	char ch;
	int j = 0, i = 39, pc1 = 0;
	
	printf("Qual polin�mio voc� deseja multiplicar por %.2f?\n", conK);
    printf("1. Polin�mio 1\n");
	printf("2. Polin�mio 2\n");
    printf("3. Polin�mio 3\n");
    printf("4. Polin�mio resultante\n");
    printf("0. Voltar\n");
    printf("Op��o: ");
    scanf("%d", &pc1);   
	
	switch(pc1)  {
		case 1:
			for(; j < 20; j++){
				pr[j] = p1[j] * conK;					
			}
			j = 0;
			break;					
		case 2:
			for(; j < 20; j++){
				pr[j] = p2[j] * conK;
			}
			j = 0;	
			break;			
		case 3:
			for(; j < 20; j++){
				pr[j] = p3[j] * conK;
			}
			j = 0;	
			break;		
		case 4:
			for(; j < 40; j++){
				pr[j] = p4[j] * conK;
			}
			j = 0;	
			break;
		case 0:
			return 0;			
	}
	pMChange(p4, pr, 40);
	
	printf("\n");
	printf("Polin�mio resultante: ");
	for(; i >= 0; i--){
		if(pr[i] != 0 && i == 39)
			printf("%.2fX^%d", pr[i], i);
		else if(pr[i] != 0)	
			if(pr[i] > 0)					
				printf("%.2fX^%d + ", pr[i], i);
			else
				printf("(%.2fX^%d) + ", pr[i], i);
	}
	printf("0");
	//Limpar polin�mio resultante
	for(i=39; i > -1; i--){
		pr[i] = 0;
	}
	printf("\n");
	system("pause");
	do{					
		system("cls");
		printf("\n\nDeseja multiplicar mais algum polin�mio por %.2f? [S,N] : ", conK);
		ch = getchar();
		ch = toupper(ch);
	}
	while( (ch != 'S') && (ch != 'N') );	
	
	if(ch == 'S')
		pMMulti(p1, p2, p3, p4, conK);	
}

//Subtrair polin�mios
void pMSub(float *p1, float *p2, float *p3, float *p4){
    static float pr[40]= {0};
    static short first = 1;
    char ch;
    int quant = 0, pc1=0, i = 39, j = 0, k = 0;
	
	printf("Qual polin�mio voc� deseja subtrair?\n");
    printf("1. Polin�mio 1\n");
	printf("2. Polin�mio 2\n");
    printf("3. Polin�mio 3\n");
    printf("4. Polin�mio resultante\n");
    printf("0. Voltar\n");
    printf("Op��o: ");
    scanf("%d", &pc1);                
	
	while(first){
		for(i = 39; i < 40 && i > -1; i--){
			if(pr[i] != 0){
				printf("%d\n", pr[i]);
				first = 0;
				break;	
			}		
		}	
		if(pr[0] == 0)
			break;		
	}	
	if(first){
		switch(pc1)  {			
			case 1:
				for(; j < 20; j++){
					pr[j] += p1[j];					
				}
				j = 0;						
				break;
			case 2:
				for(; j < 20; j++){
					pr[j] += p2[j];
				}
				j = 0;
				break;							
			case 3:
				for(; j < 20; j++){
					pr[j] += p3[j];
				}
				j = 0;
				break;				
			case 4:
				for(; j < 40; j++){
					pr[j] += p4[j];
				}
				j = 0;	
				break;
			case 0:
				return 0;
		}
		pMChange(p4, pr, 40);
		first--;		
		pMSub(p1, p2, p3, p4);
	}			
	else{		
		switch(pc1)  {
			case 1:
				for(; j < 20; j++){
					pr[j] -= p1[j];					
				}
				j = 0;
				break;				
			case 2:
				for(; j < 20; j++){
					pr[j] -= p2[j];
				}
				j = 0;
				break;				
			case 3:
				for(; j < 20; j++){
					pr[j] -= p3[j];
				}
				j = 0;	
				break;				
			case 4:
				for(; j < 40; j++){
					pr[j] -= p4[j];
				}
				j = 0;	
				break;
			case 0:
				return 0;
		}
		pMChange(p4, pr, 40);		
		
		printf("\n");
		system("pause");
		do{						
			system("cls");
			printf("\n\nDeseja subtrair mais algum polin�mio? [S,N] : ");
			ch = getchar();
			ch = toupper(ch);
		}
		while( (ch != 'S') && (ch != 'N') );	
		
		if(ch == 'S')
			pMSub(p1, p2, p3, p4);
		else{
			printf("\n");
			printf("Polin�mio resultante: ");
			for(; i >= 0; i--){								
					if(pr[i] > 0)											
						printf("%.2fX^%d + ", pr[i], i);
					else
						if(pr[i] != 0)
							printf("(%.2fX^%d) + ", pr[i], i);
			}
			printf("0");	
			//Limpar polin�mio resultante
			for(i=39; i > -1; i--){
				pr[i] = 0;
			}
		}	
	}					
}

//Transf�rir polin�mios
void pMChange(float *p, float *pr, int lenght){
	int i = 0;
	for(; i < lenght; i++){
		p[i] == pr[i];
	}
}

//Checar se polin�mio excede limite
short pMExc(float *p, float *p2, int l1, int l2){
	int i = 0;
	int g1 = 0, g2 = 0;
	
	for(i=0; i < l1; i++)
		if(p[i] != 0)
			g1 = i;
	for(i=0; i < l2; i++)
		if(p2[i] != 0)
			g2 = i;
	
	if((g1 + g2) > 40)
		return 0;
	else
		return 1;	
}

//Checar se polin�mio est� nulo
short checkNull(float *p1, float *p2, float *p3){
	int i = 0;
	short ok = 0;
	while(i < 20){
		if(p1[i] != 0){
			ok =1;
			break;	
		}			
		i++;
	}
	
	if(!ok){
		printf("\nPolin�mio 1 est� nulo!");
		return 0;	
	}		
	
	ok = 0;
	i=0;
	
	while(i < 20){
		if(p2[i] != 0){
			ok = 1;
			break;	
		}			
		i++;
	}
	
	if(!ok){
		printf("\nPolin�mio 2 est� nulo!");
		return 0;
	}					
	
	ok  = 0;
	i=0;
	
	while(i < 20){
		if(p3[i] != 0){
			ok = 1;
			break;	
		}			
		i++;
	}				
	
	if(!ok){
		printf("\nPolin�mio 3 est� nulo!");
		return 0;
	}		
	
	return 1;
}
